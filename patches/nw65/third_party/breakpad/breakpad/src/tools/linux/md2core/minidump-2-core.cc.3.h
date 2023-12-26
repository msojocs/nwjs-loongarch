  thread->mcontext.fpc_eir = rawregs->float_save.fir;
#endif
}
#else
#error "This code has not been ported to your platform yet"
#endif

//----replace
  thread->mcontext.fpc_eir = rawregs->float_save.fir;
#endif
}
#elif defined(__loongarch64) // loongarch64
ParseThreadRegisters(CrashedProcess::Thread* thread, // loongarch64
		     const MinidumpMemoryRange& range) { // loongarch64
  const MDRawContextLOONGARCH64* rawregs = range.GetData<MDRawContextLOONGARCH64>(0); // loongarch64
 // loongarch64
  for (int i = 0; i < MD_CONTEXT_LOONGARCH64_GPR_COUNT; ++i) // loongarch64
    thread->regs.regs[i] = rawregs->iregs[i]; // loongarch64
 // loongarch64
  thread->regs.csr_era = rawregs->csr_era; // loongarch64
 // loongarch64
  memcpy(thread->fpregs.fpr, rawregs->float_save.regs, 8 * 32); // loongarch64
  thread->fpregs.fcc = rawregs->float_save.fcc; // loongarch64
  thread->fpregs.fcsr = rawregs->float_save.fpcr; // loongarch64
} // loongarch64
#else
#error "This code has not been ported to your platform yet"
#endif
