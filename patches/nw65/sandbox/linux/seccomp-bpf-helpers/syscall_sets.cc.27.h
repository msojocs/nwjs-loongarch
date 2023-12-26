
bool SyscallSets::IsAnySystemV(int sysno) {
#if defined(__x86_64__) || defined(__arm__) || defined(__aarch64__) || \
    (defined(ARCH_CPU_MIPS_FAMILY) && defined(ARCH_CPU_64_BITS))
  return IsSystemVMessageQueue(sysno) || IsSystemVSemaphores(sysno) ||
         IsSystemVSharedMemory(sysno);

//----replace

bool SyscallSets::IsAnySystemV(int sysno) {
#if defined(__x86_64__) || defined(__arm__) || defined(__aarch64__) || \
    defined(__loongarch64) || \
    (defined(ARCH_CPU_MIPS_FAMILY) && defined(ARCH_CPU_64_BITS))
  return IsSystemVMessageQueue(sysno) || IsSystemVSemaphores(sysno) ||
         IsSystemVSharedMemory(sysno);
