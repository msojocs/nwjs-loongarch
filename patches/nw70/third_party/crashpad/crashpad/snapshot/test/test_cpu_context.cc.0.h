  mips64->dsp_control = value++;
}

}  // namespace test
}  // namespace crashpad

//----replace
  mips64->dsp_control = value++;
}

void InitializeCPUContextLOONGARCH64(CPUContext* context, uint32_t seed) {
  context->architecture = kCPUArchitectureLOONGARCH64;
  CPUContextLOONGARCH64* loongarch64 = context->loongarch64;

  if (seed == 0) {
    memset(loongarch64, 0, sizeof(*loongarch64));
    return;
  }

  uint64_t value = seed;

  for (size_t index = 0; index < std::size(loongarch64->regs); ++index) {
    loongarch64->regs[index] = value++;
  }

  loongarch64->csr_era = value++;

  for (size_t index = 0; index < std::size(loongarch64->fpregs.dregs); ++index) {
    loongarch64->fpregs.dregs[index] = static_cast<double>(value++);
  }

  loongarch64->fcsr = value++;
  loongarch64->fcc = value++;
}

}  // namespace test
}  // namespace crashpad
