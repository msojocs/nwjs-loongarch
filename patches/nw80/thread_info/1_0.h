#elif defined(ARCH_CPU_RISCV64)
    // Reflects user_regs_struct in asm/ptrace.h.
    uint64_t pc;
    uint64_t regs[31];
#else
#error Port.