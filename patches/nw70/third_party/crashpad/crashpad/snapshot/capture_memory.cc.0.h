  for (size_t i = 0; i < std::size(context.mipsel->regs); ++i) {
    MaybeCaptureMemoryAround(delegate, context.mipsel->regs[i]);
  }
#else
#error Port.
#endif

//----replace
  for (size_t i = 0; i < std::size(context.mipsel->regs); ++i) {
    MaybeCaptureMemoryAround(delegate, context.mipsel->regs[i]);
  }
#elif defined(ARCH_CPU_LOONG_FAMILY)
  for (size_t i = 0; i < std::size(context.loongarch64->regs); ++i) {
    MaybeCaptureMemoryAround(delegate, context.loongarch64->regs[i]);
  }
#else
#error Port.
#endif
