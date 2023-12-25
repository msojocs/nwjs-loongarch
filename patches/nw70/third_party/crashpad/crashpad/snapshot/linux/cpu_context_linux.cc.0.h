  context->fpcr = float_context.fpcr;
}

#endif  // ARCH_CPU_X86_FAMILY

}  // namespace internal

//----replace
  context->fpcr = float_context.fpcr;
}

#elif defined(ARCH_CPU_LOONG64)

void InitializeCPUContextLOONGARCH64_NoFloatingPoint(
    const ThreadContext::t64_t& thread_context,
    CPUContextLOONGARCH64* context) {
  static_assert(sizeof(context->regs) == sizeof(thread_context.regs),
                "gpr context size mismtach");
  memcpy(context->regs, thread_context.regs, sizeof(context->regs));
  context->csr_era = thread_context.csr_era;

  memset(&context->fpregs, 0, sizeof(context->fpregs));
  context->fcc = 0;
  context->fcsr = 0;
}

void InitializeCPUContextLOONGARCH64_OnlyFPU(
    const FloatContext::f64_t& float_context,
    CPUContextLOONGARCH64* context) {
  static_assert(sizeof(context->fpregs) == sizeof(float_context.fpregs),
                "fpu context size mismatch");
  memcpy(&context->fpregs, &float_context.fpregs, sizeof(context->fpregs));
  context->fcc = float_context.fcc;
  context->fcsr = float_context.fcsr;
}

void InitializeCPUContextLOONGARCH64(
    const ThreadContext::t64_t& thread_context,
    const FloatContext::f64_t& float_context,
    CPUContextLOONGARCH64* context) {
  InitializeCPUContextLOONGARCH64_NoFloatingPoint(thread_context, context);

  InitializeCPUContextLOONGARCH64_OnlyFPU(float_context, context);
}

#endif  // ARCH_CPU_X86_FAMILY

}  // namespace internal
