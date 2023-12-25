  EXPECT_EQ(context.uc_mcontext.regs[0], FromPointerCast<uintptr_t>(&context));
#elif defined(ARCH_CPU_MIPS_FAMILY)
  EXPECT_EQ(context.uc_mcontext.gregs[4], FromPointerCast<uintptr_t>(&context));
#endif
}


//----replace
  EXPECT_EQ(context.uc_mcontext.regs[0], FromPointerCast<uintptr_t>(&context));
#elif defined(ARCH_CPU_MIPS_FAMILY)
  EXPECT_EQ(context.uc_mcontext.gregs[4], FromPointerCast<uintptr_t>(&context));
#elif defined(ARCH_CPU_LOONG64)
  EXPECT_EQ(context.ucontext.uc_mcontext.__gregs[4], FromPointerCast<uintptr_t>(&context));
#endif
}

