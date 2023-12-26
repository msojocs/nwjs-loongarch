bool SyscallSets::IsAllowedBasicScheduler(int sysno) {
  switch (sysno) {
    case __NR_sched_yield:
#if !defined(__aarch64__)
    case __NR_pause:
#endif
    case __NR_nanosleep:

//----replace
bool SyscallSets::IsAllowedBasicScheduler(int sysno) {
  switch (sysno) {
    case __NR_sched_yield:
#if !defined(__aarch64__) && !defined(__loongarch64) // loongarch64
    case __NR_pause:
#endif
    case __NR_nanosleep:
