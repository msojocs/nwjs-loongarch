#elif __riscv_xlen == 32
#define V8_TARGET_ARCH_RISCV32 1
#endif
#else
#error Target architecture was not detected as supported by v8
#endif

//----replace
#elif __riscv_xlen == 32
#define V8_TARGET_ARCH_RISCV32 1
#endif
#elif defined(__loongarch64)// loongarch64
#define V8_TARGET_ARCH_LOONG64 1// loongarch64
#else
#error Target architecture was not detected as supported by v8
#endif
