
bool SyscallSets::IsAllowedGetOrModifySocket(int sysno) {
  switch (sysno) {
#if !defined(__aarch64__)
    case __NR_pipe:
#endif
    case __NR_pipe2:
      return true;
    default:
#if defined(__x86_64__) || defined(__arm__) || defined(__mips__) || \
    defined(__aarch64__)
    case __NR_socketpair:  // We will want to inspect its argument.
#endif
      return false;

//----replace

bool SyscallSets::IsAllowedGetOrModifySocket(int sysno) {
  switch (sysno) {
#if !defined(__aarch64__) && !defined(__loongarch64)
    case __NR_pipe:
#endif
    case __NR_pipe2:
      return true;
    default:
#if defined(__x86_64__) || defined(__arm__) || defined(__mips__) || \
    defined(__aarch64__) || defined(__loongarch64)
    case __NR_socketpair:  // We will want to inspect its argument.
#endif
      return false;
