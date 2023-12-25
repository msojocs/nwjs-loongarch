
#elif defined(__loongarch__)
#define DAWN_PLATFORM_IS_LOONGARCH 1
#if _LOONGARCH_SIM == _ABILP32
#define DAWN_PLATFORM_IS_LOONGARCH32 1
#else
#define DAWN_PLATFORM_IS_LOONGARCH64 1
#endif

#elif defined(__riscv)

//----replace

#elif defined(__loongarch__)
#define DAWN_PLATFORM_IS_LOONGARCH 1
#if __loongarch_grlen == 64
#define DAWN_PLATFORM_IS_LOONGARCH64 1
#else
#define DAWN_PLATFORM_IS_LOONGARCH32 1
#endif

#elif defined(__riscv)
