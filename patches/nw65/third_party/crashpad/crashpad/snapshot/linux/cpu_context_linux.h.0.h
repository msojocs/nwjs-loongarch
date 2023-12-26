
#endif  // ARCH_CPU_MIPS_FAMILY || DOXYGEN

}  // namespace internal
}  // namespace crashpad


//----replace

#endif  // ARCH_CPU_MIPS_FAMILY || DOXYGEN

#if defined(ARCH_CPU_LOONG64) || DOXYGEN // loongarch64
 // loongarch64
//! \brief Initializes GPR state in a CPUContextLOONG64 from a native context // loongarch64
//!     structure on Linux. // loongarch64
//! // loongarch64
//! Floating point state is initialized to zero. // loongarch64
//! // loongarch64
//! \param[in] thread_context The native thread context. // loongarch64
//! \param[out] context The CPUContextLOONGARCH64 structure to initialize. // loongarch64
void InitializeCPUContextLOONGARCH64_NoFloatingPoint( // loongarch64
    const ThreadContext::t64_t& thread_context, // loongarch64
    CPUContextLOONGARCH64* context); // loongarch64
//! \brief Initializes FPU state in a CPUContextLOONG64 from a native fpu // loongarch64
//!     signal context structure on Linux. // loongarch64
//! // loongarch64
//! General purpose registers are not initialized. // loongarch64
//! // loongarch64
//! \param[in] float_context The native fpu context. // loongarch64
//! \param[out] context The CPUContextLOONG64 structure to initialize. // loongarch64
void InitializeCPUContextLOONGARCH64_OnlyFPU( // loongarch64
    const FloatContext::f64_t& float_context, // loongarch64
    CPUContextLOONGARCH64* context); // loongarch64
 // loongarch64
//! \brief Initializes a CPUContextLOONGARCH64 structure from native context // loongarch64
//!     structures on Linux. // loongarch64
//! // loongarch64
//! This function has template specializations for LOONGARCH64 architecture // loongarch64
//! contexts, using ContextTraits32 or ContextTraits64 as template parameter, // loongarch64
//! respectively. // loongarch64
//! // loongarch64
//! \param[in] thread_context The native thread context. // loongarch64
//! \param[in] float_context The native float context. // loongarch64
//! \param[out] context The CPUContextLOONGARCH64 structure to initialize. // loongarch64
void InitializeCPUContextLOONGARCH64( // loongarch64
    const ThreadContext::t64_t& thread_context, // loongarch64
    const FloatContext::f64_t& float_context, // loongarch64
    CPUContextLOONGARCH64* context); // loongarch64
#endif  // ARCH_CPU_LOONG64 || DOXYGEN // loongarch64
 // loongarch64
}  // namespace internal
}  // namespace crashpad

