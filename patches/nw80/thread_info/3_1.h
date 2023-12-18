#elif defined(ARCH_CPU_RISCV64)
    // Reflects __riscv_d_ext_state in asm/ptrace.h
    uint64_t fpregs[32];
    uint64_t fcsr;
#elif defined(ARCH_CPU_LOONGARCH64)
    double fpregs[32];
    uint64_t fcc;
    uint32_t fcsr;
    uint32_t _pad;
#else
#error Port.