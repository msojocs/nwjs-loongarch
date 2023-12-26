    uint64_t cp0_badvaddr;
    uint64_t cp0_status;
    uint64_t cp0_cause;
#else
#error Port.
#endif  // ARCH_CPU_X86_FAMILY

//----replace
    uint64_t cp0_badvaddr;
    uint64_t cp0_status;
    uint64_t cp0_cause;
#elif defined(ARCH_CPU_LOONG64) // loongarch64
    // Reflects user_regs_struct in sys/user.h. // loongarch64
    uint64_t regs[32]; // loongarch64
    uint64_t orig_a0; // loongarch64
    uint64_t csr_era; // loongarch64
    uint64_t csr_badv; // loongarch64
    uint64_t reserved[10]; // loongarch64
#else
#error Port.
#endif  // ARCH_CPU_X86_FAMILY
