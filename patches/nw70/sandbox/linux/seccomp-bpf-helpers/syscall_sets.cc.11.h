
bool SyscallSets::IsAllowedEpoll(int sysno) {
  switch (sysno) {
#if !defined(__aarch64__)
    case __NR_epoll_create:
    case __NR_epoll_wait:
#endif

//----replace

bool SyscallSets::IsAllowedEpoll(int sysno) {
  switch (sysno) {
#if !defined(__aarch64__) && !defined(__loongarch64)// loongarch64
    case __NR_epoll_create:
    case __NR_epoll_wait:
#endif
