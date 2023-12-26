  }
#endif

#if !defined(__ARM_EABI__) && !defined(__aarch64__) && !defined(__mips__)
  // FPU state is not part of ARM EABI ucontext_t.
  memcpy(&context.float_state, context.context.uc_mcontext.fpregs,
         sizeof(context.float_state));

//----replace
  }
#endif

#if !defined(__ARM_EABI__) && !defined(__aarch64__) && !defined(__mips__) && !defined(__loongarch64)// loongarch64
  // FPU state is not part of ARM EABI ucontext_t.
  memcpy(&context.float_state, context.context.uc_mcontext.fpregs,
         sizeof(context.float_state));
