    } fpregs[32];
    uint32_t fpcsr;
    uint32_t fpu_id;
#else
#error Port.
#endif  // ARCH_CPU_X86_FAMILY

//----replace
    } fpregs[32];
    uint32_t fpcsr;
    uint32_t fpu_id;
#elif defined(ARCH_CPU_LOONG64)
    // Nothing.
#else
#error Port.
#endif  // ARCH_CPU_X86_FAMILY
