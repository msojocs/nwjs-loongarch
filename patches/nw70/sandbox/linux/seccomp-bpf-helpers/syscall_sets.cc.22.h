
bool SyscallSets::IsGlobalSystemStatus(int sysno) {
  switch (sysno) {
#if !defined(__aarch64__)
    case __NR__sysctl:
    case __NR_sysfs:
#endif

//----replace

bool SyscallSets::IsGlobalSystemStatus(int sysno) {
  switch (sysno) {
#if !defined(__aarch64__) && !defined(__loongarch64)// loongarch64
    case __NR__sysctl:
    case __NR_sysfs:
#endif
