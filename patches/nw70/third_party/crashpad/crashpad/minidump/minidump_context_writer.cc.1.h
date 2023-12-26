  return sizeof(context_);
}

}  // namespace crashpad

//----replace
  return sizeof(context_);
}

MinidumpContextLOONGARCH64Writer::MinidumpContextLOONGARCH64Writer()// loongarch64
    : MinidumpContextWriter(), context_() {// loongarch64
  context_.context_flags = kMinidumpContextLOONGARCH64;// loongarch64
}// loongarch64
// loongarch64
MinidumpContextLOONGARCH64Writer::~MinidumpContextLOONGARCH64Writer() = default;// loongarch64
// loongarch64
void MinidumpContextLOONGARCH64Writer::InitializeFromSnapshot(// loongarch64
    const CPUContextLOONGARCH64* context_snapshot) {// loongarch64
  DCHECK_EQ(state(), kStateMutable);// loongarch64
  DCHECK_EQ(context_.context_flags, kMinidumpContextLOONGARCH64);// loongarch64
// loongarch64
  context_.context_flags = kMinidumpContextLOONGARCH64All;// loongarch64
// loongarch64
  static_assert(sizeof(context_.regs) == sizeof(context_snapshot->regs),// loongarch64
                "GPRs size mismatch");// loongarch64
  memcpy(context_.regs, context_snapshot->regs, sizeof(context_.regs));// loongarch64
  context_.csr_era = context_snapshot->csr_era;// loongarch64
// loongarch64
  static_assert(sizeof(context_.fpregs) == sizeof(context_snapshot->fpregs),// loongarch64
                "FPRs size mismatch");// loongarch64
  memcpy(context_.fpregs.dregs,// loongarch64
         context_snapshot->fpregs.dregs,// loongarch64
         sizeof(context_.fpregs.dregs));// loongarch64
  context_.fcsr = context_snapshot->fcsr;// loongarch64
  context_.fcc = context_snapshot->fcc;// loongarch64
}// loongarch64
// loongarch64
bool MinidumpContextLOONGARCH64Writer::WriteObject(// loongarch64
    FileWriterInterface* file_writer) {// loongarch64
  DCHECK_EQ(state(), kStateWritable);// loongarch64
  return file_writer->Write(&context_, sizeof(context_));// loongarch64
}// loongarch64
// loongarch64
size_t MinidumpContextLOONGARCH64Writer::ContextSize() const {// loongarch64
  DCHECK_GE(state(), kStateFrozen);// loongarch64
  return sizeof(context_);// loongarch64
}// loongarch64
// loongarch64
}  // namespace crashpad
