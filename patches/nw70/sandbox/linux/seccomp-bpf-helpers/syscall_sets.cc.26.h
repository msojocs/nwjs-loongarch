#endif

#if defined(__x86_64__) || defined(__arm__) || defined(__aarch64__) || \
    (defined(ARCH_CPU_MIPS_FAMILY) && defined(ARCH_CPU_64_BITS))
bool SyscallSets::IsSystemVMessageQueue(int sysno) {
  switch (sysno) {

//----replace
#endif

#if defined(__x86_64__) || defined(__arm__) || defined(__aarch64__) || \
    defined(__loongarch64) || \
    (defined(ARCH_CPU_MIPS_FAMILY) && defined(ARCH_CPU_64_BITS))
bool SyscallSets::IsSystemVMessageQueue(int sysno) {
  switch (sysno) {
