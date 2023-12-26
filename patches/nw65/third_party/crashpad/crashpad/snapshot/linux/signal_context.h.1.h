static_assert(offsetof(UContext<ContextTraits64>, mcontext.fpregs) ==
                  offsetof(ucontext_t, uc_mcontext.fpregs),
              "context offset mismatch");
#endif

#else
#error Port.

//----replace
static_assert(offsetof(UContext<ContextTraits64>, mcontext.fpregs) ==
                  offsetof(ucontext_t, uc_mcontext.fpregs),
              "context offset mismatch");
#endif // ARCH_CPU_MIPSEL // loongarch64
 // loongarch64
#elif defined(ARCH_CPU_LOONG64) // loongarch64
struct MContext64 { // loongarch64
  uint64_t pc; // loongarch64
  uint64_t gregs[32]; // loongarch64
  uint32_t flags; // loongarch64
  uint32_t pading; // loongarch64
  uint64_t extcontext[0] __attribute__((__aligned__(16))); // loongarch64
}; // loongarch64
 // loongarch64
struct ContextTraits64 : public Traits64 { // loongarch64
  using MContext = MContext64; // loongarch64
  using SignalThreadContext = ThreadContext::t64_t; // loongarch64
  using SignalFloatContext = FloatContext::f64_t; // loongarch64
  using CPUContext = CPUContextLOONGARCH64; // loongarch64
}; // loongarch64
 // loongarch64
template <typename Traits> // loongarch64
struct UContext { // loongarch64
  typename Traits::ULong flags; // loongarch64
  typename Traits::Address link; // loongarch64
  SignalStack<Traits> stack; // loongarch64
  Sigset<Traits> sigmask; // loongarch64
  char padding[128 - sizeof(sigmask)]; // loongarch64
  uint64_t pading1; // loongarch64
  typename Traits::MContext mcontext; // loongarch64
}; // loongarch64
 // loongarch64
static_assert(offsetof(UContext<ContextTraits64>, mcontext) == // loongarch64
                  offsetof(ucontext_t, uc_mcontext), // loongarch64
              "context offset mismtach"); // loongarch64
static_assert(offsetof(UContext<ContextTraits64>, mcontext.gregs) == // loongarch64
                  offsetof(ucontext_t, uc_mcontext.__gregs), // loongarch64
              "context offset mismatch"); // loongarch64
static_assert(offsetof(UContext<ContextTraits64>, mcontext.extcontext) == // loongarch64
                  offsetof(ucontext_t, uc_mcontext.__extcontext), // loongarch64
              "context offset mismatch"); // loongarch64

#else
#error Port.
