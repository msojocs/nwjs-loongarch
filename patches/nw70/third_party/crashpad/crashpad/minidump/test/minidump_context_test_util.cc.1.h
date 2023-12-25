  EXPECT_EQ(observed->dsp_control, expected.dsp_control);
}

}  // namespace test
}  // namespace crashpad

//----replace
  EXPECT_EQ(observed->dsp_control, expected.dsp_control);
}

void ExpectMinidumpContextLOONGARCH64(uint32_t expect_seed,
                                 const MinidumpContextLOONGARCH64* observed,
                                 bool snapshot) {
  MinidumpContextLOONGARCH64 expected;
  InitializeMinidumpContextLOONGARCH64(&expected, expect_seed);

  EXPECT_EQ(observed->context_flags, expected.context_flags);

  for (size_t index = 0; index < std::size(expected.regs); ++index) {
    EXPECT_EQ(observed->regs[index], expected.regs[index]);
  }

  EXPECT_EQ(observed->csr_era, expected.csr_era);

  for (size_t index = 0; index < std::size(expected.fpregs.dregs); ++index) {
    EXPECT_EQ(observed->fpregs.dregs[index], expected.fpregs.dregs[index]);
  }
  EXPECT_EQ(observed->fcsr, expected.fcsr);
  EXPECT_EQ(observed->fcc, expected.fcc);
}

}  // namespace test
}  // namespace crashpad
