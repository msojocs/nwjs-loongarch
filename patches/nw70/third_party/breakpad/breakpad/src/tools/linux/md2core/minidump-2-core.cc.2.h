#endif
#if defined(__aarch64__)
    user_fpsimd_struct fpregs;
#endif
    uintptr_t stack_addr;
    const uint8_t* stack;

//----replace
#endif
#if defined(__aarch64__)
    user_fpsimd_struct fpregs;
#endif// loongarch64
#if defined(__loongarch64)// loongarch64
    user_fp_struct fpregs;// loongarch64
#endif
    uintptr_t stack_addr;
    const uint8_t* stack;
