    return RestrictPrctl();

#if defined(__x86_64__) || defined(__arm__) || defined(__mips__) || \
    defined(__aarch64__)
  if (sysno == __NR_socketpair) {
    // Only allow AF_UNIX, PF_UNIX. Crash if anything else is seen.
    static_assert(AF_UNIX == PF_UNIX,

//----replace
    return RestrictPrctl();

#if defined(__x86_64__) || defined(__arm__) || defined(__mips__) || \
    defined(__aarch64__) || defined(__loongarch64)
  if (sysno == __NR_socketpair) {
    // Only allow AF_UNIX, PF_UNIX. Crash if anything else is seen.
    static_assert(AF_UNIX == PF_UNIX,
