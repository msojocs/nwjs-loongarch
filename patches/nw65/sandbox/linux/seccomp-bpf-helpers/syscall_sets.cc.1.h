    case __NR_faccessat2:
    case __NR_fchmodat:
    case __NR_fchownat:  // Should be called chownat ?
#if defined(__x86_64__) || defined(__aarch64__)
    case __NR_newfstatat:  // fstatat(). EPERM not a valid errno.
#elif defined(__i386__) || defined(__arm__) || \
    (defined(ARCH_CPU_MIPS_FAMILY) && defined(ARCH_CPU_32_BITS))

//----replace
    case __NR_faccessat2:
    case __NR_fchmodat:
    case __NR_fchownat:  // Should be called chownat ?
#if defined(__x86_64__) || defined(__aarch64__)  // loongarch64
    case __NR_newfstatat:  // fstatat(). EPERM not a valid errno.
#elif defined(__i386__) || defined(__arm__) || \
    (defined(ARCH_CPU_MIPS_FAMILY) && defined(ARCH_CPU_32_BITS))
