}

#if defined(__x86_64__) || defined(__arm__) || defined(__aarch64__) || \
    (defined(ARCH_CPU_MIPS_FAMILY) && defined(ARCH_CPU_64_BITS))
bool SyscallSets::IsSystemVSemaphores(int sysno) {
  switch (sysno) {
    case __NR_semctl:

//----replace
}

#if defined(__x86_64__) || defined(__arm__) || defined(__aarch64__) || \
    (defined(ARCH_CPU_MIPS_FAMILY) && defined(ARCH_CPU_64_BITS)) || defined(__loongarch64) // loongarch64
bool SyscallSets::IsSystemVSemaphores(int sysno) {
  switch (sysno) {
    case __NR_semctl:
