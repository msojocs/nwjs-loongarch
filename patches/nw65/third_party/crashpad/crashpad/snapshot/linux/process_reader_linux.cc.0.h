#elif defined(ARCH_CPU_MIPS_FAMILY)
  stack_pointer = reader->Is64Bit() ? thread_info.thread_context.t64.regs[29]
                                    : thread_info.thread_context.t32.regs[29];
#else
#error Port.
#endif

//----replace
#elif defined(ARCH_CPU_MIPS_FAMILY)
  stack_pointer = reader->Is64Bit() ? thread_info.thread_context.t64.regs[29]
                                    : thread_info.thread_context.t32.regs[29];
#elif defined(ARCH_CPU_LOONG64) // loongarch64
  stack_pointer = thread_info.thread_context.t64.regs[3]; // loongarch64
#else
#error Port.
#endif
