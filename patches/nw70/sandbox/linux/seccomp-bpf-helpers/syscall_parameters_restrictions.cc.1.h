  return Switch(request)
      .CASES((
#if !defined(__aarch64__)
                 PTRACE_GETREGS, PTRACE_GETFPREGS, PTRACE_GET_THREAD_AREA,
                 PTRACE_GETREGSET,
#endif
#if defined(__arm__)
                 PTRACE_GETVFPREGS,

//----replace
  return Switch(request)
      .CASES((
#if !defined(__aarch64__)
                 PTRACE_GETREGS, PTRACE_GETFPREGS, // loongarch64
                 PTRACE_GETREGSET,
#if !defined(__loongarch64)// loongarch64
		 PTRACE_GET_THREAD_AREA,// loongarch64
#endif// loongarch64
#endif
#if defined(__arm__)
                 PTRACE_GETVFPREGS,
