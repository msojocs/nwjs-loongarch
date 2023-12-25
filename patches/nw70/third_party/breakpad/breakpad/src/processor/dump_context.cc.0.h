  return context_.ctx_mips;
}

bool DumpContext::GetInstructionPointer(uint64_t* ip) const {
  BPLOG_IF(ERROR, !ip) << "DumpContext::GetInstructionPointer requires |ip|";
  assert(ip);

//----replace
  return context_.ctx_mips;
}

const MDRawContextLOONGARCH64* DumpContext::GetContextLOONGARCH64() const {
  if (GetContextCPU() != MD_CONTEXT_LOONGARCH64) {
    BPLOG(ERROR) << "DumpContext cannot get LOONGARCH64 context";
    return NULL;
  }

  return context_.loongarch64;
}

bool DumpContext::GetInstructionPointer(uint64_t* ip) const {
  BPLOG_IF(ERROR, !ip) << "DumpContext::GetInstructionPointer requires |ip|";
  assert(ip);
