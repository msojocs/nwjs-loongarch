  uint64_t fir;
};

//! \brief A context structure capable of carrying the context of any supported
//!     CPU architecture.
struct CPUContext {

//----replace
  uint64_t fir;
};

//! \brief A context structure carrying LOONGARCH64 CPU state.// loongarch64
struct CPUContextLOONGARCH64 {// loongarch64
  uint64_t regs[32];// loongarch64
  uint64_t csr_era;// loongarch64
  union {// loongarch64
    double dregs[32];// loongarch64
    struct {// loongarch64
      float _fp_fregs;// loongarch64
      uint32_t _fp_pad;// loongarch64
    } fregs[32];// loongarch64
  } fpregs;// loongarch64
  uint64_t fcc;// loongarch64
  uint32_t fcsr;// loongarch64
  uint32_t _pad;// loongarch64
};// loongarch64
// loongarch64
//! \brief A context structure capable of carrying the context of any supported
//!     CPU architecture.
struct CPUContext {
