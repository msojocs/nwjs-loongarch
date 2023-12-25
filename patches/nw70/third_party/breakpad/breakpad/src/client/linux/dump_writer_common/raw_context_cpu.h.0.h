typedef MDRawContextARM64_Old RawContextCPU;
#elif defined(__mips__)
typedef MDRawContextMIPS RawContextCPU;
#else
#error "This code has not been ported to your platform yet."
#endif

//----replace
typedef MDRawContextARM64_Old RawContextCPU;
#elif defined(__mips__)
typedef MDRawContextMIPS RawContextCPU;
#elif defined(__loongarch64)
typedef MDRawContextLOONGARCH64 RawContextCPU;
#else
#error "This code has not been ported to your platform yet."
#endif
