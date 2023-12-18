#elif defined(__aarch64__)

#include <asm-generic/unistd.h>
#define MIN_SYSCALL 0u
#define MAX_PUBLIC_SYSCALL __NR_syscalls
#define MAX_SYSCALL MAX_PUBLIC_SYSCALL

#else
#error "Unsupported architecture"
//----replace
#elif defined(__aarch64__)

#include <asm-generic/unistd.h>
#define MIN_SYSCALL 0u
#define MAX_PUBLIC_SYSCALL __NR_syscalls
#define MAX_SYSCALL MAX_PUBLIC_SYSCALL

#elif defined(__loongarch64)
#include <asm-generic/unistd.h>
#define MIN_SYSCALL 0u
#define MAX_PUBLIC_SYSCALL __NR_syscalls
#define MAX_SYSCALL_MAX_PUBLIC_SYSCALL

#else
#error "Unsupported architecture"