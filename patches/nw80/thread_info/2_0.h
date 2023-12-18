#elif defined(ARCH_CPU_MIPS_FAMILY)
// No appropriate NativeThreadsContext type available for MIPS
#else
#error Port.
#endif  // ARCH_CPU_X86_FAMILY || ARCH_CPU_ARM64 || ARCH_CPU_RISCV64

#if !defined(ARCH_CPU_MIPS_FAMILY)