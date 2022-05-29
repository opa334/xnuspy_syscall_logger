#define UNIX_TRAP_TABLE_COUNT 546
#define syscallnames { \
	"syscall",             /* 0 = syscall indirect syscall */ \
	"exit",                /* 1 = exit */ \
	"fork",                /* 2 = fork */ \
	"read",                /* 3 = read */ \
	"write",               /* 4 = write */ \
	"open",                /* 5 = open */ \
	"close",               /* 6 = close */ \
	"wait4",               /* 7 = wait4 */ \
	"#8",                  /* 8 = old creat */ \
	"link",                /* 9 = link */ \
	"unlink",              /* 10 = unlink */ \
	"#11",                 /* 11 = old execv */ \
	"chdir",               /* 12 = chdir */ \
	"fchdir",              /* 13 = fchdir */ \
	"mknod",               /* 14 = mknod */ \
	"chmod",               /* 15 = chmod */ \
	"chown",               /* 16 = chown */ \
	"#17",                 /* 17 = old break */ \
	"getfsstat",           /* 18 = getfsstat */ \
	"#19",                 /* 19 = old lseek */ \
	"getpid",              /* 20 = getpid */ \
	"#21",                 /* 21 = old mount */ \
	"#22",                 /* 22 = old umount */ \
	"setuid",              /* 23 = setuid */ \
	"getuid",              /* 24 = getuid */ \
	"geteuid",             /* 25 = geteuid */ \
	"ptrace",              /* 26 = ptrace */ \
	"recvmsg",             /* 27 = recvmsg */ \
	"sendmsg",             /* 28 = sendmsg */ \
	"recvfrom",            /* 29 = recvfrom */ \
	"accept",              /* 30 = accept */ \
	"getpeername",         /* 31 = getpeername */ \
	"getsockname",         /* 32 = getsockname */ \
	"access",              /* 33 = access */ \
	"chflags",             /* 34 = chflags */ \
	"fchflags",            /* 35 = fchflags */ \
	"sync",                /* 36 = sync */ \
	"kill",                /* 37 = kill */ \
	"#38",                 /* 38 = old stat */ \
	"getppid",             /* 39 = getppid */ \
	"#40",                 /* 40 = old lstat */ \
	"dup",                 /* 41 = dup */ \
	"pipe",                /* 42 = pipe */ \
	"getegid",             /* 43 = getegid */ \
	"#44",                 /* 44 = old profil */ \
	"#45",                 /* 45 = old ktrace */ \
	"sigaction",           /* 46 = sigaction */ \
	"getgid",              /* 47 = getgid */ \
	"sigprocmask",         /* 48 = sigprocmask */ \
	"getlogin",            /* 49 = getlogin */ \
	"setlogin",            /* 50 = setlogin */ \
	"acct",                /* 51 = acct */ \
	"sigpending",          /* 52 = sigpending */ \
	"sigaltstack",         /* 53 = sigaltstack */ \
	"ioctl",               /* 54 = ioctl */ \
	"reboot",              /* 55 = reboot */ \
	"revoke",              /* 56 = revoke */ \
	"symlink",             /* 57 = symlink */ \
	"readlink",            /* 58 = readlink */ \
	"execve",              /* 59 = execve */ \
	"umask",               /* 60 = umask */ \
	"chroot",              /* 61 = chroot */ \
	"#62",                 /* 62 = old fstat */ \
	"#63",                 /* 63 = used internally and reserved */ \
	"#64",                 /* 64 = old getpagesize */ \
	"msync",               /* 65 = msync */ \
	"vfork",               /* 66 = vfork */ \
	"#67",                 /* 67 = old vread */ \
	"#68",                 /* 68 = old vwrite */ \
	"#69",                 /* 69 = old sbrk */ \
	"#70",                 /* 70 = old sstk */ \
	"#71",                 /* 71 = old mmap */ \
	"#72",                 /* 72 = old vadvise */ \
	"munmap",              /* 73 = munmap */ \
	"mprotect",            /* 74 = mprotect */ \
	"madvise",             /* 75 = madvise */ \
	"#76",                 /* 76 = old vhangup */ \
	"#77",                 /* 77 = old vlimit */ \
	"mincore",             /* 78 = mincore */ \
	"getgroups",           /* 79 = getgroups */ \
	"setgroups",           /* 80 = setgroups */ \
	"getpgrp",             /* 81 = getpgrp */ \
	"setpgid",             /* 82 = setpgid */ \
	"setitimer",           /* 83 = setitimer */ \
	"#84",                 /* 84 = old wait */ \
	"swapon",              /* 85 = swapon */ \
	"getitimer",           /* 86 = getitimer */ \
	"#87",                 /* 87 = old gethostname */ \
	"#88",                 /* 88 = old sethostname */ \
	"getdtablesize",       /* 89 = getdtablesize */ \
	"dup2",                /* 90 = dup2 */ \
	"#91",                 /* 91 = old getdopt */ \
	"fcntl",               /* 92 = fcntl */ \
	"select",              /* 93 = select */ \
	"#94",                 /* 94 = old setdopt */ \
	"fsync",               /* 95 = fsync */ \
	"setpriority",         /* 96 = setpriority */ \
	"socket",              /* 97 = socket */ \
	"connect",             /* 98 = connect */ \
	"#99",                 /* 99 = old accept */ \
	"getpriority",         /* 100 = getpriority */ \
	"#101",                /* 101 = old send */ \
	"#102",                /* 102 = old recv */ \
	"#103",                /* 103 = old sigreturn */ \
	"bind",                /* 104 = bind */ \
	"setsockopt",          /* 105 = setsockopt */ \
	"listen",              /* 106 = listen */ \
	"#107",                /* 107 = old vtimes */ \
	"#108",                /* 108 = old sigvec */ \
	"#109",                /* 109 = old sigblock */ \
	"#110",                /* 110 = old sigsetmask */ \
	"sigsuspend",          /* 111 = sigsuspend */ \
	"#112",                /* 112 = old sigstack */ \
	"#113",                /* 113 = old recvmsg */ \
	"#114",                /* 114 = old sendmsg */ \
	"#115",                /* 115 = old vtrace */ \
	"gettimeofday",        /* 116 = gettimeofday */ \
	"getrusage",           /* 117 = getrusage */ \
	"getsockopt",          /* 118 = getsockopt */ \
	"#119",                /* 119 = old resuba */ \
	"readv",               /* 120 = readv */ \
	"writev",              /* 121 = writev */ \
	"settimeofday",        /* 122 = settimeofday */ \
	"fchown",              /* 123 = fchown */ \
	"fchmod",              /* 124 = fchmod */ \
	"#125",                /* 125 = old recvfrom */ \
	"setreuid",            /* 126 = setreuid */ \
	"setregid",            /* 127 = setregid */ \
	"rename",              /* 128 = rename */ \
	"#129",                /* 129 = old truncate */ \
	"#130",                /* 130 = old ftruncate */ \
	"flock",               /* 131 = flock */ \
	"mkfifo",              /* 132 = mkfifo */ \
	"sendto",              /* 133 = sendto */ \
	"shutdown",            /* 134 = shutdown */ \
	"socketpair",          /* 135 = socketpair */ \
	"mkdir",               /* 136 = mkdir */ \
	"rmdir",               /* 137 = rmdir */ \
	"utimes",              /* 138 = utimes */ \
	"futimes",             /* 139 = futimes */ \
	"adjtime",             /* 140 = adjtime */ \
	"#141",                /* 141 = old getpeername */ \
	"gethostuuid",         /* 142 = gethostuuid */ \
	"#143",                /* 143 = old sethostid */ \
	"#144",                /* 144 = old getrlimit */ \
	"#145",                /* 145 = old setrlimit */ \
	"#146",                /* 146 = old killpg */ \
	"setsid",              /* 147 = setsid */ \
	"#148",                /* 148 = old setquota */ \
	"#149",                /* 149 = old qquota */ \
	"#150",                /* 150 = old getsockname */ \
	"getpgid",             /* 151 = getpgid */ \
	"setprivexec",         /* 152 = setprivexec */ \
	"pread",               /* 153 = pread */ \
	"pwrite",              /* 154 = pwrite */ \
	"nfssvc",              /* 155 = nfssvc */ \
	"#156",                /* 156 = old getdirentries */ \
	"statfs",              /* 157 = statfs */ \
	"fstatfs",             /* 158 = fstatfs */ \
	"unmount",             /* 159 = unmount */ \
	"#160",                /* 160 = old async_daemon */ \
	"getfh",               /* 161 = getfh */ \
	"#162",                /* 162 = old getdomainname */ \
	"#163",                /* 163 = old setdomainname */ \
	"#164",                /* 164 = */ \
	"quotactl",            /* 165 = quotactl */ \
	"#166",                /* 166 = old exportfs */ \
	"mount",               /* 167 = mount */ \
	"#168",                /* 168 = old ustat */ \
	"csops",               /* 169 = csops */ \
	"csops_audittoken",    /* 170 = csops_audittoken */ \
	"#171",                /* 171 = old wait3 */ \
	"#172",                /* 172 = old rpause */ \
	"waitid",              /* 173 = waitid */ \
	"#174",                /* 174 = old getdents */ \
	"#175",                /* 175 = old gc_control */ \
	"#176",                /* 176 = old add_profil */ \
	"kdebug_typefilter",   /* 177 = kdebug_typefilter */ \
	"kdebug_trace_string",   /* 178 = kdebug_trace_string */ \
	"kdebug_trace64",      /* 179 = kdebug_trace64 */ \
	"kdebug_trace",        /* 180 = kdebug_trace */ \
	"setgid",              /* 181 = setgid */ \
	"setegid",             /* 182 = setegid */ \
	"seteuid",             /* 183 = seteuid */ \
	"sigreturn",           /* 184 = sigreturn */ \
	"#185",                /* 185 = old chud */ \
	"thread_selfcounts",   /* 186 = thread_selfcounts */ \
	"fdatasync",           /* 187 = fdatasync */ \
	"stat",                /* 188 = stat */ \
	"fstat",               /* 189 = fstat */ \
	"lstat",               /* 190 = lstat */ \
	"pathconf",            /* 191 = pathconf */ \
	"fpathconf",           /* 192 = fpathconf */ \
	"#193",                /* 193 = old getfsstat */ \
	"getrlimit",           /* 194 = getrlimit */ \
	"setrlimit",           /* 195 = setrlimit */ \
	"getdirentries",       /* 196 = getdirentries */ \
	"mmap",                /* 197 = mmap */ \
	"#198",                /* 198 = old __syscall */ \
	"lseek",               /* 199 = lseek */ \
	"truncate",            /* 200 = truncate */ \
	"ftruncate",           /* 201 = ftruncate */ \
	"sysctl",              /* 202 = sysctl */ \
	"mlock",               /* 203 = mlock */ \
	"munlock",             /* 204 = munlock */ \
	"undelete",            /* 205 = undelete */ \
	"#206",                /* 206 = old ATsocket */ \
	"#207",                /* 207 = old ATgetmsg */ \
	"#208",                /* 208 = old ATputmsg */ \
	"#209",                /* 209 = old ATsndreq */ \
	"#210",                /* 210 = old ATsndrsp */ \
	"#211",                /* 211 = old ATgetreq */ \
	"#212",                /* 212 = old ATgetrsp */ \
	"#213",                /* 213 = Reserved for AppleTalk */ \
	"#214",                /* 214 = */ \
	"#215",                /* 215 = */ \
	"open_dprotected_np",   /* 216 = open_dprotected_np */ \
	"fsgetpath_ext",       /* 217 = fsgetpath_ext */ \
	"#218",                /* 218 = old lstatv */ \
	"#219",                /* 219 = old fstatv */ \
	"getattrlist",         /* 220 = getattrlist */ \
	"setattrlist",         /* 221 = setattrlist */ \
	"getdirentriesattr",   /* 222 = getdirentriesattr */ \
	"exchangedata",        /* 223 = exchangedata */ \
	"#224",                /* 224 = old checkuseraccess or fsgetpath */ \
	"searchfs",            /* 225 = searchfs */ \
	"delete",              /* 226 = delete private delete ( Carbon semantics ) */ \
	"copyfile",            /* 227 = copyfile */ \
	"fgetattrlist",        /* 228 = fgetattrlist */ \
	"fsetattrlist",        /* 229 = fsetattrlist */ \
	"poll",                /* 230 = poll */ \
	"#231",                /* 231 = old watchevent */ \
	"#232",                /* 232 = old waitevent */ \
	"#233",                /* 233 = old modwatch */ \
	"getxattr",            /* 234 = getxattr */ \
	"fgetxattr",           /* 235 = fgetxattr */ \
	"setxattr",            /* 236 = setxattr */ \
	"fsetxattr",           /* 237 = fsetxattr */ \
	"removexattr",         /* 238 = removexattr */ \
	"fremovexattr",        /* 239 = fremovexattr */ \
	"listxattr",           /* 240 = listxattr */ \
	"flistxattr",          /* 241 = flistxattr */ \
	"fsctl",               /* 242 = fsctl */ \
	"initgroups",          /* 243 = initgroups */ \
	"posix_spawn",         /* 244 = posix_spawn */ \
	"ffsctl",              /* 245 = ffsctl */ \
	"#246",                /* 246 = */ \
	"nfsclnt",             /* 247 = nfsclnt */ \
	"fhopen",              /* 248 = fhopen */ \
	"#249",                /* 249 = */ \
	"minherit",            /* 250 = minherit */ \
	"semsys",              /* 251 = semsys */ \
	"msgsys",              /* 252 = msgsys */ \
	"shmsys",              /* 253 = shmsys */ \
	"semctl",              /* 254 = semctl */ \
	"semget",              /* 255 = semget */ \
	"semop",               /* 256 = semop */ \
	"#257",                /* 257 = old semconfig */ \
	"msgctl",              /* 258 = msgctl */ \
	"msgget",              /* 259 = msgget */ \
	"msgsnd",              /* 260 = msgsnd */ \
	"msgrcv",              /* 261 = msgrcv */ \
	"shmat",               /* 262 = shmat */ \
	"shmctl",              /* 263 = shmctl */ \
	"shmdt",               /* 264 = shmdt */ \
	"shmget",              /* 265 = shmget */ \
	"shm_open",            /* 266 = shm_open */ \
	"shm_unlink",          /* 267 = shm_unlink */ \
	"sem_open",            /* 268 = sem_open */ \
	"sem_close",           /* 269 = sem_close */ \
	"sem_unlink",          /* 270 = sem_unlink */ \
	"sem_wait",            /* 271 = sem_wait */ \
	"sem_trywait",         /* 272 = sem_trywait */ \
	"sem_post",            /* 273 = sem_post */ \
	"sysctlbyname",        /* 274 = sysctlbyname */ \
	"#275",                /* 275 = old sem_init */ \
	"#276",                /* 276 = old sem_destroy */ \
	"open_extended",       /* 277 = open_extended */ \
	"umask_extended",      /* 278 = umask_extended */ \
	"stat_extended",       /* 279 = stat_extended */ \
	"lstat_extended",      /* 280 = lstat_extended */ \
	"fstat_extended",      /* 281 = fstat_extended */ \
	"chmod_extended",      /* 282 = chmod_extended */ \
	"fchmod_extended",     /* 283 = fchmod_extended */ \
	"access_extended",     /* 284 = access_extended */ \
	"settid",              /* 285 = settid */ \
	"gettid",              /* 286 = gettid */ \
	"setsgroups",          /* 287 = setsgroups */ \
	"getsgroups",          /* 288 = getsgroups */ \
	"setwgroups",          /* 289 = setwgroups */ \
	"getwgroups",          /* 290 = getwgroups */ \
	"mkfifo_extended",     /* 291 = mkfifo_extended */ \
	"mkdir_extended",      /* 292 = mkdir_extended */ \
	"identitysvc",         /* 293 = identitysvc */ \
	"shared_region_check_np",   /* 294 = shared_region_check_np */ \
	"#295",                /* 295 = old shared_region_map_np */ \
	"vm_pressure_monitor",   /* 296 = vm_pressure_monitor */ \
	"psynch_rw_longrdlock",   /* 297 = psynch_rw_longrdlock */ \
	"psynch_rw_yieldwrlock",   /* 298 = psynch_rw_yieldwrlock */ \
	"psynch_rw_downgrade",   /* 299 = psynch_rw_downgrade */ \
	"psynch_rw_upgrade",   /* 300 = psynch_rw_upgrade */ \
	"psynch_mutexwait",    /* 301 = psynch_mutexwait */ \
	"psynch_mutexdrop",    /* 302 = psynch_mutexdrop */ \
	"psynch_cvbroad",      /* 303 = psynch_cvbroad */ \
	"psynch_cvsignal",     /* 304 = psynch_cvsignal */ \
	"psynch_cvwait",       /* 305 = psynch_cvwait */ \
	"psynch_rw_rdlock",    /* 306 = psynch_rw_rdlock */ \
	"psynch_rw_wrlock",    /* 307 = psynch_rw_wrlock */ \
	"psynch_rw_unlock",    /* 308 = psynch_rw_unlock */ \
	"psynch_rw_unlock2",   /* 309 = psynch_rw_unlock2 */ \
	"getsid",              /* 310 = getsid */ \
	"settid_with_pid",     /* 311 = settid_with_pid */ \
	"psynch_cvclrprepost",   /* 312 = psynch_cvclrprepost */ \
	"aio_fsync",           /* 313 = aio_fsync */ \
	"aio_return",          /* 314 = aio_return */ \
	"aio_suspend",         /* 315 = aio_suspend */ \
	"aio_cancel",          /* 316 = aio_cancel */ \
	"aio_error",           /* 317 = aio_error */ \
	"aio_read",            /* 318 = aio_read */ \
	"aio_write",           /* 319 = aio_write */ \
	"lio_listio",          /* 320 = lio_listio */ \
	"#321",                /* 321 = old __pthread_cond_wait */ \
	"iopolicysys",         /* 322 = iopolicysys */ \
	"process_policy",      /* 323 = process_policy */ \
	"mlockall",            /* 324 = mlockall */ \
	"munlockall",          /* 325 = munlockall */ \
	"#326",                /* 326 = */ \
	"issetugid",           /* 327 = issetugid */ \
	"__pthread_kill",      /* 328 = __pthread_kill */ \
	"__pthread_sigmask",   /* 329 = __pthread_sigmask */ \
	"__sigwait",           /* 330 = __sigwait */ \
	"__disable_threadsignal",   /* 331 = __disable_threadsignal */ \
	"__pthread_markcancel",   /* 332 = __pthread_markcancel */ \
	"__pthread_canceled",   /* 333 = __pthread_canceled */ \
	"__semwait_signal",    /* 334 = __semwait_signal */ \
	"#335",                /* 335 = old utrace */ \
	"proc_info",           /* 336 = proc_info */ \
	"sendfile",            /* 337 = sendfile */ \
	"stat64",              /* 338 = stat64 */ \
	"fstat64",             /* 339 = fstat64 */ \
	"lstat64",             /* 340 = lstat64 */ \
	"stat64_extended",     /* 341 = stat64_extended */ \
	"lstat64_extended",    /* 342 = lstat64_extended */ \
	"fstat64_extended",    /* 343 = fstat64_extended */ \
	"getdirentries64",     /* 344 = getdirentries64 */ \
	"statfs64",            /* 345 = statfs64 */ \
	"fstatfs64",           /* 346 = fstatfs64 */ \
	"getfsstat64",         /* 347 = getfsstat64 */ \
	"__pthread_chdir",     /* 348 = __pthread_chdir */ \
	"__pthread_fchdir",    /* 349 = __pthread_fchdir */ \
	"audit",               /* 350 = audit */ \
	"auditon",             /* 351 = auditon */ \
	"#352",                /* 352 = */ \
	"getauid",             /* 353 = getauid */ \
	"setauid",             /* 354 = setauid */ \
	"#355",                /* 355 = old getaudit */ \
	"#356",                /* 356 = old setaudit */ \
	"getaudit_addr",       /* 357 = getaudit_addr */ \
	"setaudit_addr",       /* 358 = setaudit_addr */ \
	"auditctl",            /* 359 = auditctl */ \
	"bsdthread_create",    /* 360 = bsdthread_create */ \
	"bsdthread_terminate",   /* 361 = bsdthread_terminate */ \
	"kqueue",              /* 362 = kqueue */ \
	"kevent",              /* 363 = kevent */ \
	"lchown",              /* 364 = lchown */ \
	"#365",                /* 365 = old stack_snapshot */ \
	"bsdthread_register",   /* 366 = bsdthread_register */ \
	"workq_open",          /* 367 = workq_open */ \
	"workq_kernreturn",    /* 368 = workq_kernreturn */ \
	"kevent64",            /* 369 = kevent64 */ \
	"__old_semwait_signal",   /* 370 = __old_semwait_signal */ \
	"__old_semwait_signal_nocancel",   /* 371 = __old_semwait_signal_nocancel */ \
	"thread_selfid",       /* 372 = thread_selfid */ \
	"ledger",              /* 373 = ledger */ \
	"kevent_qos",          /* 374 = kevent_qos */ \
	"kevent_id",           /* 375 = kevent_id */ \
	"#376",                /* 376 = */ \
	"#377",                /* 377 = */ \
	"#378",                /* 378 = */ \
	"#379",                /* 379 = */ \
	"__mac_execve",        /* 380 = __mac_execve */ \
	"__mac_syscall",       /* 381 = __mac_syscall */ \
	"__mac_get_file",      /* 382 = __mac_get_file */ \
	"__mac_set_file",      /* 383 = __mac_set_file */ \
	"__mac_get_link",      /* 384 = __mac_get_link */ \
	"__mac_set_link",      /* 385 = __mac_set_link */ \
	"__mac_get_proc",      /* 386 = __mac_get_proc */ \
	"__mac_set_proc",      /* 387 = __mac_set_proc */ \
	"__mac_get_fd",        /* 388 = __mac_get_fd */ \
	"__mac_set_fd",        /* 389 = __mac_set_fd */ \
	"__mac_get_pid",       /* 390 = __mac_get_pid */ \
	"#391",                /* 391 = */ \
	"#392",                /* 392 = */ \
	"#393",                /* 393 = */ \
	"pselect",             /* 394 = pselect */ \
	"pselect_nocancel",    /* 395 = pselect_nocancel */ \
	"read_nocancel",       /* 396 = read_nocancel */ \
	"write_nocancel",      /* 397 = write_nocancel */ \
	"open_nocancel",       /* 398 = open_nocancel */ \
	"close_nocancel",      /* 399 = close_nocancel */ \
	"wait4_nocancel",      /* 400 = wait4_nocancel */ \
	"recvmsg_nocancel",    /* 401 = recvmsg_nocancel */ \
	"sendmsg_nocancel",    /* 402 = sendmsg_nocancel */ \
	"recvfrom_nocancel",   /* 403 = recvfrom_nocancel */ \
	"accept_nocancel",     /* 404 = accept_nocancel */ \
	"msync_nocancel",      /* 405 = msync_nocancel */ \
	"fcntl_nocancel",      /* 406 = fcntl_nocancel */ \
	"select_nocancel",     /* 407 = select_nocancel */ \
	"fsync_nocancel",      /* 408 = fsync_nocancel */ \
	"connect_nocancel",    /* 409 = connect_nocancel */ \
	"sigsuspend_nocancel",   /* 410 = sigsuspend_nocancel */ \
	"readv_nocancel",      /* 411 = readv_nocancel */ \
	"writev_nocancel",     /* 412 = writev_nocancel */ \
	"sendto_nocancel",     /* 413 = sendto_nocancel */ \
	"pread_nocancel",      /* 414 = pread_nocancel */ \
	"pwrite_nocancel",     /* 415 = pwrite_nocancel */ \
	"waitid_nocancel",     /* 416 = waitid_nocancel */ \
	"poll_nocancel",       /* 417 = poll_nocancel */ \
	"msgsnd_nocancel",     /* 418 = msgsnd_nocancel */ \
	"msgrcv_nocancel",     /* 419 = msgrcv_nocancel */ \
	"sem_wait_nocancel",   /* 420 = sem_wait_nocancel */ \
	"aio_suspend_nocancel",   /* 421 = aio_suspend_nocancel */ \
	"__sigwait_nocancel",   /* 422 = __sigwait_nocancel */ \
	"__semwait_signal_nocancel",   /* 423 = __semwait_signal_nocancel */ \
	"__mac_mount",         /* 424 = __mac_mount */ \
	"__mac_get_mount",     /* 425 = __mac_get_mount */ \
	"__mac_getfsstat",     /* 426 = __mac_getfsstat */ \
	"fsgetpath",           /* 427 = fsgetpath private fsgetpath ( File Manager SPI ) */ \
	"audit_session_self",   /* 428 = audit_session_self */ \
	"audit_session_join",   /* 429 = audit_session_join */ \
	"fileport_makeport",   /* 430 = fileport_makeport */ \
	"fileport_makefd",     /* 431 = fileport_makefd */ \
	"audit_session_port",   /* 432 = audit_session_port */ \
	"pid_suspend",         /* 433 = pid_suspend */ \
	"pid_resume",          /* 434 = pid_resume */ \
	"pid_hibernate",       /* 435 = pid_hibernate */ \
	"pid_shutdown_sockets",   /* 436 = pid_shutdown_sockets */ \
	"#437",                /* 437 = old shared_region_slide_np */ \
	"shared_region_map_and_slide_np",   /* 438 = shared_region_map_and_slide_np */ \
	"kas_info",            /* 439 = kas_info */ \
	"memorystatus_control",   /* 440 = memorystatus_control */ \
	"guarded_open_np",     /* 441 = guarded_open_np */ \
	"guarded_close_np",    /* 442 = guarded_close_np */ \
	"guarded_kqueue_np",   /* 443 = guarded_kqueue_np */ \
	"change_fdguard_np",   /* 444 = change_fdguard_np */ \
	"usrctl",              /* 445 = usrctl */ \
	"proc_rlimit_control",   /* 446 = proc_rlimit_control */ \
	"connectx",            /* 447 = connectx */ \
	"disconnectx",         /* 448 = disconnectx */ \
	"peeloff",             /* 449 = peeloff */ \
	"socket_delegate",     /* 450 = socket_delegate */ \
	"telemetry",           /* 451 = telemetry */ \
	"proc_uuid_policy",    /* 452 = proc_uuid_policy */ \
	"memorystatus_get_level",   /* 453 = memorystatus_get_level */ \
	"system_override",     /* 454 = system_override */ \
	"vfs_purge",           /* 455 = vfs_purge */ \
	"sfi_ctl",             /* 456 = sfi_ctl */ \
	"sfi_pidctl",          /* 457 = sfi_pidctl */ \
	"coalition",           /* 458 = coalition */ \
	"coalition_info",      /* 459 = coalition_info */ \
	"necp_match_policy",   /* 460 = necp_match_policy */ \
	"getattrlistbulk",     /* 461 = getattrlistbulk */ \
	"clonefileat",         /* 462 = clonefileat */ \
	"openat",              /* 463 = openat */ \
	"openat_nocancel",     /* 464 = openat_nocancel */ \
	"renameat",            /* 465 = renameat */ \
	"faccessat",           /* 466 = faccessat */ \
	"fchmodat",            /* 467 = fchmodat */ \
	"fchownat",            /* 468 = fchownat */ \
	"fstatat",             /* 469 = fstatat */ \
	"fstatat64",           /* 470 = fstatat64 */ \
	"linkat",              /* 471 = linkat */ \
	"unlinkat",            /* 472 = unlinkat */ \
	"readlinkat",          /* 473 = readlinkat */ \
	"symlinkat",           /* 474 = symlinkat */ \
	"mkdirat",             /* 475 = mkdirat */ \
	"getattrlistat",       /* 476 = getattrlistat */ \
	"proc_trace_log",      /* 477 = proc_trace_log */ \
	"bsdthread_ctl",       /* 478 = bsdthread_ctl */ \
	"openbyid_np",         /* 479 = openbyid_np */ \
	"recvmsg_x",           /* 480 = recvmsg_x */ \
	"sendmsg_x",           /* 481 = sendmsg_x */ \
	"thread_selfusage",    /* 482 = thread_selfusage */ \
	"csrctl",              /* 483 = csrctl */ \
	"guarded_open_dprotected_np",   /* 484 = guarded_open_dprotected_np */ \
	"guarded_write_np",    /* 485 = guarded_write_np */ \
	"guarded_pwrite_np",   /* 486 = guarded_pwrite_np */ \
	"guarded_writev_np",   /* 487 = guarded_writev_np */ \
	"renameatx_np",        /* 488 = renameatx_np */ \
	"mremap_encrypted",    /* 489 = mremap_encrypted */ \
	"netagent_trigger",    /* 490 = netagent_trigger */ \
	"stack_snapshot_with_config",   /* 491 = stack_snapshot_with_config */ \
	"microstackshot",      /* 492 = microstackshot */ \
	"grab_pgo_data",       /* 493 = grab_pgo_data */ \
	"persona",             /* 494 = persona */ \
	"#495",                /* 495 = */ \
	"mach_eventlink_signal",   /* 496 = mach_eventlink_signal */ \
	"mach_eventlink_wait_until",   /* 497 = mach_eventlink_wait_until */ \
	"mach_eventlink_signal_wait_until",   /* 498 = mach_eventlink_signal_wait_until */ \
	"work_interval_ctl",   /* 499 = work_interval_ctl */ \
	"getentropy",          /* 500 = getentropy */ \
	"necp_open",           /* 501 = necp_open */ \
	"necp_client_action",   /* 502 = necp_client_action */ \
	"#503",                /* 503 = */ \
	"#504",                /* 504 = */ \
	"#505",                /* 505 = */ \
	"#506",                /* 506 = */ \
	"#507",                /* 507 = */ \
	"#508",                /* 508 = */ \
	"#509",                /* 509 = */ \
	"#510",                /* 510 = */ \
	"#511",                /* 511 = */ \
	"#512",                /* 512 = */ \
	"#513",                /* 513 = */ \
	"#514",                /* 514 = */ \
	"ulock_wait",          /* 515 = ulock_wait */ \
	"ulock_wake",          /* 516 = ulock_wake */ \
	"fclonefileat",        /* 517 = fclonefileat */ \
	"fs_snapshot",         /* 518 = fs_snapshot */ \
	"#519",                /* 519 = */ \
	"terminate_with_payload",   /* 520 = terminate_with_payload */ \
	"abort_with_payload",   /* 521 = abort_with_payload */ \
	"necp_session_open",   /* 522 = necp_session_open */ \
	"necp_session_action",   /* 523 = necp_session_action */ \
	"setattrlistat",       /* 524 = setattrlistat */ \
	"net_qos_guideline",   /* 525 = net_qos_guideline */ \
	"fmount",              /* 526 = fmount */ \
	"ntp_adjtime",         /* 527 = ntp_adjtime */ \
	"ntp_gettime",         /* 528 = ntp_gettime */ \
	"os_fault_with_payload",   /* 529 = os_fault_with_payload */ \
	"kqueue_workloop_ctl",   /* 530 = kqueue_workloop_ctl */ \
	"__mach_bridge_remote_time",   /* 531 = __mach_bridge_remote_time */ \
	"coalition_ledger",    /* 532 = coalition_ledger */ \
	"log_data",            /* 533 = log_data */ \
	"memorystatus_available_memory",   /* 534 = memorystatus_available_memory */ \
	"#535",                /* 535 = */ \
	"shared_region_map_and_slide_2_np",   /* 536 = shared_region_map_and_slide_2_np */ \
	"pivot_root",          /* 537 = pivot_root */ \
	"task_inspect_for_pid",   /* 538 = task_inspect_for_pid */ \
	"task_read_for_pid",   /* 539 = task_read_for_pid */ \
	"preadv",              /* 540 = preadv */ \
	"pwritev",             /* 541 = pwritev */ \
	"preadv_nocancel",     /* 542 = preadv_nocancel */ \
	"pwritev_nocancel",    /* 543 = pwritev_nocancel */ \
	"ulock_wait2",         /* 544 = ulock_wait2 */ \
	"proc_info_extended_id",   /* 545 = proc_info_extended_id */ \
}

#define MACH_TRAP_TABLE_COUNT 128
#define mach_syscall_name_table { \
/* 0 */ "kern_invalid", \
/* 1 */ "kern_invalid", \
/* 2 */ "kern_invalid", \
/* 3 */ "kern_invalid", \
/* 4 */ "kern_invalid", \
/* 5 */ "kern_invalid", \
/* 6 */ "kern_invalid", \
/* 7 */ "kern_invalid", \
/* 8 */ "kern_invalid", \
/* 9 */ "kern_invalid", \
/* 10 */ "_kernelrpc_mach_vm_allocate_trap", \
/* 11 */ "kern_invalid", \
/* 12 */ "_kernelrpc_mach_vm_deallocate_trap", \
/* 13 */ "task_dyld_process_info_notify_get_trap", \
/* 14 */ "_kernelrpc_mach_vm_protect_trap", \
/* 15 */ "_kernelrpc_mach_vm_map_trap", \
/* 16 */ "_kernelrpc_mach_port_allocate_trap", \
/* 17 */ "kern_invalid", \
/* 18 */ "_kernelrpc_mach_port_deallocate_trap", \
/* 19 */ "_kernelrpc_mach_port_mod_refs_trap", \
/* 20 */ "_kernelrpc_mach_port_move_member_trap", \
/* 21 */ "_kernelrpc_mach_port_insert_right_trap", \
/* 22 */ "_kernelrpc_mach_port_insert_member_trap", \
/* 23 */ "_kernelrpc_mach_port_extract_member_trap", \
/* 24 */ "_kernelrpc_mach_port_construct_trap", \
/* 25 */ "_kernelrpc_mach_port_destruct_trap", \
/* 26 */ "mach_reply_port", \
/* 27 */ "thread_self_trap", \
/* 28 */ "task_self_trap", \
/* 29 */ "host_self_trap", \
/* 30 */ "kern_invalid", \
/* 31 */ "mach_msg_trap", \
/* 32 */ "mach_msg_overwrite_trap", \
/* 33 */ "semaphore_signal_trap", \
/* 34 */ "semaphore_signal_all_trap", \
/* 35 */ "semaphore_signal_thread_trap", \
/* 36 */ "semaphore_wait_trap", \
/* 37 */ "semaphore_wait_signal_trap", \
/* 38 */ "semaphore_timedwait_trap", \
/* 39 */ "semaphore_timedwait_signal_trap", \
/* 40 */ "kern_invalid", \
/* 41 */ "_kernelrpc_mach_port_guard_trap", \
/* 42 */ "_kernelrpc_mach_port_unguard_trap", \
/* 43 */ "mach_generate_activity_id", \
/* 44 */ "task_name_for_pid", \
/* 45 */ "task_for_pid", \
/* 46 */ "pid_for_task", \
/* 47 */ "kern_invalid", \
/* 48 */ "macx_swapon", \
/* 49 */ "macx_swapoff", \
/* 50 */ "thread_get_special_reply_port", \
/* 51 */ "macx_triggers", \
/* 52 */ "macx_backing_store_suspend", \
/* 53 */ "macx_backing_store_recovery", \
/* 54 */ "kern_invalid", \
/* 55 */ "kern_invalid", \
/* 56 */ "kern_invalid", \
/* 57 */ "kern_invalid", \
/* 58 */ "pfz_exit", \
/* 59 */ "swtch_pri", \
/* 60 */ "swtch", \
/* 61 */ "thread_switch", \
/* 62 */ "clock_sleep_trap", \
/* 63 */ "kern_invalid", \
/* traps 64 - 95 reserved (debo) */ \
/* 64 */ "kern_invalid", \
/* 65 */ "kern_invalid", \
/* 66 */ "kern_invalid", \
/* 67 */ "kern_invalid", \
/* 68 */ "kern_invalid", \
/* 69 */ "kern_invalid", \
/* 70 */ "host_create_mach_voucher_trap", \
/* 71 */ "kern_invalid", \
/* 72 */ "mach_voucher_extract_attr_recipe_trap", \
/* 73 */ "kern_invalid", \
/* 74 */ "kern_invalid", \
/* 75 */ "kern_invalid", \
/* 76 */ "_kernelrpc_mach_port_type_trap", \
/* 77 */ "_kernelrpc_mach_port_request_notification_trap", \
/* 78 */ "kern_invalid", \
/* 79 */ "kern_invalid", \
/* 80 */ "kern_invalid", \
/* 81 */ "kern_invalid", \
/* 82 */ "kern_invalid", \
/* 83 */ "kern_invalid", \
/* 84 */ "kern_invalid", \
/* 85 */ "kern_invalid", \
/* 86 */ "kern_invalid", \
/* 87 */ "kern_invalid", \
/* 88 */ "kern_invalid", \
/* 89 */ "mach_timebase_info_trap", \
/* 90 */ "mach_wait_until_trap", \
/* 91 */ "mk_timer_create_trap", \
/* 92 */ "mk_timer_destroy_trap", \
/* 93 */ "mk_timer_arm_trap", \
/* 94 */ "mk_timer_cancel_trap", \
/* 95 */ "kern_invalid", \
/* traps 64 - 95 reserved (debo) */ \
/* 96 */ "debug_control_port_for_pid", \
/* 97 */ "kern_invalid", \
/* 98 */ "kern_invalid", \
/* 99 */ "kern_invalid", \
/* traps 100-107 reserved for iokit (esb) */ \
/* 100 */ "iokit_user_client_trap", \
/* 101 */ "kern_invalid", \
/* 102 */ "kern_invalid", \
/* 103 */ "kern_invalid", \
/* 104 */ "kern_invalid", \
/* 105 */ "kern_invalid", \
/* 106 */ "kern_invalid", \
/* 107 */ "kern_invalid", \
/* traps 108-127 unused */ \
/* 108 */ "kern_invalid", \
/* 109 */ "kern_invalid", \
/* 110 */ "kern_invalid", \
/* 111 */ "kern_invalid", \
/* 112 */ "kern_invalid", \
/* 113 */ "kern_invalid", \
/* 114 */ "kern_invalid", \
/* 115 */ "kern_invalid", \
/* 116 */ "kern_invalid", \
/* 117 */ "kern_invalid", \
/* 118 */ "kern_invalid", \
/* 119 */ "kern_invalid", \
/* 120 */ "kern_invalid", \
/* 121 */ "kern_invalid", \
/* 122 */ "kern_invalid", \
/* 123 */ "kern_invalid", \
/* 124 */ "kern_invalid", \
/* 125 */ "kern_invalid", \
/* 126 */ "kern_invalid", \
/* 127 */ "kern_invalid", \
}

