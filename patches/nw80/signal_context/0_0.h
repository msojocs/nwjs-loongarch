static_assert(offsetof(UContext<ContextTraits64>, mcontext.fpregs) ==
                  offsetof(ucontext_t, uc_mcontext.__fpregs),
              "context offset mismatch");

#else
#error Port.