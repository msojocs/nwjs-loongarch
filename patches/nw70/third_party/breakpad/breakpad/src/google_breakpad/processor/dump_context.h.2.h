    MDRawContextARM*   arm;
    MDRawContextARM64* arm64;
    MDRawContextMIPS*  ctx_mips;
  } context_;

  // Store this separately because of the weirdo AMD64 context

//----replace
    MDRawContextARM*   arm;
    MDRawContextARM64* arm64;
    MDRawContextMIPS*  ctx_mips;
    MDRawContextLOONGARCH64* loongarch64;// loongarch64
  } context_;

  // Store this separately because of the weirdo AMD64 context
