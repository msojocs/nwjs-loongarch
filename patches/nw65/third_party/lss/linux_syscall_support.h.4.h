    void             (*sa_sigaction_)(int, siginfo_t *, void *);
  };
  unsigned long      sa_flags;
  void               (*sa_restorer)(void);
  struct kernel_sigset_t sa_mask;
#endif
};

//----replace
    void             (*sa_sigaction_)(int, siginfo_t *, void *);
  };
  unsigned long      sa_flags;
#ifndef __loongarch64 // loongarch64
  void               (*sa_restorer)(void);
#endif // loongarch64
  struct kernel_sigset_t sa_mask;
#endif
};
