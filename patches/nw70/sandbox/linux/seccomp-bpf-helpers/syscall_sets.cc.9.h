      return true;
    case __NR_clone:  // Should be parameter-restricted.
    case __NR_setns:  // Privileged.
#if !defined(__aarch64__)
    case __NR_fork:
#endif
#if defined(__i386__) || defined(__x86_64__)

//----replace
      return true;
    case __NR_clone:  // Should be parameter-restricted.
    case __NR_setns:  // Privileged.
#if !defined(__aarch64__) && !defined(__loongarch64)
    case __NR_fork:
#endif
#if defined(__i386__) || defined(__x86_64__)
