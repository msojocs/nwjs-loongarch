    double fpregs[32];
    uint32_t fpcsr;
    uint32_t fpu_id;
#else
#error Port.
#endif  // ARCH_CPU_X86_FAMILY

//----replace
    double fpregs[32];
    uint32_t fpcsr;
    uint32_t fpu_id;
#elif defined(ARCH_CPU_LOONG64) // loongarch64
    double fpregs[32]; // loongarch64
    uint64_t fcc; // loongarch64
    uint32_t fcsr; // loongarch64
    uint32_t _pad; // loongarch64
#else
#error Port.
#endif  // ARCH_CPU_X86_FAMILY
