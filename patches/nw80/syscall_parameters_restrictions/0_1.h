#if !defined(__aarch64__)
                 PTRACE_GETREGS, PTRACE_GETFPREGS,
                 PTRACE_GETREGSET,
#if !defined(__loongarch64)
                 PTRACE_GET_THREAD_AREA,
#endif
#endif