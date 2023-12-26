  static bool IsAsyncIo(int sysno);
  static bool IsKeyManagement(int sysno);
#if defined(__x86_64__) || defined(__arm__) || defined(__aarch64__) || \
    (defined(ARCH_CPU_MIPS_FAMILY) && defined(ARCH_CPU_64_BITS))
  static bool IsSystemVSemaphores(int sysno);
#endif
#if defined(__i386__) || defined(__x86_64__) || defined(__arm__) || \
    defined(__aarch64__) ||                                         \
    (defined(ARCH_CPU_MIPS_FAMILY) && defined(ARCH_CPU_64_BITS))
  // These give a lot of ambient authority and bypass the setuid sandbox.
  static bool IsSystemVSharedMemory(int sysno);
#endif

#if defined(__x86_64__) || defined(__arm__) || defined(__aarch64__) || \
    (defined(ARCH_CPU_MIPS_FAMILY) && defined(ARCH_CPU_64_BITS))
  static bool IsSystemVMessageQueue(int sysno);
#endif


//----replace
  static bool IsAsyncIo(int sysno);
  static bool IsKeyManagement(int sysno);
#if defined(__x86_64__) || defined(__arm__) || defined(__aarch64__) || \
    (defined(ARCH_CPU_MIPS_FAMILY) && defined(ARCH_CPU_64_BITS)) || \
    defined(__loongarch64) // loongarch64
  static bool IsSystemVSemaphores(int sysno);
#endif
#if defined(__i386__) || defined(__x86_64__) || defined(__arm__) || \
    defined(__aarch64__) || defined(__loongarch64) ||               \
    (defined(ARCH_CPU_MIPS_FAMILY) && defined(ARCH_CPU_64_BITS))
  // These give a lot of ambient authority and bypass the setuid sandbox.
  static bool IsSystemVSharedMemory(int sysno);
#endif

#if defined(__x86_64__) || defined(__arm__) || defined(__aarch64__) || \
    (defined(ARCH_CPU_MIPS_FAMILY) && defined(ARCH_CPU_64_BITS)) || \
    defined(__loongarch64) // loongarch64
  static bool IsSystemVMessageQueue(int sysno);
#endif

