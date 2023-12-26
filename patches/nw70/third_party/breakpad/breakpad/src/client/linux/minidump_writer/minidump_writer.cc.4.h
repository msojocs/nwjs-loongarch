  const char* path_;  // Path to the file where the minidum should be written.

  const ucontext_t* const ucontext_;  // also from the signal handler
#if !defined(__ARM_EABI__) && !defined(__mips__)
  const google_breakpad::fpstate_t* const float_state_;  // ditto
#endif
  LinuxDumper* dumper_;

//----replace
  const char* path_;  // Path to the file where the minidum should be written.

  const ucontext_t* const ucontext_;  // also from the signal handler
#if !defined(__ARM_EABI__) && !defined(__mips__) && !defined(__loongarch64)// loongarch64
  const google_breakpad::fpstate_t* const float_state_;  // ditto
#endif
  LinuxDumper* dumper_;
