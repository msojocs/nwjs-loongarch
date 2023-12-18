  for (size_t i = 0; i < std::size(context.riscv64->regs); ++i) {
    MaybeCaptureMemoryAround(delegate, context.riscv64->regs[i]);
  }
#elif defined(ARCH_CPU_LOONGARCH_FAMILY)
  for (size_t i = 0; i < std::size(context.loongarch64->regs); ++i) {
    MaybeCaptureMemoryAround(delegate, context.loongarch64->regs[i]);
  }
#else
#error Port.