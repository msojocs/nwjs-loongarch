  memset(context->uc_mcontext.__reserved,
         0,
         sizeof(context->uc_mcontext.__reserved));
#endif

  siginfo_t siginfo;

//----replace
  memset(context->uc_mcontext.__reserved,
         0,
         sizeof(context->uc_mcontext.__reserved));
#elif defined(ARCH_CPU_LOONG64)
  memset(context->uc_mcontext.__extcontext,
         0,
         sizeof(context->uc_mcontext.__extcontext));
#endif

  siginfo_t siginfo;
