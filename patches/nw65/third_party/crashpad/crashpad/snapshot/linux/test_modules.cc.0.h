  module.ehdr.e_machine = EM_AARCH64;
#elif defined(ARCH_CPU_MIPSEL) || defined(ARCH_CPU_MIPS64EL)
  module.ehdr.e_machine = EM_MIPS;
#endif

  module.ehdr.e_version = EV_CURRENT;

//----replace
  module.ehdr.e_machine = EM_AARCH64;
#elif defined(ARCH_CPU_MIPSEL) || defined(ARCH_CPU_MIPS64EL)
  module.ehdr.e_machine = EM_MIPS;
#elif defined(ARCH_CPU_LOONG64) // loongarch64
  module.ehdr.e_machine = EM_LOONGARCH; // loongarch64
  module.ehdr.e_flags |= EF_LARCH_ABI_LP64; // loongarch64
#endif

  module.ehdr.e_version = EV_CURRENT;
