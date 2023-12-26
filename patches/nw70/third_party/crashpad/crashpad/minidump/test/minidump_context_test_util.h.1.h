void ExpectMinidumpContextMIPS64(uint32_t expect_seed,
                                 const MinidumpContextMIPS64* observed,
                                 bool snapshot);
//! \}

}  // namespace test

//----replace
void ExpectMinidumpContextMIPS64(uint32_t expect_seed,
                                 const MinidumpContextMIPS64* observed,
                                 bool snapshot);
void ExpectMinidumpContextLOONGARCH64(uint32_t expect_seed,// loongarch64
                                 const MinidumpContextLOONGARCH64* observed,// loongarch64
                                 bool snapshot);// loongarch64
//! \}

}  // namespace test
