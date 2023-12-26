    siginfo_t siginfo;
    pid_t tid;  // the crashing thread.
    ucontext_t context;
#if !defined(__ARM_EABI__) && !defined(__mips__)
    // #ifdef this out because FP state is not part of user ABI for Linux ARM.
    // In case of MIPS Linux FP state is already part of ucontext_t so
    // 'float_state' is not required.

//----replace
    siginfo_t siginfo;
    pid_t tid;  // the crashing thread.
    ucontext_t context;
#if !defined(__ARM_EABI__) && !defined(__mips__) && !defined(__loongarch64) // loongarch64
    // #ifdef this out because FP state is not part of user ABI for Linux ARM.
    // In case of MIPS Linux FP state is already part of ucontext_t so
    // 'float_state' is not required.
