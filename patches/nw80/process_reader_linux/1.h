#elif defined(ARCH_CPU_RISCV64)
  stack_pointer = thread_info.thread_context.t64.regs[1];
#else
#error Port.
//----replace
#elif defined(ARCH_CPU_RISCV64)
  stack_pointer = thread_info.thread_context.t64.regs[1];
#elif defined(ARCH_CPU_LOONGARCH64)
  stack_pointer = thread_info.thread_context.t64.regs[3];
#else
#error Port.