  InitializeCPUContextRISCV64(thread.thread_info.thread_context.t64,
                              thread.thread_info.float_context.f64,
                              context_.riscv64);
#else
#error Port.