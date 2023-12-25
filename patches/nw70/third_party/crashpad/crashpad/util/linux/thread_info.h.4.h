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
#elif defined(ARCH_CPU_LOONG64)
    double fpregs[32];
    uint64_t fcc;
    uint32_t fcsr;
    uint32_t _pad;
#else
#error Port.
#endif  // ARCH_CPU_X86_FAMILY
