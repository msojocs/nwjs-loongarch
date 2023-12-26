#elif defined(ARCH_CPU_MIPS_FAMILY)
  return process_reader_->Is64Bit() ? kCPUArchitectureMIPS64EL
                                    : kCPUArchitectureMIPSEL;
#else
#error port to your architecture
#endif

//----replace
#elif defined(ARCH_CPU_MIPS_FAMILY)
  return process_reader_->Is64Bit() ? kCPUArchitectureMIPS64EL
                                    : kCPUArchitectureMIPSEL;
#elif defined(ARCH_CPU_LOONG64) // loongarch64
  return kCPUArchitectureLOONGARCH64; // loongarch64
#else
#error port to your architecture
#endif
