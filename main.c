#include <errno.h>
#include <mach/mach.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/sysctl.h>
#include <sys/syscall.h>
#include <unistd.h>
#include "symbolicate.h"

#include "xnuspy_ctl.h"

#include "states.h"

// Process name to trace
#define TARGET_PROCESS_NAME "pushTanApp"

// (iPhone SE 14.3)
/*
#define MACH_SYSCALL_OFFSET 0xFFFFFFF007240D28
#define UNIX_SYSCALL_OFFSET 0xFFFFFFF007629850*/

// (iPhone SE 14.8)
#define MACH_SYSCALL_OFFSET 0xFFFFFFF007262B7C
#define UNIX_SYSCALL_OFFSET 0xFFFFFFF00764F950

// also existant: platform_syscall
// handle_mach_absolute_time_trap
// handle_mach_continuous_time_trap
// seem to not be that relevant so not hooked at least for now

static void (*_bzero)(void *p, size_t n);
static int (*copyinstr)(const void *uaddr, void *kaddr, size_t len, size_t *done);
static void *(*current_proc)(void);
static void (*kprintf)(const char *, ...);
static void (*proc_name)(int pid, char *buf, int size);
static pid_t (*proc_pid)(void *);
static int (*_strcmp)(const char *s1, const char *s2);
static void *(*unified_kalloc)(size_t sz);
static void (*unified_kfree)(void *ptr);

static int (*copyin)(const user_addr_t uaddr, void *kaddr, size_t len);
static int (*copyout)(const void *kaddr, user_addr_t udaddr, size_t len);

static uint64_t kernel_slide;

static uint8_t curcpu(void){
    uint64_t mpidr_el1;
    asm volatile("mrs %0, mpidr_el1" : "=r" (mpidr_el1));
    return (uint8_t)(mpidr_el1 & 0xff);
}

static pid_t caller_pid(void){
    return proc_pid(current_proc());
}

static void (*mach_syscall_orig)(arm_saved_state_t* state);
static void mach_syscall(arm_saved_state_t* state)
{
    char *caller_name = unified_kalloc(MAXCOMLEN + 1);
    if(caller_name)
    {
        pid_t pid = caller_pid();
        _bzero(caller_name, MAXCOMLEN + 1);
        proc_name(pid, caller_name, MAXCOMLEN + 1);

        if(!_strcmp(caller_name, TARGET_PROCESS_NAME))
        {
            uint8_t cpu = curcpu();
            int trap_no = state->ss_64.x[16];
            int svc_num = -trap_no;

            // Note: Args need to be logged manually when needed

            const char* syscall_name = get_name_for_mach_syscall(svc_num);
            if(syscall_name)
            {
                kprintf("%s (%d) MACH SYSCALL %s (%d) (pc:%p, lr:%p, cpu:%d)\n", caller_name, pid, syscall_name, svc_num, state->ss_64.pc, state->ss_64.lr, cpu);
            }
            else
            {
                kprintf("%s (%d) MACH SYSCALL %d (pc:%p, lr:%p, cpu:%d)\n", caller_name, pid, svc_num, state->ss_64.pc, state->ss_64.lr, cpu);
            }
        }

        unified_kfree(caller_name);
    }

    mach_syscall_orig(state);
}

static void (*unix_syscall_orig)(arm_saved_state_t*, thread_t, /*struct uthread* */ void*, /*struct proc* */ void*);
static void unix_syscall(arm_saved_state_t* state, thread_t thread_act, void* uthread, void* proc)
{
    char *caller_name = unified_kalloc(MAXCOMLEN + 1);
    if(caller_name)
    {
        pid_t pid = caller_pid();
        _bzero(caller_name, MAXCOMLEN + 1);
        proc_name(pid, caller_name, MAXCOMLEN + 1);

        if(!_strcmp(caller_name, TARGET_PROCESS_NAME))
        {
            uint8_t cpu = curcpu();
            int trap_no = state->ss_64.x[16];
            int svc_num = trap_no;

            // Note: Args need to be logged manually when needed

            // Print paths (first arg) of open and access syscalls
            if(svc_num == 5 || svc_num == 33)
            {
                size_t size = 256;
                char* pathname = unified_kalloc(size);
                if(pathname)
                {
                    uint64_t usr_addr = state->ss_64.x[0];
                    size_t outsize = 0;

                    copyinstr((void*)usr_addr, pathname, size, &outsize);

                    if(svc_num == 5)
                    {
                        kprintf("%s (%d) UNIX SYSCALL open %s\n", caller_name, pid, pathname);
                    }
                    else
                    {
                        kprintf("%s (%d) UNIX SYSCALL access %s\n", caller_name, pid, pathname);
                    }

                    unified_kfree(pathname);
                }
            }

            const char* syscall_name = get_name_for_unix_syscall(svc_num);

            if(syscall_name)
            {
                kprintf("%s (%d) UNIX SYSCALL %s (%d) (pc:%p, lr:%p, cpu:%d)\n", caller_name, pid, syscall_name, svc_num, state->ss_64.pc, state->ss_64.lr, cpu);
            }
            else
            {
                kprintf("%s (%d) UNIX SYSCALL %d (pc:%p, lr:%p, cpu:%d)\n", caller_name, pid, svc_num, state->ss_64.pc, state->ss_64.lr, cpu);
            }
        }

        unified_kfree(caller_name);
    }

    unix_syscall_orig(state, thread_act, uthread, proc);
}

static long SYS_xnuspy_ctl = 0;

static int gather_kernel_offsets(void){
    int ret;
#define GET(a, b) \
    do { \
        ret = syscall(SYS_xnuspy_ctl, XNUSPY_CACHE_READ, a, b, 0); \
        if(ret){ \
            printf("%s: failed getting %s\n", __func__, #a); \
            return ret; \
        } \
    } while (0)

    GET(BZERO, &_bzero);
    GET(COPYINSTR, &copyinstr);
    GET(CURRENT_PROC, &current_proc);
    GET(KPRINTF, &kprintf);
    GET(PROC_NAME, &proc_name);
    GET(PROC_PID, &proc_pid);
    GET(STRCMP, &_strcmp);
    GET(UNIFIED_KALLOC, &unified_kalloc);
    GET(UNIFIED_KFREE, &unified_kfree);
    GET(COPYIN, &copyin);
    GET(COPYOUT, &copyout);

    return 0;
}

int main(int argc, char *argv[], char *envp[]) {
	size_t oldlen = sizeof(long);
    int ret = sysctlbyname("kern.xnuspy_ctl_callnum", &SYS_xnuspy_ctl,
            &oldlen, NULL, 0);

    if(ret == -1){
        printf("sysctlbyname with kern.xnuspy_ctl_callnum failed: %s\n",
                strerror(errno));
        return 1;
    }

    ret = syscall(SYS_xnuspy_ctl, XNUSPY_CHECK_IF_PATCHED, 0, 0, 0);

    if(ret != 999){
        printf("xnuspy_ctl isn't present?\n");
        return 1;
    }

	ret = gather_kernel_offsets();

    if(ret)
	{
        printf("something failed: %s\n", strerror(errno));
        return 1;
    }

    ret = syscall(SYS_xnuspy_ctl, XNUSPY_INSTALL_HOOK, MACH_SYSCALL_OFFSET, mach_syscall, &mach_syscall_orig);
	if(ret)
	{
        return 1;
    }

    ret = syscall(SYS_xnuspy_ctl, XNUSPY_INSTALL_HOOK, UNIX_SYSCALL_OFFSET, unix_syscall, &unix_syscall_orig);
	if(ret)
	{
        return 1;
    }

	for(;;)
	{
        sleep(1);
    }

	return 0;
}