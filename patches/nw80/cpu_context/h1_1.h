  uint64_t fpregs[32];
  uint32_t fcsr;
};

//! \brief A context structure carrying LOONGARCH64 CPU state.
struct CPUContextLOONGARCH64 {
  uint64_t regs[32];
  uint64_t csr_era;
  union {
    double dregs[32];
    struct {
      float _fp_fregs;
      uint32_t _fp_pad;
    } fregs[32];
  } fpregs;
  uint64_t fcc;
  uint32_t fcsr;
  uint32_t _pad;
};
// loongarch

//! \brief A context structure capable of carrying the context of any supported
//!     CPU architecture.