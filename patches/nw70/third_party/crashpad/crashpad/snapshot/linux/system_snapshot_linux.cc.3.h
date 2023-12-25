#elif defined(ARCH_CPU_MIPS_FAMILY)
  // Not implementable on MIPS
  return false;
#else
#error Port.
#endif  // ARCH_CPU_X86_FAMILY

//----replace
#elif defined(ARCH_CPU_MIPS_FAMILY)
  // Not implementable on MIPS
  return false;
#elif defined(ARCH_CPU_LOONG64)
  // Not implementable on LOONGARCH64
  return false;
#else
#error Port.
#endif  // ARCH_CPU_X86_FAMILY
