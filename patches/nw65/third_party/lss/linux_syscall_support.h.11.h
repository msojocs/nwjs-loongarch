    // fork is polyfilled below when not available.
    LSS_INLINE _syscall0(pid_t,   fork)
  #endif
  LSS_INLINE _syscall2(int,     fstat,           int,         f,
                      struct kernel_stat*,   b)
  LSS_INLINE _syscall2(int,     fstatfs,         int,         f,
                      struct kernel_statfs*, b)
  #if defined(__x86_64__)

//----replace
    // fork is polyfilled below when not available.
    LSS_INLINE _syscall0(pid_t,   fork)
  #endif
#if !defined(__loongarch64) // loongarch64
  LSS_INLINE _syscall2(int,     fstat,           int,         f,
                      struct kernel_stat*,   b)
#endif // loongarch64
  LSS_INLINE _syscall2(int,     fstatfs,         int,         f,
                      struct kernel_statfs*, b)
  #if defined(__x86_64__)
