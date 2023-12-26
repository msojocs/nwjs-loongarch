void InitializeMinidumpContextMIPS(MinidumpContextMIPS* context, uint32_t seed);
void InitializeMinidumpContextMIPS64(MinidumpContextMIPS* context,
                                     uint32_t seed);
//! \}

//! \brief Verifies, via Google Test assertions, that a context structure

//----replace
void InitializeMinidumpContextMIPS(MinidumpContextMIPS* context, uint32_t seed);
void InitializeMinidumpContextMIPS64(MinidumpContextMIPS* context,
                                     uint32_t seed);
void InitializeMinidumpContextLOONGARCH64(MinidumpContextLOONGARCH64* context, // loongarch64
                                     uint32_t seed); // loongarch64
//! \}

//! \brief Verifies, via Google Test assertions, that a context structure
