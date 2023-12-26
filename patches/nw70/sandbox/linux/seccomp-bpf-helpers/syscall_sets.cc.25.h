#endif

#if defined(__i386__) || defined(__x86_64__) || defined(__arm__) || \
    defined(__aarch64__) ||                                         \
    (defined(ARCH_CPU_MIPS_FAMILY) && defined(ARCH_CPU_64_BITS))
// These give a lot of ambient authority and bypass the setuid sandbox.
bool SyscallSets::IsSystemVSharedMemory(int sysno) {

//----replace
#endif

#if defined(__i386__) || defined(__x86_64__) || defined(__arm__) || \
    defined(__aarch64__) || defined(__loongarch64) ||               \// loongarch64
    (defined(ARCH_CPU_MIPS_FAMILY) && defined(ARCH_CPU_64_BITS))
// These give a lot of ambient authority and bypass the setuid sandbox.
bool SyscallSets::IsSystemVSharedMemory(int sysno) {
