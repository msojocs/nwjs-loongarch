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
#endif // ARCH_CPU_MIPSEL

#elif defined(ARCH_CPU_LOONG64)
struct MContext64 {
  uint64_t pc;
  uint64_t gregs[32];
  uint32_t flags;
  uint32_t pading;
  uint64_t extcontext[0] __attribute__((__aligned__(16)));
};

struct ContextTraits64 : public Traits64 {
  using MContext = MContext64;
  using SignalThreadContext = ThreadContext::t64_t;
  using SignalFloatContext = FloatContext::f64_t;
  using CPUContext = CPUContextLOONGARCH64;
};

template <typename Traits>
struct UContext {
  typename Traits::ULong flags;
  typename Traits::Address link;
  SignalStack<Traits> stack;
  Sigset<Traits> sigmask;
  char padding[128 - sizeof(sigmask)];
  uint64_t pading1;
  typename Traits::MContext mcontext;
};

static_assert(offsetof(UContext<ContextTraits64>, mcontext) ==
                  offsetof(ucontext_t, uc_mcontext),
              "context offset mismtach");
static_assert(offsetof(UContext<ContextTraits64>, mcontext.gregs) ==
                  offsetof(ucontext_t, uc_mcontext.__gregs),
              "context offset mismatch");
static_assert(offsetof(UContext<ContextTraits64>, mcontext.extcontext) ==
                  offsetof(ucontext_t, uc_mcontext.__extcontext),
              "context offset mismatch");

#else
#error Port.
