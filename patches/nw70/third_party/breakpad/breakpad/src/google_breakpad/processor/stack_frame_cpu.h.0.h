  int context_validity;
};

}  // namespace google_breakpad

#endif  // GOOGLE_BREAKPAD_PROCESSOR_STACK_FRAME_CPU_H__

//----replace
  int context_validity;
};

struct StackFrameLOONGARCH64 : public StackFrame {
  enum ContextValidity {
    CONTEXT_VALID_NONE = 0,

    CONTEXT_VALID_RA = 1UL << 1,
    CONTEXT_VALID_TP = 1UL << 2,
    CONTEXT_VALID_SP = 1UL << 3,
    CONTEXT_VALID_A0 = 1UL << 4,
    CONTEXT_VALID_A1 = 1UL << 5,
    CONTEXT_VALID_A2 = 1UL << 6,
    CONTEXT_VALID_A3 = 1UL << 7,
    CONTEXT_VALID_A4 = 1UL << 8,
    CONTEXT_VALID_A5 = 1UL << 9,
    CONTEXT_VALID_A6 = 1UL << 10,
    CONTEXT_VALID_A7 = 1UL << 11,
    CONTEXT_VALID_T0 = 1UL << 12,
    CONTEXT_VALID_T1 = 1UL << 13,
    CONTEXT_VALID_T2 = 1UL << 14,
    CONTEXT_VALID_T3 = 1UL << 15,
    CONTEXT_VALID_T4 = 1UL << 16,
    CONTEXT_VALID_T5 = 1UL << 17,
    CONTEXT_VALID_T6 = 1UL << 18,
    CONTEXT_VALID_T7 = 1UL << 19,
    CONTEXT_VALID_T8 = 1UL << 20,
    CONTEXT_VALID_X0 = 1UL << 21,
    CONTEXT_VALID_FP = 1UL << 22,
    CONTEXT_VALID_S0 = 1UL << 23,
    CONTEXT_VALID_S1 = 1UL << 24,
    CONTEXT_VALID_S2 = 1UL << 25,
    CONTEXT_VALID_S3 = 1UL << 26,
    CONTEXT_VALID_S4 = 1UL << 27,
    CONTEXT_VALID_S5 = 1UL << 28,
    CONTEXT_VALID_S6 = 1UL << 29,
    CONTEXT_VALID_S7 = 1UL << 30,
    CONTEXT_VALID_S8 = 1UL << 31,

    CONTEXT_VALID_PC = 1UL << 32,
    CONTEXT_VALID_ALL = ~CONTEXT_VALID_NONE
  };

  // Return the ContextValidity flag for register rN.
  static ContextValidity RegisterValidFlag(int n) {
    return ContextValidity(1 << n);
  }

  StackFrameLOONGARCH64() : context(), context_validity(CONTEXT_VALID_NONE) {}

  // Register state. This is only fully valid for the topmost frame in a
  // stack. In other frames, which registers are present depends on what
  // debugging information were available. Refer to 'context_validity' below.
  MDRawContextLOONGARCH64 context;   

  // For each register in context whose value has been recovered,
  // the corresponding CONTEXT_VALID_ bit in 'context_validity' is set.
  //
  // context_validity's type should actually be ContextValidity, but
  // type int is used instead because the bitwise inclusive or operator
  // yields an int when applied to enum values, and C++ doesn't
  // silently convert from ints to enums.
  int context_validity;
};
// loongarch64
}  // namespace google_breakpad

#endif  // GOOGLE_BREAKPAD_PROCESSOR_STACK_FRAME_CPU_H__
