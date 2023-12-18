#endif

#if !defined(AT_EMPTY_PATH)
//----replace
#endif

#if defined(__loongarch64)
#define AT_STATX_SYNC_AS_STAT 0x0000
#define STATX_ALL 0x00000fffU
#endif
// loong64
#if !defined(AT_EMPTY_PATH)