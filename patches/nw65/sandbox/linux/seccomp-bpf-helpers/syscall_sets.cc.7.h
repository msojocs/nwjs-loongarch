    case __NR_rt_sigqueueinfo:
    case __NR_rt_sigsuspend:
    case __NR_rt_tgsigqueueinfo:
#if !defined(__aarch64__)
    case __NR_signalfd:
#endif
    case __NR_signalfd4:

//----replace
    case __NR_rt_sigqueueinfo:
    case __NR_rt_sigsuspend:
    case __NR_rt_tgsigqueueinfo:
#if !defined(__aarch64__) && !defined(__loongarch64) // loongarch64
    case __NR_signalfd:
#endif
    case __NR_signalfd4:
