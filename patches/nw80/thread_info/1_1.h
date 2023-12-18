#elif defined(ARCH_CPU_RISCV64)
    // Reflects user_regs_struct in asm/ptrace.h.
    uint64_t pc;
    uint64_t regs[31];
#elif defined(ARCH_CPU_LOONGARCH64)
    // Reflects user_regs_struct in sys/user.h.
    uint64_t regs[32];
    uint64_t orig_a0;
    uint64_t csr_era;
    uint64_t csr_badv;
    uint64_t reserved[10];
#else
#error Port.