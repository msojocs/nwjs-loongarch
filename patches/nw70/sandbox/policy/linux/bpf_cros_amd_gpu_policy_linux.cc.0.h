    case __NR_sched_setscheduler:
    case __NR_sysinfo:
    case __NR_uname:
#if !defined(__aarch64__)
    case __NR_readlink:
    case __NR_stat:
#endif

//----replace
    case __NR_sched_setscheduler:
    case __NR_sysinfo:
    case __NR_uname:
#if !defined(__aarch64__) && !defined(__loongarch64)// loongarch64
    case __NR_readlink:
    case __NR_stat:
#endif
