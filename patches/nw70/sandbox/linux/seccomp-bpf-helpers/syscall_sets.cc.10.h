#endif
    case __NR_set_tid_address:
    case __NR_unshare:
#if !defined(__mips__) && !defined(__aarch64__)
    case __NR_vfork:
#endif
    default:

//----replace
#endif
    case __NR_set_tid_address:
    case __NR_unshare:
#if !defined(__mips__) && !defined(__aarch64__) && !defined(__loongarch64)// loongarch64
    case __NR_vfork:
#endif
    default:
