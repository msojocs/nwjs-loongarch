  uintptr_t pc = ProgramCounterFromContext(context_1);

#if !defined(ADDRESS_SANITIZER) && !defined(ARCH_CPU_MIPS_FAMILY) && \
    !defined(MEMORY_SANITIZER)
  // Sanitizers can cause enough code bloat that the “nearby” check would
  // likely fail.
  const uintptr_t kReferencePC =

//----replace
  uintptr_t pc = ProgramCounterFromContext(context_1);

#if !defined(ADDRESS_SANITIZER) && !defined(ARCH_CPU_MIPS_FAMILY) && \
    !defined(MEMORY_SANITIZER) && !defined(ARCH_CPU_LOONG64) // loongarch64
  // Sanitizers can cause enough code bloat that the “nearby” check would
  // likely fail.
  const uintptr_t kReferencePC =
