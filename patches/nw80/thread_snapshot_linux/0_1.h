  InitializeCPUContextRISCV64(thread.thread_info.thread_context.t64,
                              thread.thread_info.float_context.f64,
                              context_.riscv64);
#elif defined(ARCH_CPU_LOONGARCH64)
  context_.architecture = kCPUArchitectureLOONGARCH64;
  context_.loongarch64 = &context_union_.loongarch64;
  InitializeCPUContextLOONGARCH64(
      thread.thread_info.thread_context.t64,
      thread.thread_info.float_context.f64,
      context_.loongarch64);
// loongarch
#else
#error Port.