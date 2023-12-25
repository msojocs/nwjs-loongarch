#elif DAWN_PLATFORM_IS(ARM64)
    __asm__ __volatile__("brk 0");
#elif DAWN_PLATFORM_IS(LOONGARCH)
    __asm__ __volatile__("break");
#elif DAWN_PLATFORM_IS(RISCV)
    __asm__ __volatile__("ebreak");
#elif DAWN_PLATFORM_IS(MIPS)
    __asm__ __volatile__("break");
#elif DAWN_PLATFORM_IS(S390) || DAWN_PLATFORM_IS_(S390X)
    __asm__ __volatile__(".word 0x0001");
#elif DAWN_PLATFORM_IS(PPC) || DAWN_PLATFORM_IS_(PPC64)
    __asm__ __volatile__("twge 2,2");
#else
#error "Unsupported platform"

//----replace
#elif DAWN_PLATFORM_IS(ARM64)
    __asm__ __volatile__("brk 0");
#elif DAWN_PLATFORM_IS(LOONGARCH)
    __asm__ __volatile__("break 0");
#elif DAWN_PLATFORM_IS(RISCV)
    __asm__ __volatile__("ebreak");
#elif DAWN_PLATFORM_IS(MIPS)
    __asm__ __volatile__("break");
#elif DAWN_PLATFORM_IS(S390) || DAWN_PLATFORM_IS(S390X)
    __asm__ __volatile__(".word 0x0001");
#elif DAWN_PLATFORM_IS(PPC) || DAWN_PLATFORM_IS(PPC64)
    __asm__ __volatile__("twge 2,2");
#else
#error "Unsupported platform"
