    context_.mips64->fir = src->fir;

    memcpy(&context_.mips64->fpregs, &src->fpregs, sizeof(src->fpregs));
  } else {
    // Architecture is listed as "unknown".
    DLOG(ERROR) << "Unknown architecture";

//----replace
    context_.mips64->fir = src->fir;

    memcpy(&context_.mips64->fpregs, &src->fpregs, sizeof(src->fpregs));
  } else if (context_.architecture ==
             CPUArchitecture::kCPUArchitectureLOONGARCH64) {
    context_memory_.resize(sizeof(CPUContextLOONGARCH64));
    context_.loongarch64 =
        reinterpret_cast<CPUContextLOONGARCH64*>(context_memory_.data());
    const MinidumpContextLOONGARCH64* src =
        reinterpret_cast<const MinidumpContextLOONGARCH64*>(minidump_context.data());
    if (minidump_context.size() < sizeof(MinidumpContextLOONGARCH64)) {
      return false;
    }

    if (!(src->context_flags & kMinidumpContextLOONGARCH64)) {
      return false;
    }

    for (size_t i = 0; i < std::size(src->regs); i++) {
      context_.loongarch64->regs[i] = src->regs[i];
    }

    context_.loongarch64->csr_era = src->csr_era;
    context_.loongarch64->fcsr = src->fcsr;
    context_.loongarch64->fcc = src->fcc;

    memcpy(&context_.loongarch64->fpregs, &src->fpregs, sizeof(src->fpregs));
  } else {
    // Architecture is listed as "unknown".
    DLOG(ERROR) << "Unknown architecture";
