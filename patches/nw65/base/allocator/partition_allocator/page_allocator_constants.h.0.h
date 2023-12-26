  // compiled for 64kB are likely to work on 4kB systems, 64kB is a good choice
  // here.
  return 16;  // 64kB
#elif defined(_MIPS_ARCH_LOONGSON)
  return 14;  // 16kB
#elif BUILDFLAG(IS_APPLE) && defined(ARCH_CPU_64_BITS)
  return vm_page_shift;

//----replace
  // compiled for 64kB are likely to work on 4kB systems, 64kB is a good choice
  // here.
  return 16;  // 64kB
#elif defined(_MIPS_ARCH_LOONGSON) || defined(ARCH_CPU_LOONG64) // loongarch64
  return 14;  // 16kB
#elif BUILDFLAG(IS_APPLE) && defined(ARCH_CPU_64_BITS)
  return vm_page_shift;
