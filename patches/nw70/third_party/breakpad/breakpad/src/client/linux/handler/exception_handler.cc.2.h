#elif defined(__mips__)
  context.siginfo.si_addr =
      reinterpret_cast<void*>(context.context.uc_mcontext.pc);
#else
#error "This code has not been ported to your platform yet."
#endif

//----replace
#elif defined(__mips__)
  context.siginfo.si_addr =
      reinterpret_cast<void*>(context.context.uc_mcontext.pc);
#elif defined(__loongarch64)
  context.siginfo.si_addr = 
      reinterpret_cast<void*>(context.context.uc_mcontext.__pc);
#else
#error "This code has not been ported to your platform yet."
#endif
