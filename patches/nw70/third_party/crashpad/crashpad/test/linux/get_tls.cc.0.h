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
#elif defined(ARCH_CPU_LOONG64)
  asm("move    %0,$tp\n\t"
      : "=r"(tls) ::);
#else
#error Port.
#endif  // ARCH_CPU_ARMEL
