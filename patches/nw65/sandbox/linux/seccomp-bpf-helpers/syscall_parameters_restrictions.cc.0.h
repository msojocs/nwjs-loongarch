
#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) && \
    !defined(__arm__) && !defined(__aarch64__) &&             \
    !defined(PTRACE_GET_THREAD_AREA)
// Also include asm/ptrace-abi.h since ptrace.h in older libc (for instance
// the one in Ubuntu 16.04 LTS) is missing PTRACE_GET_THREAD_AREA.
// asm/ptrace-abi.h doesn't exist on arm32 and PTRACE_GET_THREAD_AREA isn't

//----replace

#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) && \
    !defined(__arm__) && !defined(__aarch64__) &&             \
    !defined(__loongarch64) && !defined(PTRACE_GET_THREAD_AREA) // loongarch64
// Also include asm/ptrace-abi.h since ptrace.h in older libc (for instance
// the one in Ubuntu 16.04 LTS) is missing PTRACE_GET_THREAD_AREA.
// asm/ptrace-abi.h doesn't exist on arm32 and PTRACE_GET_THREAD_AREA isn't
