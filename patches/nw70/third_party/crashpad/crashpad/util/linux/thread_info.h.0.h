    uint32_t cp0_status;
    uint32_t cp0_cause;
    uint32_t padding1_;
#else
#error Port.
#endif  // ARCH_CPU_X86_FAMILY

//----replace
    uint32_t cp0_status;
    uint32_t cp0_cause;
    uint32_t padding1_;
#elif defined(ARCH_CPU_LOONG64)// loongarch64
    // Nothing.// loongarch64
#else
#error Port.
#endif  // ARCH_CPU_X86_FAMILY
