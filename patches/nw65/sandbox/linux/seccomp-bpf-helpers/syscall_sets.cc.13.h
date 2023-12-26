bool SyscallSets::IsDeniedGetOrModifySocket(int sysno) {
  switch (sysno) {
#if defined(__x86_64__) || defined(__arm__) || defined(__mips__) || \
    defined(__aarch64__)
    case __NR_accept:
    case __NR_accept4:
    case __NR_bind:

//----replace
bool SyscallSets::IsDeniedGetOrModifySocket(int sysno) {
  switch (sysno) {
#if defined(__x86_64__) || defined(__arm__) || defined(__mips__) || \
    defined(__aarch64__) || defined(__loongarch64) // loongarch64
    case __NR_accept:
    case __NR_accept4:
    case __NR_bind:
