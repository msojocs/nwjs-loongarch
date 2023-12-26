                       gid_t *,         e,       gid_t *,     s)
  LSS_INLINE _syscall3(int,     getresuid,       uid_t *,     r,
                       uid_t *,         e,       uid_t *,     s)
#if !defined(__ARM_EABI__)
  LSS_INLINE _syscall2(int,     getrlimit,       int,         r,
                      struct kernel_rlimit*, l)
#endif

//----replace
                       gid_t *,         e,       gid_t *,     s)
  LSS_INLINE _syscall3(int,     getresuid,       uid_t *,     r,
                       uid_t *,         e,       uid_t *,     s)
#if !defined(__ARM_EABI__) && !defined(__loongarch64) // loongarch64
  LSS_INLINE _syscall2(int,     getrlimit,       int,         r,
                      struct kernel_rlimit*, l)
#endif
