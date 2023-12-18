#elif defined(ARCH_CPU_RISCV64)
    CPUContextRISCV64 riscv64;
#elif defined(ARCH_CPU_LOONGARCH64)
    CPUContextLOONGARCH64 loongarch64;
#else
#error Port.