bool SyscallSets::IsProcessGroupOrSession(int sysno) {
  switch (sysno) {
    case __NR_setpgid:
#if !defined(__aarch64__)
    case __NR_getpgrp:
#endif
    case __NR_setsid:

//----replace
bool SyscallSets::IsProcessGroupOrSession(int sysno) {
  switch (sysno) {
    case __NR_setpgid:
#if !defined(__aarch64__) && !defined(__loongarch64) // loongarch64
    case __NR_getpgrp:
#endif
    case __NR_setsid:
