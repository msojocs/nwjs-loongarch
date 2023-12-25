bool SyscallSets::IsInotify(int sysno) {
  switch (sysno) {
    case __NR_inotify_add_watch:
#if !defined(__aarch64__)
    case __NR_inotify_init:
#endif
    case __NR_inotify_init1:

//----replace
bool SyscallSets::IsInotify(int sysno) {
  switch (sysno) {
    case __NR_inotify_add_watch:
#if !defined(__aarch64__) && !defined(__loongarch64)
    case __NR_inotify_init:
#endif
    case __NR_inotify_init1:
