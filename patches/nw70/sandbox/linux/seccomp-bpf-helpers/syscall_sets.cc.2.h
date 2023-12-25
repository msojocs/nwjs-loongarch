#endif
    case __NR_openat:
    case __NR_readlinkat:
    case __NR_renameat:
    case __NR_renameat2:
#if defined(__i386__) || defined(__arm__) || \
    (defined(ARCH_CPU_MIPS_FAMILY) && defined(ARCH_CPU_32_BITS))

//----replace
#endif
    case __NR_openat:
    case __NR_readlinkat:
#if !defined(__loongarch64)
    case __NR_renameat:
#endif
    case __NR_renameat2:
#if defined(__i386__) || defined(__arm__) || \
    (defined(ARCH_CPU_MIPS_FAMILY) && defined(ARCH_CPU_32_BITS))
