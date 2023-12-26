    case __NR_getcpu:
    case __NR_mbind:
#if defined(__i386__) || defined(__x86_64__) || defined(__mips__) || \
    defined(__aarch64__)
    case __NR_migrate_pages:
#endif
    case __NR_move_pages:

//----replace
    case __NR_getcpu:
    case __NR_mbind:
#if defined(__i386__) || defined(__x86_64__) || defined(__mips__) || \
    defined(__aarch64__) || defined(__loongarch64)// loongarch64
    case __NR_migrate_pages:
#endif
    case __NR_move_pages:
