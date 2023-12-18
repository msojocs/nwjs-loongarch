#elif defined (ARCH_CPU_RISCV64)
    static constexpr char arch[] = "riscv64";
#else
#error Port
//----replace
#elif defined (ARCH_CPU_RISCV64)
    static constexpr char arch[] = "riscv64";
#elif defined(ARCH_CPU_LOONGARCH64)
    static constexpr char arch[] = "loongarch64";
#else
#error Port