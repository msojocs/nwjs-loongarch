      MD_FLOATINGSAVEAREA_ARM64_FPR_COUNT * 16);
}

#elif defined(__mips__)

uintptr_t UContextReader::GetStackPointer(const ucontext_t* uc) {

//----replace
      MD_FLOATINGSAVEAREA_ARM64_FPR_COUNT * 16);
}

#elif defined(__loongarch64)

uintptr_t UContextReader::GetStackPointer(const ucontext_t* uc) {
  return uc->uc_mcontext.__gregs[MD_CONTEXT_LOONGARCH64_REG_SP];
}

uintptr_t UContextReader::GetInstructionPointer(const ucontext_t* uc) {
  return uc->uc_mcontext.__pc;
}

void UContextReader::FillCPUContext(RawContextCPU* out, const ucontext_t* uc) {
  out->context_flags = MD_CONTEXT_LOONGARCH64_FULL;

  for (int i = 0; i < MD_CONTEXT_LOONGARCH64_GPR_COUNT; ++i)
    out->iregs[i] = uc->uc_mcontext.__gregs[i];

  out->csr_era = uc->uc_mcontext.__pc;
}
#elif defined(__mips__)

uintptr_t UContextReader::GetStackPointer(const ucontext_t* uc) {
