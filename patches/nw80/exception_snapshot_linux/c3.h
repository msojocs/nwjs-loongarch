
#if !defined(ARCH_CPU_RISCV64)
    if (!ReadContext<ContextTraits32>(process_reader, context_address) ||
        !ReadSiginfo<Traits32>(process_reader, siginfo_address)) {
      return false;
//----replace

#if !defined(ARCH_CPU_RISCV64) && !defined(ARCH_CPU_LOONGARCH64)
    if (!ReadContext<ContextTraits32>(process_reader, context_address) ||
        !ReadSiginfo<Traits32>(process_reader, siginfo_address)) {
      return false;