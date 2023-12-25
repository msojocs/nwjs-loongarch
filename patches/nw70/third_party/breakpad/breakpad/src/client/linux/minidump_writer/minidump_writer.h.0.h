
#if defined(__aarch64__)
typedef struct fpsimd_context fpstate_t;
#elif !defined(__ARM_EABI__) && !defined(__mips__)
typedef std::remove_pointer<fpregset_t>::type fpstate_t;
#endif


//----replace

#if defined(__aarch64__)
typedef struct fpsimd_context fpstate_t;
#elif !defined(__ARM_EABI__) && !defined(__mips__) && !defined(__loongarch64)
typedef std::remove_pointer<fpregset_t>::type fpstate_t;
#endif

