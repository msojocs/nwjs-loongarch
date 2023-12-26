    case __NR_oldfstat:
#endif
#if defined(__i386__) || defined(__x86_64__) || defined(__mips__) || \
    defined(__aarch64__)
    case __NR_sync_file_range:  // EPERM not a valid errno.
#elif defined(__arm__)
    case __NR_arm_sync_file_range:  // EPERM not a valid errno.

//----replace
    case __NR_oldfstat:
#endif
#if defined(__i386__) || defined(__x86_64__) || defined(__mips__) || \
    defined(__aarch64__) || defined(__loongarch64) // loongarch64
    case __NR_sync_file_range:  // EPERM not a valid errno.
#elif defined(__arm__)
    case __NR_arm_sync_file_range:  // EPERM not a valid errno.
