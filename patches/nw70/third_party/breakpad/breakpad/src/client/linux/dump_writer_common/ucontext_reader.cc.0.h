      MD_FLOATINGSAVEAREA_ARM64_FPR_COUNT * 16);
}

#elif defined(__mips__)

uintptr_t UContextReader::GetStackPointer(const ucontext_t* uc) {

//----replace
      MD_FLOATINGSAVEAREA_ARM64_FPR_COUNT * 16);
}

#elif defined(__loongarch64)// loongarch64
// loongarch64
uintptr_t UContextReader::GetStackPointer(const ucontext_t* uc) {// loongarch64
  return uc->uc_mcontext.__gregs[MD_CONTEXT_LOONGARCH64_REG_SP];// loongarch64
}// loongarch64
// loongarch64
uintptr_t UContextReader::GetInstructionPointer(const ucontext_t* uc) {// loongarch64
  return uc->uc_mcontext.__pc;// loongarch64
}// loongarch64
// loongarch64
void UContextReader::FillCPUContext(RawContextCPU* out, const ucontext_t* uc) {// loongarch64
  out->context_flags = MD_CONTEXT_LOONGARCH64_FULL;// loongarch64
// loongarch64
  for (int i = 0; i < MD_CONTEXT_LOONGARCH64_GPR_COUNT; ++i)// loongarch64
    out->iregs[i] = uc->uc_mcontext.__gregs[i];// loongarch64
// loongarch64
  out->csr_era = uc->uc_mcontext.__pc;// loongarch64
}// loongarch64
#elif defined(__mips__)

uintptr_t UContextReader::GetStackPointer(const ucontext_t* uc) {
