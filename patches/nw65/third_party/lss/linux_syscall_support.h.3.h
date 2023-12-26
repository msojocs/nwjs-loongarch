} __attribute__((packed,aligned(4)));
#elif (defined(__mips__) && _MIPS_SIM == _MIPS_SIM_ABI32)
  #define kernel_old_sigaction kernel_sigaction
#elif defined(__aarch64__)
  // No kernel_old_sigaction defined for arm64.
#endif


//----replace
} __attribute__((packed,aligned(4)));
#elif (defined(__mips__) && _MIPS_SIM == _MIPS_SIM_ABI32)
  #define kernel_old_sigaction kernel_sigaction
#elif defined(__aarch64__) || defined(__loongarch64) // loongarch64
  // No kernel_old_sigaction defined for arm64.
#endif

