        thread.thread_info.float_context.f32,
        context_.mipsel);
  }
#else
#error Port.
#endif

//----replace
        thread.thread_info.float_context.f32,
        context_.mipsel);
  }
#elif defined(ARCH_CPU_LOONG64)// loongarch64
  context_.architecture = kCPUArchitectureLOONGARCH64;// loongarch64
  context_.loongarch64 = &context_union_.loongarch64;// loongarch64
  InitializeCPUContextLOONGARCH64(// loongarch64
      thread.thread_info.thread_context.t64,// loongarch64
      thread.thread_info.float_context.f64,// loongarch64
      context_.loongarch64);// loongarch64
#else
#error Port.
#endif
