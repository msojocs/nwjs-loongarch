  return context.uc_mcontext.sp;
#elif defined(ARCH_CPU_MIPS_FAMILY)
  return context.uc_mcontext.gregs[29];
#endif
}


//----replace
  return context.uc_mcontext.sp;
#elif defined(ARCH_CPU_MIPS_FAMILY)
  return context.uc_mcontext.gregs[29];
#elif defined(ARCH_CPU_LOONG64) // loongarch64
  return context.ucontext.uc_mcontext.__gregs[3]; // loongarch64
#endif
}

