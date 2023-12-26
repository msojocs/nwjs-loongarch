    return RestrictFcntlCommands();
#endif

#if !defined(__aarch64__)
  // fork() is never used as a system call (clone() is used instead), but we
  // have seen it in fallback code on Android.
  if (sysno == __NR_fork) {

//----replace
    return RestrictFcntlCommands();
#endif

#if !defined(__aarch64__) && !defined(__loongarch__)// loongarch64
  // fork() is never used as a system call (clone() is used instead), but we
  // have seen it in fallback code on Android.
  if (sysno == __NR_fork) {
