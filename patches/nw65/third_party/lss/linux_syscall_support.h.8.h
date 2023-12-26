#ifndef __NR_getrandom
#define __NR_getrandom          278
#endif
/* End of aarch64 definitions                                                */
#elif defined(__x86_64__)
#ifndef __NR_pread64
#define __NR_pread64             17

//----replace
#ifndef __NR_getrandom
#define __NR_getrandom          278
#endif
/* End of aarch64 definitions and loongarch64                             */  // loongarch64
#elif defined(__x86_64__)
#ifndef __NR_pread64
#define __NR_pread64             17
