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

#elif defined(__loongarch64) // loongarch64
 // loongarch64
uintptr_t ThreadInfo::GetInstructionPointer() const { // loongarch64
  return regs.csr_era; // loongarch64
} // loongarch64
 // loongarch64
void ThreadInfo::FillCPUContext(RawContextCPU* out) const { // loongarch64
  out->context_flags = MD_CONTEXT_LOONGARCH64_FULL; // loongarch64
 // loongarch64
  for (int i = 0; i < MD_CONTEXT_LOONGARCH64_GPR_COUNT; ++i) // loongarch64
    out->iregs[i] = regs.regs[i]; // loongarch64
 // loongarch64
  out->csr_era = regs.csr_era; // loongarch64
  my_memcpy(&out->float_save.regs, &fpregs.fpr, // loongarch64
	MD_FLOATINGSAVEAREA_LOONGARCH64_FPR_COUNT * 8); // loongarch64
  out->float_save.fcc = fpregs.fcc; // loongarch64
  out->float_save.fcsr = fpregs.fcsr; // loongarch64
} // loongarch64
 // loongarch64
#endif  // __loongarch64 // loongarch64
void ThreadInfo::GetGeneralPurposeRegisters(void** gp_regs, size_t* size) {
  assert(gp_regs || size);
#if defined(__mips__)
