#elif defined(ARCH_CPU_MIPS_FAMILY)
  // Not implementable on MIPS
  return 0;
#else
#error port to your architecture
#endif

//----replace
#elif defined(ARCH_CPU_MIPS_FAMILY)
  // Not implementable on MIPS
  return 0;
#elif defined(ARCH_CPU_LOONG64)
  // Not implementable on LOONGARCH64
  return 0;
#else
#error port to your architecture
#endif
