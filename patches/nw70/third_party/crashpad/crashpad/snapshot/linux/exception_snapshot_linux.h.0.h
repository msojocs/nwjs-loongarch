#elif defined(ARCH_CPU_MIPS_FAMILY)
    CPUContextMIPS mipsel;
    CPUContextMIPS64 mips64;
#endif
  } context_union_;
  CPUContext context_;

//----replace
#elif defined(ARCH_CPU_MIPS_FAMILY)
    CPUContextMIPS mipsel;
    CPUContextMIPS64 mips64;
#elif defined(ARCH_CPU_LOONG64)// loongarch64
    CPUContextLOONGARCH64 loongarch64;// loongarch64
#endif
  } context_union_;
  CPUContext context_;
