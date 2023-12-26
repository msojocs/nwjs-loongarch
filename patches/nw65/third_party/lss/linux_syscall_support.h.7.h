#define __NR_getrandom          (__NR_SYSCALL_BASE + 384)
#endif
/* End of ARM 3/EABI definitions                                             */
#elif defined(__aarch64__)
#ifndef __NR_setxattr
#define __NR_setxattr             5
#endif

//----replace
#define __NR_getrandom          (__NR_SYSCALL_BASE + 384)
#endif
/* End of ARM 3/EABI definitions                                             */
#elif defined(__aarch64__) || defined(__loongarch64) // loongarch64
#ifndef __NR_setxattr
#define __NR_setxattr             5
#endif
