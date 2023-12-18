#elif defined(ARCH_CPU_RISCV64)
  static constexpr char kCPU[] = "riscv64";
#else
#error define kCPU for this CPU