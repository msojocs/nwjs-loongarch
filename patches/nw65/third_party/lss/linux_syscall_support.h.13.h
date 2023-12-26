                       gid_t,          e, gid_t,  s)
  LSS_INLINE _syscall3(int,     setresuid,       uid_t,       r,
                       uid_t,          e, uid_t,  s)
  LSS_INLINE _syscall2(int,     setrlimit,       int,         r,
                       const struct kernel_rlimit*, l)
  LSS_INLINE _syscall0(pid_t,    setsid)
  LSS_INLINE _syscall2(int,     sigaltstack,     const stack_t*, s,
                       const stack_t*, o)

//----replace
                       gid_t,          e, gid_t,  s)
  LSS_INLINE _syscall3(int,     setresuid,       uid_t,       r,
                       uid_t,          e, uid_t,  s)
#if !defined(__loongarch64) // loongarch64
  LSS_INLINE _syscall2(int,     setrlimit,       int,         r,
                       const struct kernel_rlimit*, l)
#endif // loongarch64
  LSS_INLINE _syscall0(pid_t,    setsid)
  LSS_INLINE _syscall2(int,     sigaltstack,     const stack_t*, s,
                       const stack_t*, o)
