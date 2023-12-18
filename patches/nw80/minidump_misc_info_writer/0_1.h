#elif defined(ARCH_CPU_RISCV64)
  static constexpr char kCPU[] = "riscv64";
#elif defined(ARCH_CPU_LOONGARCH64)
  static constexpr char kCPU[] = "loongarch64";
#else
#error define kCPU for this CPU