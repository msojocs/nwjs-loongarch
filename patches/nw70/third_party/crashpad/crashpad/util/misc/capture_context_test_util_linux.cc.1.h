  return context.uc_mcontext.pc;
#elif defined(ARCH_CPU_MIPS_FAMILY)
  return context.uc_mcontext.pc;
#endif
}


//----replace
  return context.uc_mcontext.pc;
#elif defined(ARCH_CPU_MIPS_FAMILY)
  return context.uc_mcontext.pc;
#elif defined(ARCH_CPU_LOONG64)
  return context.ucontext.uc_mcontext.__pc;
#endif
}

