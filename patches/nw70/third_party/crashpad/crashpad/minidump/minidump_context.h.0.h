  uint64_t fir;
};

}  // namespace crashpad

#endif  // CRASHPAD_MINIDUMP_MINIDUMP_CONTEXT_H_

//----replace
  uint64_t fir;
};

//! \brief LOONGARCH64-specifc flags for MinidumpContextLOONGARCH64::context_flags.
//! Based on minidump_cpu_loongarch64.h from breakpad
enum MinidumpContextLOONGARCH64Flags : uint32_t {
  //! \brief Identifies the context structure as LOONGARCH64.
  kMinidumpContextLOONGARCH64 = 0x00800000,

  //! \brief Indicates the validity of integer registers.
  //!
  //! Registers `0`-`31`, `epc` are valid.
  kMinidumpContextLOONGARCH64Integer = kMinidumpContextLOONGARCH64 | 0x00000002,

  //! \brief Indicates the validity of floating point registers.
  //!
  //! Floating point registers `0`-`31`, `fpcsr` and `fir` are valid
  kMinidumpContextLOONGARCH64FloatingPoint = kMinidumpContextLOONGARCH64 | 0x00000004,

  //! \brief Indicates the validity of all registers.
  kMinidumpContextLOONGARCH64All = kMinidumpContextLOONGARCH64Integer |
                              kMinidumpContextLOONGARCH64FloatingPoint,
};

//! \brief A LOONGARCH64 CPU context (register state) carried in a minidump file.
struct MinidumpContextLOONGARCH64 {
  uint64_t context_flags;

  //! \brief General purpose registers.
  uint64_t regs[32];

  //! \brief csr_era registers.
  uint64_t csr_era;

  //! \brief FPU registers.
  union {
    struct {
      float _fp_fregs;
      uint32_t _fp_pad;
    } fregs[32];
    double dregs[32];
  } fpregs;

  //! \brief Floating-point status and control register.
  uint64_t fcc;

  //! \brief Floating-point control and status register.
  uint32_t fcsr;

  //! \brief padding
  uint32_t _pad;
};

}  // namespace crashpad

#endif  // CRASHPAD_MINIDUMP_MINIDUMP_CONTEXT_H_
