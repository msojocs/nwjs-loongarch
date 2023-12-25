#elif defined(__mips__)
  stack_pointer =
      reinterpret_cast<uint8_t*>(info->mcontext.gregs[MD_CONTEXT_MIPS_REG_SP]);
#else
#error "This code hasn't been ported to your platform yet."
#endif

//----replace
#elif defined(__mips__)
  stack_pointer =
      reinterpret_cast<uint8_t*>(info->mcontext.gregs[MD_CONTEXT_MIPS_REG_SP]);
#elif defined(__loongarch64)
  memcpy(&stack_pointer, &info->regs.regs[MD_CONTEXT_LOONGARCH64_REG_SP], 
	 sizeof(info->regs.regs[MD_CONTEXT_LOONGARCH64_REG_SP]));
#else
#error "This code hasn't been ported to your platform yet."
#endif
