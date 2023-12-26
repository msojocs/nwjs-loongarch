
bool SyscallSets::IsEventFd(int sysno) {
  switch (sysno) {
#if !defined(__aarch64__)
    case __NR_eventfd:
#endif
    case __NR_eventfd2:

//----replace

bool SyscallSets::IsEventFd(int sysno) {
  switch (sysno) {
#if !defined(__aarch64__) && !defined(__loongarch64) // loongarch64
    case __NR_eventfd:
#endif
    case __NR_eventfd2:
