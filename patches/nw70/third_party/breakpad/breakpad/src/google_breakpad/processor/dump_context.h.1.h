  void SetContextARM(MDRawContextARM* arm);
  void SetContextARM64(MDRawContextARM64* arm64);
  void SetContextMIPS(MDRawContextMIPS* ctx_mips);

  // Free the CPU-specific context structure.
  void FreeContext();

//----replace
  void SetContextARM(MDRawContextARM* arm);
  void SetContextARM64(MDRawContextARM64* arm64);
  void SetContextMIPS(MDRawContextMIPS* ctx_mips);
  void SetContextLOONGARCH64(MDRawContextLOONGARCH64* loongarch64);

  // Free the CPU-specific context structure.
  void FreeContext();
