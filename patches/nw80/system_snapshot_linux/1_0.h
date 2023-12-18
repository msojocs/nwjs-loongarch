#elif defined(ARCH_CPU_RISCV64)
  return kCPUArchitectureRISCV64;
#else
#error port to your architecture
//----replace
#elif defined(ARCH_CPU_RISCV64)
  return kCPUArchitectureRISCV64;
#elif defined(ARCH_CPU_LOONGARCH64)
  return kCPUArchitectureLOONGARCH64;
#else
#error port to your architecture