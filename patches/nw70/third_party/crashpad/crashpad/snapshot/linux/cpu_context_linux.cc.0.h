  context->fpcr = float_context.fpcr;
}

#endif  // ARCH_CPU_X86_FAMILY

}  // namespace internal

//----replace
  context->fpcr = float_context.fpcr;
}

#elif defined(ARCH_CPU_LOONG64)// loongarch64
// loongarch64
void InitializeCPUContextLOONGARCH64_NoFloatingPoint(// loongarch64
    const ThreadContext::t64_t& thread_context,// loongarch64
    CPUContextLOONGARCH64* context) {// loongarch64
  static_assert(sizeof(context->regs) == sizeof(thread_context.regs),// loongarch64
                "gpr context size mismtach");// loongarch64
  memcpy(context->regs, thread_context.regs, sizeof(context->regs));// loongarch64
  context->csr_era = thread_context.csr_era;// loongarch64
// loongarch64
  memset(&context->fpregs, 0, sizeof(context->fpregs));// loongarch64
  context->fcc = 0;// loongarch64
  context->fcsr = 0;// loongarch64
}// loongarch64
// loongarch64
void InitializeCPUContextLOONGARCH64_OnlyFPU(// loongarch64
    const FloatContext::f64_t& float_context,// loongarch64
    CPUContextLOONGARCH64* context) {// loongarch64
  static_assert(sizeof(context->fpregs) == sizeof(float_context.fpregs),// loongarch64
                "fpu context size mismatch");// loongarch64
  memcpy(&context->fpregs, &float_context.fpregs, sizeof(context->fpregs));// loongarch64
  context->fcc = float_context.fcc;// loongarch64
  context->fcsr = float_context.fcsr;// loongarch64
}// loongarch64
// loongarch64
void InitializeCPUContextLOONGARCH64(// loongarch64
    const ThreadContext::t64_t& thread_context,// loongarch64
    const FloatContext::f64_t& float_context,// loongarch64
    CPUContextLOONGARCH64* context) {// loongarch64
  InitializeCPUContextLOONGARCH64_NoFloatingPoint(thread_context, context);// loongarch64
// loongarch64
  InitializeCPUContextLOONGARCH64_OnlyFPU(float_context, context);// loongarch64
}// loongarch64
// loongarch64
#endif  // ARCH_CPU_X86_FAMILY

}  // namespace internal
