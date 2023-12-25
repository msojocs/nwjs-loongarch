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
#elif defined(ARCH_CPU_LOONG64)
  context_.architecture = kCPUArchitectureLOONGARCH64;
  context_.loongarch64 = &context_union_.loongarch64;
  InitializeCPUContextLOONGARCH64(
      thread.thread_info.thread_context.t64,
      thread.thread_info.float_context.f64,
      context_.loongarch64);
#else
#error Port.
#endif
