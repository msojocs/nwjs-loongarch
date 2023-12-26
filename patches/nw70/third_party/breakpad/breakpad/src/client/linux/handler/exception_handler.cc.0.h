    memcpy(&g_crash_context_.float_state, fp_ptr,
           sizeof(g_crash_context_.float_state));
  }
#elif !defined(__ARM_EABI__) && !defined(__mips__)
  // FP state is not part of user ABI on ARM Linux.
  // In case of MIPS Linux FP state is already part of ucontext_t
  // and 'float_state' is not a member of CrashContext.

//----replace
    memcpy(&g_crash_context_.float_state, fp_ptr,
           sizeof(g_crash_context_.float_state));
  }
#elif !defined(__ARM_EABI__) && !defined(__mips__) && !defined(__loongarch64)// loongarch64
  // FP state is not part of user ABI on ARM Linux.
  // In case of MIPS Linux FP state is already part of ucontext_t
  // and 'float_state' is not a member of CrashContext.
