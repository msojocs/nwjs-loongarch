#elif defined(ARCH_CPU_MIPS_FAMILY)
  // Not implementable on MIPS
  return std::string();
#else
#error port to your architecture
#endif

//----replace
#elif defined(ARCH_CPU_MIPS_FAMILY)
  // Not implementable on MIPS
  return std::string();
#elif defined(ARCH_CPU_LOONG64)
  // Not implementable on LOONGARCH64
  return std::string();
#else
#error port to your architecture
#endif
