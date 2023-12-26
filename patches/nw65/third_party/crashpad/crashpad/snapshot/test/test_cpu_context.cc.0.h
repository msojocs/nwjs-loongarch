  mips64->dsp_control = value++;
}

}  // namespace test
}  // namespace crashpad

//----replace
  mips64->dsp_control = value++;
}

void InitializeCPUContextLOONGARCH64(CPUContext* context, uint32_t seed) { // loongarch64
  context->architecture = kCPUArchitectureLOONGARCH64; // loongarch64
  CPUContextLOONGARCH64* loongarch64 = context->loongarch64; // loongarch64
 // loongarch64
  if (seed == 0) { // loongarch64
    memset(loongarch64, 0, sizeof(*loongarch64)); // loongarch64
    return; // loongarch64
  } // loongarch64
 // loongarch64
  uint64_t value = seed; // loongarch64
 // loongarch64
  for (size_t index = 0; index < std::size(loongarch64->regs); ++index) { // loongarch64
    loongarch64->regs[index] = value++; // loongarch64
  } // loongarch64
 // loongarch64
  loongarch64->csr_era = value++; // loongarch64
 // loongarch64
  for (size_t index = 0; index < std::size(loongarch64->fpregs.dregs); ++index) { // loongarch64
    loongarch64->fpregs.dregs[index] = static_cast<double>(value++); // loongarch64
  } // loongarch64
 // loongarch64
  loongarch64->fcsr = value++; // loongarch64
  loongarch64->fcc = value++; // loongarch64
} // loongarch64
 // loongarch64
}  // namespace test
}  // namespace crashpad
