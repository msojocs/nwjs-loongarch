#elif defined(ARCH_CPU_MIPS_FAMILY) || defined(ARCH_CPU_LOONGARCH64)
// No appropriate floating point context native type for available MIPS.
#elif defined(ARCH_CPU_RISCV64)
  static_assert(sizeof(f64) == sizeof(__riscv_d_ext_state), "Size mismatch");
#else
#error Port.