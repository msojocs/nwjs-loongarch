void InitializeCPUContextARM64(CPUContext* context, uint32_t seed);
void InitializeCPUContextMIPS(CPUContext* context, uint32_t seed);
void InitializeCPUContextMIPS64(CPUContext* context, uint32_t seed);
//! \}

}  // namespace test

//----replace
void InitializeCPUContextARM64(CPUContext* context, uint32_t seed);
void InitializeCPUContextMIPS(CPUContext* context, uint32_t seed);
void InitializeCPUContextMIPS64(CPUContext* context, uint32_t seed);
void InitializeCPUContextLOONGARCH64(CPUContext* context, uint32_t seed);
//! \}

}  // namespace test
