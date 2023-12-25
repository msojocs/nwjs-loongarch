  pid_t pid = -1;
  alignas(16) char stack_buf[PTHREAD_STACK_MIN];
#if defined(ARCH_CPU_X86_FAMILY) || defined(ARCH_CPU_ARM_FAMILY) || \
    defined(ARCH_CPU_MIPS_FAMILY)
  // The stack grows downward.
  void* stack = stack_buf + sizeof(stack_buf);
#else

//----replace
  pid_t pid = -1;
  alignas(16) char stack_buf[PTHREAD_STACK_MIN];
#if defined(ARCH_CPU_X86_FAMILY) || defined(ARCH_CPU_ARM_FAMILY) || \
    defined(ARCH_CPU_MIPS_FAMILY) || defined(ARCH_CPU_LOONG_FAMILY)
  // The stack grows downward.
  void* stack = stack_buf + sizeof(stack_buf);
#else
