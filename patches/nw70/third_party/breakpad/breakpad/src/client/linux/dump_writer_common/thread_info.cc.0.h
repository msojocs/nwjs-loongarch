  out->float_save.fir = mcontext.fpc_eir;
#endif
}
#endif  // __mips__

void ThreadInfo::GetGeneralPurposeRegisters(void** gp_regs, size_t* size) {
  assert(gp_regs || size);
#if defined(__mips__)

//----replace
  out->float_save.fir = mcontext.fpc_eir;
#endif
}

#elif defined(__loongarch64)

uintptr_t ThreadInfo::GetInstructionPointer() const {
  return regs.csr_era;
}

void ThreadInfo::FillCPUContext(RawContextCPU* out) const {
  out->context_flags = MD_CONTEXT_LOONGARCH64_FULL;

  for (int i = 0; i < MD_CONTEXT_LOONGARCH64_GPR_COUNT; ++i)
    out->iregs[i] = regs.regs[i];

  out->csr_era = regs.csr_era;
  my_memcpy(&out->float_save.regs, &fpregs.fpr,
	MD_FLOATINGSAVEAREA_LOONGARCH64_FPR_COUNT * 8);
  out->float_save.fcc = fpregs.fcc;
  out->float_save.fcsr = fpregs.fcsr;
}

#endif  // __loongarch64
void ThreadInfo::GetGeneralPurposeRegisters(void** gp_regs, size_t* size) {
  assert(gp_regs || size);
#if defined(__mips__)
