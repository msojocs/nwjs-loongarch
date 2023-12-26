    (defined(ARCH_CPU_MIPS_FAMILY) && defined(ARCH_CPU_32_BITS))
    case __NR_ftruncate64:
#endif
#if !defined(__aarch64__)
    case __NR_getdents:
#endif
    case __NR_getdents64:

//----replace
    (defined(ARCH_CPU_MIPS_FAMILY) && defined(ARCH_CPU_32_BITS))
    case __NR_ftruncate64:
#endif
#if !defined(__aarch64__) && !defined(__loongarch64) // loongarch64
    case __NR_getdents:
#endif
    case __NR_getdents64:
