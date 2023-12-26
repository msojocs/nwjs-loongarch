  context->dsp_control = value++;
}

namespace {

// Using Google Test assertions, compares |expected| to |observed|. This is

//----replace
  context->dsp_control = value++;
}

void InitializeMinidumpContextLOONGARCH64(MinidumpContextLOONGARCH64* context,// loongarch64
                                     uint32_t seed) {// loongarch64
  if (seed == 0) {// loongarch64
    memset(context, 0, sizeof(*context));// loongarch64
    context->context_flags = kMinidumpContextLOONGARCH64;// loongarch64
    return;// loongarch64
  }// loongarch64
// loongarch64
  context->context_flags = kMinidumpContextLOONGARCH64All;// loongarch64
// loongarch64
  uint64_t value = seed;// loongarch64
// loongarch64
  for (size_t index = 0; index < std::size(context->regs); ++index) {// loongarch64
    context->regs[index] = value++;// loongarch64
  }// loongarch64
// loongarch64
  context->csr_era = value++;// loongarch64
// loongarch64
  for (size_t index = 0; index < std::size(context->fpregs.dregs); ++index) {// loongarch64
    context->fpregs.dregs[index] = static_cast<double>(value++);// loongarch64
  }// loongarch64
  context->fcsr = value++;// loongarch64
  context->fcc = value++;// loongarch64
}// loongarch64
// loongarch64
namespace {

// Using Google Test assertions, compares |expected| to |observed|. This is
