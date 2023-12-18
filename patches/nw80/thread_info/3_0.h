#elif defined(ARCH_CPU_RISCV64)
    // Reflects __riscv_d_ext_state in asm/ptrace.h
    uint64_t fpregs[32];
    uint64_t fcsr;
#else
#error Port.