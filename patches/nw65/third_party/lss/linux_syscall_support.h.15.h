    LSS_INLINE _syscall4(int, socketpair, int, d, int, type, int, protocol,
                         int*, sv)
  #endif
  #if defined(__i386__) || defined(__ARM_ARCH_3__) ||                         \
      (defined(__mips__) && _MIPS_SIM == _MIPS_SIM_ABI32) ||                  \
      defined(__s390__)

//----replace
    LSS_INLINE _syscall4(int, socketpair, int, d, int, type, int, protocol,
                         int*, sv)
  #endif
  #if defined(__loongarch64) // loongarch64
    LSS_INLINE _syscall5(int, statx, int, dfd, const char*, pathname, int, flags, unsigned int, mask, struct kernel_stat*, statxbuf) // loongarch64
  #endif // loongarch64
  #if defined(__i386__) || defined(__ARM_ARCH_3__) ||                         \
      (defined(__mips__) && _MIPS_SIM == _MIPS_SIM_ABI32) ||                  \
      defined(__s390__)
