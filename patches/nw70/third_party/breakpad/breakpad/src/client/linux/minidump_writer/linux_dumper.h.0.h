 (defined(__mips__) && _MIPS_SIM == _ABIO32)
typedef Elf32_auxv_t elf_aux_entry;
#elif defined(__x86_64) || defined(__aarch64__) || \
     (defined(__mips__) && _MIPS_SIM != _ABIO32)
typedef Elf64_auxv_t elf_aux_entry;
#endif


//----replace
 (defined(__mips__) && _MIPS_SIM == _ABIO32)
typedef Elf32_auxv_t elf_aux_entry;
#elif defined(__x86_64) || defined(__aarch64__) || \
     (defined(__mips__) && _MIPS_SIM != _ABIO32) || defined(__loongarch64)
typedef Elf64_auxv_t elf_aux_entry;
#endif

