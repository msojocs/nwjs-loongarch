      : "=r"(tls)
      :
      : "$3");
#else
#error Port.
#endif  // ARCH_CPU_ARMEL

//----replace
      : "=r"(tls)
      :
      : "$3");
#elif defined(ARCH_CPU_LOONG64) // loongarch64
  asm("move    %0,$tp\n\t" // loongarch64
      : "=r"(tls) ::); // loongarch64
#else
#error Port.
#endif  // ARCH_CPU_ARMEL
