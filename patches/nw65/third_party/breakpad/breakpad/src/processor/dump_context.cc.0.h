  return context_.ctx_mips;
}

bool DumpContext::GetInstructionPointer(uint64_t* ip) const {
  BPLOG_IF(ERROR, !ip) << "DumpContext::GetInstructionPointer requires |ip|";
  assert(ip);

//----replace
  return context_.ctx_mips;
}

const MDRawContextLOONGARCH64* DumpContext::GetContextLOONGARCH64() const { // loongarch64
  if (GetContextCPU() != MD_CONTEXT_LOONGARCH64) { // loongarch64
    BPLOG(ERROR) << "DumpContext cannot get LOONGARCH64 context"; // loongarch64
    return NULL; // loongarch64
  } // loongarch64
 // loongarch64
  return context_.loongarch64; // loongarch64
} // loongarch64
 // loongarch64
bool DumpContext::GetInstructionPointer(uint64_t* ip) const {
  BPLOG_IF(ERROR, !ip) << "DumpContext::GetInstructionPointer requires |ip|";
  assert(ip);
