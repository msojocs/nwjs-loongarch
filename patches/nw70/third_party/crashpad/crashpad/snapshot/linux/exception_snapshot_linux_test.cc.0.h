            0);
#undef CPU_ARCH_NAME
}

#else
#error Port.

//----replace
            0);
#undef CPU_ARCH_NAME
}
#elif defined(ARCH_CPU_LOONG64)// loongarch64
struct NativeCPUContext {// loongarch64
  ucontext_t ucontext;// loongarch64
  struct context_info info;// loongarch64
};// loongarch64
// loongarch64
void InitializeContext(NativeCPUContext* context) {// loongarch64
  for (size_t reg = 0; reg < std::size(context->ucontext.uc_mcontext.__gregs); ++reg) {// loongarch64
    context->ucontext.uc_mcontext.__gregs[reg] = reg;// loongarch64
  }// loongarch64
  context->info.magic = 0;// loongarch64
  context->info.size = 0;// loongarch64
}// loongarch64
// loongarch64
void ExpectContext(const CPUContext& actual, const NativeCPUContext& expected) {// loongarch64
  EXPECT_EQ(actual.architecture, kCPUArchitectureLOONGARCH64);// loongarch64
// loongarch64
  for (size_t reg = 0; reg < std::size(expected.ucontext.uc_mcontext.__gregs); ++reg) {// loongarch64
    EXPECT_EQ(actual.loongarch64->regs[reg], expected.ucontext.uc_mcontext.__gregs[reg]);// loongarch64
  }// loongarch64
}// loongarch64

#else
#error Port.
