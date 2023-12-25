  context->dsp_control = value++;
}

namespace {

// Using Google Test assertions, compares |expected| to |observed|. This is

//----replace
  context->dsp_control = value++;
}

void InitializeMinidumpContextLOONGARCH64(MinidumpContextLOONGARCH64* context,
                                     uint32_t seed) {
  if (seed == 0) {
    memset(context, 0, sizeof(*context));
    context->context_flags = kMinidumpContextLOONGARCH64;
    return;
  }

  context->context_flags = kMinidumpContextLOONGARCH64All;

  uint64_t value = seed;

  for (size_t index = 0; index < std::size(context->regs); ++index) {
    context->regs[index] = value++;
  }

  context->csr_era = value++;

  for (size_t index = 0; index < std::size(context->fpregs.dregs); ++index) {
    context->fpregs.dregs[index] = static_cast<double>(value++);
  }
  context->fcsr = value++;
  context->fcc = value++;
}

namespace {

// Using Google Test assertions, compares |expected| to |observed|. This is
