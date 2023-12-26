    context_.mips64->fir = src->fir;

    memcpy(&context_.mips64->fpregs, &src->fpregs, sizeof(src->fpregs));
  } else {
    // Architecture is listed as "unknown".
    DLOG(ERROR) << "Unknown architecture";

//----replace
    context_.mips64->fir = src->fir;

    memcpy(&context_.mips64->fpregs, &src->fpregs, sizeof(src->fpregs));
  } else if (context_.architecture ==// loongarch64
             CPUArchitecture::kCPUArchitectureLOONGARCH64) {// loongarch64
    context_memory_.resize(sizeof(CPUContextLOONGARCH64));// loongarch64
    context_.loongarch64 =// loongarch64
        reinterpret_cast<CPUContextLOONGARCH64*>(context_memory_.data());// loongarch64
    const MinidumpContextLOONGARCH64* src =// loongarch64
        reinterpret_cast<const MinidumpContextLOONGARCH64*>(minidump_context.data());// loongarch64
    if (minidump_context.size() < sizeof(MinidumpContextLOONGARCH64)) {// loongarch64
      return false;// loongarch64
    }// loongarch64
// loongarch64
    if (!(src->context_flags & kMinidumpContextLOONGARCH64)) {// loongarch64
      return false;// loongarch64
    }// loongarch64
// loongarch64
    for (size_t i = 0; i < std::size(src->regs); i++) {// loongarch64
      context_.loongarch64->regs[i] = src->regs[i];// loongarch64
    }// loongarch64
// loongarch64
    context_.loongarch64->csr_era = src->csr_era;// loongarch64
    context_.loongarch64->fcsr = src->fcsr;// loongarch64
    context_.loongarch64->fcc = src->fcc;// loongarch64
// loongarch64
    memcpy(&context_.loongarch64->fpregs, &src->fpregs, sizeof(src->fpregs));// loongarch64
  } else {
    // Architecture is listed as "unknown".
    DLOG(ERROR) << "Unknown architecture";
