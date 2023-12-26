}

void Multiprocess::SetExpectedChildTerminationBuiltinTrap() {
#if defined(ARCH_CPU_ARM64) || defined(ARCH_CPU_MIPS_FAMILY)
  SetExpectedChildTermination(kTerminationSignal, SIGTRAP);
#else
  SetExpectedChildTermination(kTerminationSignal, SIGILL);

//----replace
}

void Multiprocess::SetExpectedChildTerminationBuiltinTrap() {
#if defined(ARCH_CPU_ARM64) || defined(ARCH_CPU_MIPS_FAMILY) ||\
    defined (ARCH_CPU_LOONG64) // loongarch64
  SetExpectedChildTermination(kTerminationSignal, SIGTRAP);
#else
  SetExpectedChildTermination(kTerminationSignal, SIGILL);
