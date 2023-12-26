#elif defined(ARCH_CPU_MIPS_FAMILY)
    CPUContextMIPS mipsel;
    CPUContextMIPS64 mips64;
#else
#error Port.
#endif  // ARCH_CPU_X86_FAMILY

//----replace
#elif defined(ARCH_CPU_MIPS_FAMILY)
    CPUContextMIPS mipsel;
    CPUContextMIPS64 mips64;
#elif defined(ARCH_CPU_LOONG64) // loongarch64
    CPUContextLOONGARCH64 loongarch64; // loongarch64
#else
#error Port.
#endif  // ARCH_CPU_X86_FAMILY
