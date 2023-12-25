  switch (sysno) {
    case __NR_close:
    case __NR_dup:
#if !defined(__aarch64__)
    case __NR_dup2:
#endif
    case __NR_dup3:
#if defined(__x86_64__) || defined(__arm__) || defined(__mips__) || \
    defined(__aarch64__)
    case __NR_shutdown:
#endif
      return true;

//----replace
  switch (sysno) {
    case __NR_close:
    case __NR_dup:
#if !defined(__aarch64__) && !defined(__loongarch64)
    case __NR_dup2:
#endif
    case __NR_dup3:
#if defined(__x86_64__) || defined(__arm__) || defined(__mips__) || \
    defined(__aarch64__) || defined(__loongarch64)
    case __NR_shutdown:
#endif
      return true;
