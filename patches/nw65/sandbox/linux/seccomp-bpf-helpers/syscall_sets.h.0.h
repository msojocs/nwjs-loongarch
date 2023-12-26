#endif

#if defined(__x86_64__) || defined(__arm__) || defined(__mips__) || \
    defined(__aarch64__)
  static bool IsNetworkSocketInformation(int sysno);
#endif


//----replace
#endif

#if defined(__x86_64__) || defined(__arm__) || defined(__mips__) || \
    defined(__aarch64__) || defined(__loongarch64) // loongarch64
  static bool IsNetworkSocketInformation(int sysno);
#endif

