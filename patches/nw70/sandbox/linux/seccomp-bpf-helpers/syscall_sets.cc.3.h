
bool SyscallSets::IsAllowedFileSystemAccessViaFd(int sysno) {
  switch (sysno) {
    case __NR_fstat:
    case __NR_ftruncate:
#if defined(__i386__) || defined(__arm__) || \
    (defined(ARCH_CPU_MIPS_FAMILY) && defined(ARCH_CPU_32_BITS))
    case __NR_fstat64:
    case __NR_ftruncate64:
#endif
      return true;
// TODO(jln): these should be denied gracefully as well (moved below).

//----replace

bool SyscallSets::IsAllowedFileSystemAccessViaFd(int sysno) {
  switch (sysno) {
#if !defined(__loongarch64)
    case __NR_fstat:
#endif
    case __NR_ftruncate:
#if defined(__i386__) || defined(__arm__) || \
    (defined(ARCH_CPU_MIPS_FAMILY) && defined(ARCH_CPU_32_BITS))
    case __NR_fstat64:
    case __NR_ftruncate64:
#endif
#if defined(__loongarch64)
    case __NR_statx:
#endif
      return true;
// TODO(jln): these should be denied gracefully as well (moved below).
