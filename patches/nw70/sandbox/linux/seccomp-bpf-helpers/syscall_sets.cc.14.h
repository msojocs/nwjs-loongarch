    case __NR_mincore:
    case __NR_mlockall:
#if defined(__i386__) || defined(__x86_64__) || defined(__mips__) || \
    defined(__aarch64__)
    case __NR_mmap:
#endif
#if defined(__i386__) || defined(__arm__) || \

//----replace
    case __NR_mincore:
    case __NR_mlockall:
#if defined(__i386__) || defined(__x86_64__) || defined(__mips__) || \
    defined(__aarch64__) || defined(__loongarch64)// loongarch64
    case __NR_mmap:
#endif
#if defined(__i386__) || defined(__arm__) || \
