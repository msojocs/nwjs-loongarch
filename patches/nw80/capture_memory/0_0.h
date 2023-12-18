  for (size_t i = 0; i < std::size(context.riscv64->regs); ++i) {
    MaybeCaptureMemoryAround(delegate, context.riscv64->regs[i]);
  }
#else
#error Port.