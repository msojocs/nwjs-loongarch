  void* Alloc(unsigned bytes) { return dumper_->allocator()->Alloc(bytes); }

  const ucontext_t* const ucontext_;
#if !defined(__ARM_EABI__) && !defined(__mips__)
  const google_breakpad::fpstate_t* const float_state_;
#endif
  LinuxDumper* dumper_;

//----replace
  void* Alloc(unsigned bytes) { return dumper_->allocator()->Alloc(bytes); }

  const ucontext_t* const ucontext_;
#if !defined(__ARM_EABI__) && !defined(__mips__) && !defined(__loongarch64)// loongarch64
  const google_breakpad::fpstate_t* const float_state_;
#endif
  LinuxDumper* dumper_;
