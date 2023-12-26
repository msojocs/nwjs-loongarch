  context_.ctx_mips = ctx_mips;
}

void DumpContext::FreeContext() {
  switch (GetContextCPU()) {
    case MD_CONTEXT_X86:

//----replace
  context_.ctx_mips = ctx_mips;
}

void DumpContext::SetContextLOONGARCH64(MDRawContextLOONGARCH64* loongarch64) {// loongarch64
  context_.loongarch64 = loongarch64;// loongarch64
}// loongarch64
// loongarch64
void DumpContext::FreeContext() {
  switch (GetContextCPU()) {
    case MD_CONTEXT_X86:
