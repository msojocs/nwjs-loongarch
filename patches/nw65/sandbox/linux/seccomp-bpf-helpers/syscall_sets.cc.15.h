    (defined(ARCH_CPU_MIPS_FAMILY) && defined(ARCH_CPU_32_BITS))
    case __NR__llseek:
#endif
#if !defined(__aarch64__)
    case __NR_poll:
#endif
    case __NR_ppoll:

//----replace
    (defined(ARCH_CPU_MIPS_FAMILY) && defined(ARCH_CPU_32_BITS))
    case __NR__llseek:
#endif
#if !defined(__aarch64__) && !defined(__loongarch64) // loongarch64
    case __NR_poll:
#endif
    case __NR_ppoll:
