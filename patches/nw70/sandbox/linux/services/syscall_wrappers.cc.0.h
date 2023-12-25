#if defined(ARCH_CPU_X86_64)
  return syscall(__NR_clone, flags, child_stack, ptid, ctid, tls);
#elif defined(ARCH_CPU_X86) || defined(ARCH_CPU_ARM_FAMILY) || \
    defined(ARCH_CPU_MIPS_FAMILY)
  // CONFIG_CLONE_BACKWARDS defined.
  return syscall(__NR_clone, flags, child_stack, ptid, tls, ctid);
#endif

//----replace
#if defined(ARCH_CPU_X86_64)
  return syscall(__NR_clone, flags, child_stack, ptid, ctid, tls);
#elif defined(ARCH_CPU_X86) || defined(ARCH_CPU_ARM_FAMILY) || \
    defined(ARCH_CPU_MIPS_FAMILY) || defined(ARCH_CPU_LOONG_FAMILY)
  // CONFIG_CLONE_BACKWARDS defined.
  return syscall(__NR_clone, flags, child_stack, ptid, tls, ctid);
#endif
