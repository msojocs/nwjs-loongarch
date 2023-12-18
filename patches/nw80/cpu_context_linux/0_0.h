  memcpy(context->fpregs, float_context.fpregs, sizeof(context->fpregs));
  context->fcsr = float_context.fcsr;
}

#endif  // ARCH_CPU_X86_FAMILY