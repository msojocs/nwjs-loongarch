#if defined(ARCH_CPU_X86_FAMILY) || defined(ARCH_CPU_ARM_FAMILY) || \
    defined(ARCH_CPU_MIPS_FAMILY)
  // The stack grows downward.
//----replace
#if defined(ARCH_CPU_X86_FAMILY) || defined(ARCH_CPU_ARM_FAMILY) || \
    defined(ARCH_CPU_MIPS_FAMILY) || defined(ARCH_CPU_LOONGARCH_FAMILY)
  // The stack grows downward.