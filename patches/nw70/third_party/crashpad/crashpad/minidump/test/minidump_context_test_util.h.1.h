void ExpectMinidumpContextMIPS64(uint32_t expect_seed,
                                 const MinidumpContextMIPS64* observed,
                                 bool snapshot);
//! \}

}  // namespace test

//----replace
void ExpectMinidumpContextMIPS64(uint32_t expect_seed,
                                 const MinidumpContextMIPS64* observed,
                                 bool snapshot);
void ExpectMinidumpContextLOONGARCH64(uint32_t expect_seed,
                                 const MinidumpContextLOONGARCH64* observed,
                                 bool snapshot);
//! \}

}  // namespace test
