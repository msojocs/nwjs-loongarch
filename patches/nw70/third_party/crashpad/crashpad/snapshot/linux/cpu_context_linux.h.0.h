
#endif  // ARCH_CPU_MIPS_FAMILY || DOXYGEN

}  // namespace internal
}  // namespace crashpad


//----replace

#endif  // ARCH_CPU_MIPS_FAMILY || DOXYGEN

#if defined(ARCH_CPU_LOONG64) || DOXYGEN

//! \brief Initializes GPR state in a CPUContextLOONG64 from a native context
//!     structure on Linux.
//!
//! Floating point state is initialized to zero.
//!
//! \param[in] thread_context The native thread context.
//! \param[out] context The CPUContextLOONGARCH64 structure to initialize.
void InitializeCPUContextLOONGARCH64_NoFloatingPoint(
    const ThreadContext::t64_t& thread_context,
    CPUContextLOONGARCH64* context);
//! \brief Initializes FPU state in a CPUContextLOONG64 from a native fpu
//!     signal context structure on Linux.
//!
//! General purpose registers are not initialized.
//!
//! \param[in] float_context The native fpu context.
//! \param[out] context The CPUContextLOONG64 structure to initialize.
void InitializeCPUContextLOONGARCH64_OnlyFPU(
    const FloatContext::f64_t& float_context,
    CPUContextLOONGARCH64* context);

//! \brief Initializes a CPUContextLOONGARCH64 structure from native context
//!     structures on Linux.
//!
//! This function has template specializations for LOONGARCH64 architecture
//! contexts, using ContextTraits32 or ContextTraits64 as template parameter,
//! respectively.
//!
//! \param[in] thread_context The native thread context.
//! \param[in] float_context The native float context.
//! \param[out] context The CPUContextLOONGARCH64 structure to initialize.
void InitializeCPUContextLOONGARCH64(
    const ThreadContext::t64_t& thread_context,
    const FloatContext::f64_t& float_context,
    CPUContextLOONGARCH64* context);
#endif  // ARCH_CPU_LOONG64 || DOXYGEN

}  // namespace internal
}  // namespace crashpad

