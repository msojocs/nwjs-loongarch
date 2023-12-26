#elif defined(ARCH_CPU_BIG_ENDIAN)
    static constexpr char arch[] = "aarch64_be";
#endif
#else
#error Port
#endif

//----replace
#elif defined(ARCH_CPU_BIG_ENDIAN)
    static constexpr char arch[] = "aarch64_be";
#endif
#elif defined(ARCH_CPU_LOONG64) // loongarch64
    static constexpr char arch[] = "loongarch64"; // loongarch64
#else
#error Port
#endif
