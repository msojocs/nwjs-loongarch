    case __NR_recv:
#endif
#if defined(__x86_64__) || defined(__arm__) || defined(__mips__) || \
    defined(__aarch64__)
    case __NR_recvfrom:  // Could specify source.
    case __NR_recvmsg:   // Could specify source.
#endif

//----replace
    case __NR_recv:
#endif
#if defined(__x86_64__) || defined(__arm__) || defined(__mips__) || \
    defined(__aarch64__) || defined(__loongarch64)// loongarch64
    case __NR_recvfrom:  // Could specify source.
    case __NR_recvmsg:   // Could specify source.
#endif
