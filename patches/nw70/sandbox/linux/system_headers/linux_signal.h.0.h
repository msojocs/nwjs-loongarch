// (not undefined, but defined different values and in different memory
// layouts). So, fill the gap here.
#if defined(__i386__) || defined(__x86_64__) || defined(__arm__) || \
    defined(__aarch64__)

#define LINUX_SIGHUP 1
#define LINUX_SIGINT 2

//----replace
// (not undefined, but defined different values and in different memory
// layouts). So, fill the gap here.
#if defined(__i386__) || defined(__x86_64__) || defined(__arm__) || \
    defined(__aarch64__) || defined(__loongarch64)// loongarch64

#define LINUX_SIGHUP 1
#define LINUX_SIGINT 2
