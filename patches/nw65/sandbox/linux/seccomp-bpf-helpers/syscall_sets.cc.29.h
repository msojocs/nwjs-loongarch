#if defined(__x86_64__)
    case __NR_tuxcall:
#endif
#if !defined(__aarch64__)
    case __NR_vserver:
#endif
      return true;

//----replace
#if defined(__x86_64__)
    case __NR_tuxcall:
#endif
#if !defined(__aarch64__) && !defined(__loongarch64) // loongarch64
    case __NR_vserver:
#endif
      return true;
