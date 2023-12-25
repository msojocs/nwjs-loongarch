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
#elif defined(__loongarch64)
ParseThreadRegisters(CrashedProcess::Thread* thread,
		     const MinidumpMemoryRange& range) {
  const MDRawContextLOONGARCH64* rawregs = range.GetData<MDRawContextLOONGARCH64>(0);

  for (int i = 0; i < MD_CONTEXT_LOONGARCH64_GPR_COUNT; ++i)
    thread->regs.regs[i] = rawregs->iregs[i];

  thread->regs.csr_era = rawregs->csr_era;

  memcpy(thread->fpregs.fpr, rawregs->float_save.regs, 8 * 32);
  thread->fpregs.fcc = rawregs->float_save.fcc;
  thread->fpregs.fcsr = rawregs->float_save.fpcr;
}
#else
#error "This code has not been ported to your platform yet"
#endif
