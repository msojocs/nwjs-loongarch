  #define ELF_ARCH  EM_MIPS
#elif defined(__aarch64__)
  #define ELF_ARCH  EM_AARCH64
#endif

#if defined(__arm__)

//----replace
  #define ELF_ARCH  EM_MIPS
#elif defined(__aarch64__)
  #define ELF_ARCH  EM_AARCH64
#elif defined(__loongarch64) // loongarch64
  #define ELF_ARCH  EM_LOONGARCH // loongarch64
#endif

#if defined(__arm__)
