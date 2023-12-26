static constexpr __ptrace_request PTRACE_GET_THREAD_AREA_3264 =
    static_cast<__ptrace_request>(0xc4);
#define PTRACE_GET_THREAD_AREA_3264 PTRACE_GET_THREAD_AREA_3264
#endif
#endif  // !PTRACE_GET_THREAD_AREA && !PT_GET_THREAD_AREA && defined(__GLIBC__)


//----replace
static constexpr __ptrace_request PTRACE_GET_THREAD_AREA_3264 =
    static_cast<__ptrace_request>(0xc4);
#define PTRACE_GET_THREAD_AREA_3264 PTRACE_GET_THREAD_AREA_3264
#elif defined(__loongarch64)// loongarch64
static constexpr __ptrace_request PTRACE_GET_THREAD_AREA =// loongarch64
    static_cast<__ptrace_request>(25);// loongarch64
#define PTRACE_GET_THREAD_AREA PTRACE_GET_THREAD_AREA// loongarch64
#endif
#endif  // !PTRACE_GET_THREAD_AREA && !PT_GET_THREAD_AREA && defined(__GLIBC__)

