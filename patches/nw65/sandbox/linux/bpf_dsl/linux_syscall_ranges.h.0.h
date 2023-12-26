#define MAX_PUBLIC_SYSCALL __NR_syscalls
#define MAX_SYSCALL MAX_PUBLIC_SYSCALL

#else
#error "Unsupported architecture"
#endif

//----replace
#define MAX_PUBLIC_SYSCALL __NR_syscalls
#define MAX_SYSCALL MAX_PUBLIC_SYSCALL

#elif defined(__loongarch64) // loongarch64
#include <asm-generic/unistd.h> // loongarch64
#define MIN_SYSCALL 0u // loongarch64
#define MAX_PUBLIC_SYSCALL __NR_syscalls // loongarch64
#define MAX_SYSCALL_MAX_PUBLIC_SYSCALL // loongarch64
 // loongarch64
#else
#error "Unsupported architecture"
#endif
