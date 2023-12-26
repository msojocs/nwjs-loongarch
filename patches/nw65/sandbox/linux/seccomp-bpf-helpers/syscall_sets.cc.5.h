#if defined(__i386__) || defined(__arm__)
    case __NR_fchown32:
#endif
#if !defined(__aarch64__)
    case __NR_getdents:    // EPERM not a valid errno.
#endif
    case __NR_getdents64:  // EPERM not a valid errno.

//----replace
#if defined(__i386__) || defined(__arm__)
    case __NR_fchown32:
#endif
#if !defined(__aarch64__) && !defined(__loongarch64) // loongarch64
    case __NR_getdents:    // EPERM not a valid errno.
#endif
    case __NR_getdents64:  // EPERM not a valid errno.
