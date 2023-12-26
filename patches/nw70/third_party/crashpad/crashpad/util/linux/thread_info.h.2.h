  using NativeThreadContext = user_regs_struct;
#elif defined(ARCH_CPU_ARMEL)
  using NativeThreadContext = user_regs;
#elif defined(ARCH_CPU_MIPS_FAMILY)
// No appropriate NativeThreadsContext type available for MIPS
#else
#error Port.
#endif  // ARCH_CPU_X86_FAMILY || ARCH_CPU_ARM64

#if !defined(ARCH_CPU_MIPS_FAMILY)
#if defined(ARCH_CPU_32_BITS)
  static_assert(sizeof(t32_t) == sizeof(NativeThreadContext), "Size mismatch");
#else  // ARCH_CPU_64_BITS

//----replace
  using NativeThreadContext = user_regs_struct;
#elif defined(ARCH_CPU_ARMEL)
  using NativeThreadContext = user_regs;
#elif defined(ARCH_CPU_MIPS_FAMILY) || defined (ARCH_CPU_LOONG64)// loongarch64
// No appropriate NativeThreadsContext type available for MIPS
#else
#error Port.
#endif  // ARCH_CPU_X86_FAMILY || ARCH_CPU_ARM64

#if !defined(ARCH_CPU_MIPS_FAMILY) && !defined(ARCH_CPU_LOONG64)// loongarch64
#if defined(ARCH_CPU_32_BITS)
  static_assert(sizeof(t32_t) == sizeof(NativeThreadContext), "Size mismatch");
#else  // ARCH_CPU_64_BITS
