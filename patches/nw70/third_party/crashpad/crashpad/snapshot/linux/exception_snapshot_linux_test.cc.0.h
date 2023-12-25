            0);
#undef CPU_ARCH_NAME
}

#else
#error Port.

//----replace
            0);
#undef CPU_ARCH_NAME
}
#elif defined(ARCH_CPU_LOONG64)
struct NativeCPUContext {
  ucontext_t ucontext;
  struct context_info info;
};

void InitializeContext(NativeCPUContext* context) {
  for (size_t reg = 0; reg < std::size(context->ucontext.uc_mcontext.__gregs); ++reg) {
    context->ucontext.uc_mcontext.__gregs[reg] = reg;
  }
  context->info.magic = 0;
  context->info.size = 0;
}

void ExpectContext(const CPUContext& actual, const NativeCPUContext& expected) {
  EXPECT_EQ(actual.architecture, kCPUArchitectureLOONGARCH64);

  for (size_t reg = 0; reg < std::size(expected.ucontext.uc_mcontext.__gregs); ++reg) {
    EXPECT_EQ(actual.loongarch64->regs[reg], expected.ucontext.uc_mcontext.__gregs[reg]);
  }
}

#else
#error Port.
