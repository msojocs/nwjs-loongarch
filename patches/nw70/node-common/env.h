#endif

// Detect word size:
#if defined (__x86_64__)
// This also works for the x32 ABI, which has a 64-bit word size.
#  define BASE64_WORDSIZE 64
#elif defined (_INTEGRAL_MAX_BITS)
//----replace
#endif

// Detect word size:
#if defined (__x86_64__) || defined(__loongarch64)
// This also works for the x32 ABI, which has a 64-bit word size.
#  define BASE64_WORDSIZE 64
#elif defined (_INTEGRAL_MAX_BITS)
