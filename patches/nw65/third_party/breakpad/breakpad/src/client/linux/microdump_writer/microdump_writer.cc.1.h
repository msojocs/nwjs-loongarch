# else
#  error "This mips ABI is currently not supported (n32)"
#endif
#else
#error "This code has not been ported to your platform yet"
#endif

//----replace
# else
#  error "This mips ABI is currently not supported (n32)"
#endif
#elif defined(__loongarch64) // loongarch64
    const char kArch[] = "loongarch64"; // loongarch64
#else
#error "This code has not been ported to your platform yet"
#endif
