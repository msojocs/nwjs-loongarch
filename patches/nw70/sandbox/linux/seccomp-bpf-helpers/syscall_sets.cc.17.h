    case __NR_send:
#endif
#if defined(__x86_64__) || defined(__arm__) || defined(__mips__) || \
    defined(__aarch64__)
    case __NR_sendmsg:  // Could specify destination.
    case __NR_sendto:   // Could specify destination.
#endif

//----replace
    case __NR_send:
#endif
#if defined(__x86_64__) || defined(__arm__) || defined(__mips__) || \
    defined(__aarch64__) || defined(__loongarch64)
    case __NR_sendmsg:  // Could specify destination.
    case __NR_sendto:   // Could specify destination.
#endif
