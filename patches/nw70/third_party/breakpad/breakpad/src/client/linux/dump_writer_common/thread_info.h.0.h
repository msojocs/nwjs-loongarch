#elif defined(__mips__)
  // Use the structure defined in <sys/ucontext.h>.
  mcontext_t mcontext;
#endif

  // Returns the instruction pointer (platform-dependent impl.).

//----replace
#elif defined(__mips__)
  // Use the structure defined in <sys/ucontext.h>.
  mcontext_t mcontext;
#elif defined(__loongarch64)
  // Use the structures defined in <sys/user.h>
  struct user_regs_struct regs;
  struct user_fp_struct fpregs;
#endif

  // Returns the instruction pointer (platform-dependent impl.).
