  int context_validity;
};

}  // namespace google_breakpad

#endif  // GOOGLE_BREAKPAD_PROCESSOR_STACK_FRAME_CPU_H__

//----replace
  int context_validity;
};

struct StackFrameLOONGARCH64 : public StackFrame { // loongarch64
  enum ContextValidity { // loongarch64
    CONTEXT_VALID_NONE = 0, // loongarch64
 // loongarch64
    CONTEXT_VALID_RA = 1UL << 1, // loongarch64
    CONTEXT_VALID_TP = 1UL << 2, // loongarch64
    CONTEXT_VALID_SP = 1UL << 3, // loongarch64
    CONTEXT_VALID_A0 = 1UL << 4, // loongarch64
    CONTEXT_VALID_A1 = 1UL << 5, // loongarch64
    CONTEXT_VALID_A2 = 1UL << 6, // loongarch64
    CONTEXT_VALID_A3 = 1UL << 7, // loongarch64
    CONTEXT_VALID_A4 = 1UL << 8, // loongarch64
    CONTEXT_VALID_A5 = 1UL << 9, // loongarch64
    CONTEXT_VALID_A6 = 1UL << 10, // loongarch64
    CONTEXT_VALID_A7 = 1UL << 11, // loongarch64
    CONTEXT_VALID_T0 = 1UL << 12, // loongarch64
    CONTEXT_VALID_T1 = 1UL << 13, // loongarch64
    CONTEXT_VALID_T2 = 1UL << 14, // loongarch64
    CONTEXT_VALID_T3 = 1UL << 15, // loongarch64
    CONTEXT_VALID_T4 = 1UL << 16, // loongarch64
    CONTEXT_VALID_T5 = 1UL << 17, // loongarch64
    CONTEXT_VALID_T6 = 1UL << 18, // loongarch64
    CONTEXT_VALID_T7 = 1UL << 19, // loongarch64
    CONTEXT_VALID_T8 = 1UL << 20, // loongarch64
    CONTEXT_VALID_X0 = 1UL << 21, // loongarch64
    CONTEXT_VALID_FP = 1UL << 22, // loongarch64
    CONTEXT_VALID_S0 = 1UL << 23, // loongarch64
    CONTEXT_VALID_S1 = 1UL << 24, // loongarch64
    CONTEXT_VALID_S2 = 1UL << 25, // loongarch64
    CONTEXT_VALID_S3 = 1UL << 26, // loongarch64
    CONTEXT_VALID_S4 = 1UL << 27, // loongarch64
    CONTEXT_VALID_S5 = 1UL << 28, // loongarch64
    CONTEXT_VALID_S6 = 1UL << 29, // loongarch64
    CONTEXT_VALID_S7 = 1UL << 30, // loongarch64
    CONTEXT_VALID_S8 = 1UL << 31, // loongarch64
 // loongarch64
    CONTEXT_VALID_PC = 1UL << 32, // loongarch64
    CONTEXT_VALID_ALL = ~CONTEXT_VALID_NONE // loongarch64
  }; // loongarch64
 // loongarch64
  // Return the ContextValidity flag for register rN. // loongarch64
  static ContextValidity RegisterValidFlag(int n) { // loongarch64
    return ContextValidity(1 << n); // loongarch64
  } // loongarch64
 // loongarch64
  StackFrameLOONGARCH64() : context(), context_validity(CONTEXT_VALID_NONE) {} // loongarch64
 // loongarch64
  // Register state. This is only fully valid for the topmost frame in a // loongarch64
  // stack. In other frames, which registers are present depends on what // loongarch64
  // debugging information were available. Refer to 'context_validity' below. // loongarch64
  MDRawContextLOONGARCH64 context;    // loongarch64
 // loongarch64
  // For each register in context whose value has been recovered, // loongarch64
  // the corresponding CONTEXT_VALID_ bit in 'context_validity' is set. // loongarch64
  // // loongarch64
  // context_validity's type should actually be ContextValidity, but // loongarch64
  // type int is used instead because the bitwise inclusive or operator // loongarch64
  // yields an int when applied to enum values, and C++ doesn't // loongarch64
  // silently convert from ints to enums. // loongarch64
  int context_validity; // loongarch64
}; // loongarch64
 // loongarch64
}  // namespace google_breakpad

#endif  // GOOGLE_BREAKPAD_PROCESSOR_STACK_FRAME_CPU_H__
