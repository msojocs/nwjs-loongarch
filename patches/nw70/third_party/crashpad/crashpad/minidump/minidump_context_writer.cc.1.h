  return sizeof(context_);
}

}  // namespace crashpad

//----replace
  return sizeof(context_);
}

MinidumpContextLOONGARCH64Writer::MinidumpContextLOONGARCH64Writer()
    : MinidumpContextWriter(), context_() {
  context_.context_flags = kMinidumpContextLOONGARCH64;
}

MinidumpContextLOONGARCH64Writer::~MinidumpContextLOONGARCH64Writer() = default;

void MinidumpContextLOONGARCH64Writer::InitializeFromSnapshot(
    const CPUContextLOONGARCH64* context_snapshot) {
  DCHECK_EQ(state(), kStateMutable);
  DCHECK_EQ(context_.context_flags, kMinidumpContextLOONGARCH64);

  context_.context_flags = kMinidumpContextLOONGARCH64All;

  static_assert(sizeof(context_.regs) == sizeof(context_snapshot->regs),
                "GPRs size mismatch");
  memcpy(context_.regs, context_snapshot->regs, sizeof(context_.regs));
  context_.csr_era = context_snapshot->csr_era;

  static_assert(sizeof(context_.fpregs) == sizeof(context_snapshot->fpregs),
                "FPRs size mismatch");
  memcpy(context_.fpregs.dregs,
         context_snapshot->fpregs.dregs,
         sizeof(context_.fpregs.dregs));
  context_.fcsr = context_snapshot->fcsr;
  context_.fcc = context_snapshot->fcc;
}

bool MinidumpContextLOONGARCH64Writer::WriteObject(
    FileWriterInterface* file_writer) {
  DCHECK_EQ(state(), kStateWritable);
  return file_writer->Write(&context_, sizeof(context_));
}

size_t MinidumpContextLOONGARCH64Writer::ContextSize() const {
  DCHECK_GE(state(), kStateFrozen);
  return sizeof(context_);
}
// loongarch64 end
}  // namespace crashpad
