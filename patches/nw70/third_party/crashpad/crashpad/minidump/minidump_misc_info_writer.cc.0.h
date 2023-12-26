  static constexpr char kCPU[] = "mips";
#elif defined(ARCH_CPU_MIPS64EL)
  static constexpr char kCPU[] = "mips64";
#else
#error define kCPU for this CPU
#endif

//----replace
  static constexpr char kCPU[] = "mips";
#elif defined(ARCH_CPU_MIPS64EL)
  static constexpr char kCPU[] = "mips64";
#elif defined(ARCH_CPU_LOONG64)// loongarch64
  static constexpr char kCPU[] = "loongarch64";// loongarch64
#else
#error define kCPU for this CPU
#endif
