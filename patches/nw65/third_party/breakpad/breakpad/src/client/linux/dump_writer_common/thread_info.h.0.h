#elif defined(__mips__)
  // Use the structure defined in <sys/ucontext.h>.
  mcontext_t mcontext;
#endif

  // Returns the instruction pointer (platform-dependent impl.).

//----replace
#elif defined(__mips__)
  // Use the structure defined in <sys/ucontext.h>.
  mcontext_t mcontext;
#elif defined(__loongarch64) // loongarch64
  // Use the structures defined in <sys/user.h> // loongarch64
  struct user_regs_struct regs; // loongarch64
  struct user_fp_struct fpregs; // loongarch64
#endif

  // Returns the instruction pointer (platform-dependent impl.).
