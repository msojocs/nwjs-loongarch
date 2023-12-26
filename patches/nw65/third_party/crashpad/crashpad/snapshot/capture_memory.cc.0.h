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
#elif defined(ARCH_CPU_LOONG_FAMILY) // loongarch64
  for (size_t i = 0; i < std::size(context.loongarch64->regs); ++i) { // loongarch64
    MaybeCaptureMemoryAround(delegate, context.loongarch64->regs[i]); // loongarch64
  } // loongarch64
#else
#error Port.
#endif
