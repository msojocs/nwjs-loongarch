  switch (sysno) {
    case __NR_acct:  // Privileged.
#if defined(__i386__) || defined(__x86_64__) || defined(__mips__) || \
    defined(__aarch64__)
    case __NR_getrlimit:
#endif
#if defined(__i386__) || defined(__arm__)

//----replace
  switch (sysno) {
    case __NR_acct:  // Privileged.
#if defined(__i386__) || defined(__x86_64__) || defined(__mips__) || \
    defined(__aarch64__) // loongarch64
    case __NR_getrlimit:
#endif
#if defined(__i386__) || defined(__arm__)
