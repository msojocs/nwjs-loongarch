#endif
#elif defined(ARCH_CPU_ARM64)
  static_assert(sizeof(f64) == sizeof(user_fpsimd_struct), "Size mismatch");
#elif defined(ARCH_CPU_MIPS_FAMILY)
// No appropriate floating point context native type for available MIPS.
#else
#error Port.

//----replace
#endif
#elif defined(ARCH_CPU_ARM64)
  static_assert(sizeof(f64) == sizeof(user_fpsimd_struct), "Size mismatch");
#elif defined(ARCH_CPU_MIPS_FAMILY) || defined (ARCH_CPU_LOONG64)// loongarch64
// No appropriate floating point context native type for available MIPS.
#else
#error Port.
