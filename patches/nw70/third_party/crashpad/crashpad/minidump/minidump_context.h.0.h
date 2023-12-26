  uint64_t fir;
};

}  // namespace crashpad

#endif  // CRASHPAD_MINIDUMP_MINIDUMP_CONTEXT_H_

//----replace
  uint64_t fir;
};

//! \brief LOONGARCH64-specifc flags for MinidumpContextLOONGARCH64::context_flags.// loongarch64
//! Based on minidump_cpu_loongarch64.h from breakpad// loongarch64
enum MinidumpContextLOONGARCH64Flags : uint32_t {// loongarch64
  //! \brief Identifies the context structure as LOONGARCH64.// loongarch64
  kMinidumpContextLOONGARCH64 = 0x00800000,// loongarch64
// loongarch64
  //! \brief Indicates the validity of integer registers.// loongarch64
  //!// loongarch64
  //! Registers `0`-`31`, `epc` are valid.// loongarch64
  kMinidumpContextLOONGARCH64Integer = kMinidumpContextLOONGARCH64 | 0x00000002,// loongarch64
// loongarch64
  //! \brief Indicates the validity of floating point registers.// loongarch64
  //!// loongarch64
  //! Floating point registers `0`-`31`, `fpcsr` and `fir` are valid// loongarch64
  kMinidumpContextLOONGARCH64FloatingPoint = kMinidumpContextLOONGARCH64 | 0x00000004,// loongarch64
// loongarch64
  //! \brief Indicates the validity of all registers.// loongarch64
  kMinidumpContextLOONGARCH64All = kMinidumpContextLOONGARCH64Integer |// loongarch64
                              kMinidumpContextLOONGARCH64FloatingPoint,// loongarch64
};// loongarch64
// loongarch64
//! \brief A LOONGARCH64 CPU context (register state) carried in a minidump file.// loongarch64
struct MinidumpContextLOONGARCH64 {// loongarch64
  uint64_t context_flags;// loongarch64
// loongarch64
  //! \brief General purpose registers.// loongarch64
  uint64_t regs[32];// loongarch64
// loongarch64
  //! \brief csr_era registers.// loongarch64
  uint64_t csr_era;// loongarch64
// loongarch64
  //! \brief FPU registers.// loongarch64
  union {// loongarch64
    struct {// loongarch64
      float _fp_fregs;// loongarch64
      uint32_t _fp_pad;// loongarch64
    } fregs[32];// loongarch64
    double dregs[32];// loongarch64
  } fpregs;// loongarch64
// loongarch64
  //! \brief Floating-point status and control register.// loongarch64
  uint64_t fcc;// loongarch64
// loongarch64
  //! \brief Floating-point control and status register.// loongarch64
  uint32_t fcsr;// loongarch64
// loongarch64
  //! \brief padding// loongarch64
  uint32_t _pad;// loongarch64
};// loongarch64
// loongarch64
}  // namespace crashpad

#endif  // CRASHPAD_MINIDUMP_MINIDUMP_CONTEXT_H_
