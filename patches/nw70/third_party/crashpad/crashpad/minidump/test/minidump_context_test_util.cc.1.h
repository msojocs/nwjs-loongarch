  EXPECT_EQ(observed->dsp_control, expected.dsp_control);
}

}  // namespace test
}  // namespace crashpad

//----replace
  EXPECT_EQ(observed->dsp_control, expected.dsp_control);
}

void ExpectMinidumpContextLOONGARCH64(uint32_t expect_seed,// loongarch64
                                 const MinidumpContextLOONGARCH64* observed,// loongarch64
                                 bool snapshot) {// loongarch64
  MinidumpContextLOONGARCH64 expected;// loongarch64
  InitializeMinidumpContextLOONGARCH64(&expected, expect_seed);// loongarch64
// loongarch64
  EXPECT_EQ(observed->context_flags, expected.context_flags);// loongarch64
// loongarch64
  for (size_t index = 0; index < std::size(expected.regs); ++index) {// loongarch64
    EXPECT_EQ(observed->regs[index], expected.regs[index]);// loongarch64
  }// loongarch64
// loongarch64
  EXPECT_EQ(observed->csr_era, expected.csr_era);// loongarch64
// loongarch64
  for (size_t index = 0; index < std::size(expected.fpregs.dregs); ++index) {// loongarch64
    EXPECT_EQ(observed->fpregs.dregs[index], expected.fpregs.dregs[index]);// loongarch64
  }// loongarch64
  EXPECT_EQ(observed->fcsr, expected.fcsr);// loongarch64
  EXPECT_EQ(observed->fcc, expected.fcc);// loongarch64
}// loongarch64
// loongarch64
}  // namespace test
}  // namespace crashpad
