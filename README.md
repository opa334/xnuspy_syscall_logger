# xnuspy syscall logger

Prints all executed syscalls by a process to klog (change process name to the process you want to log [here](main.c#L17)).

Needs mach_syscall and unix_syscall kernel offsets for your device added [here](main.c#L25).

Afterwards compile, install and run `xnuspy_syscall_logger` on a device that's booted with [xnuspy](https://github.com/jsherman212/xnuspy).