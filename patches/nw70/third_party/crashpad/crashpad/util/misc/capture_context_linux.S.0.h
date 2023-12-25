// compatibility with both possibilities.
#define CAPTURECONTEXT_SYMBOL _ZN8crashpad14CaptureContextEP10ucontext_t
#define CAPTURECONTEXT_SYMBOL2 _ZN8crashpad14CaptureContextEP8ucontext

  .text
  .globl CAPTURECONTEXT_SYMBOL
  .globl CAPTURECONTEXT_SYMBOL2
#if defined(__i386__) || defined(__x86_64__)
  .balign 16, 0x90
#elif defined(__arm__) || defined(__aarch64__)
  .balign 4, 0x0
  .type CAPTURECONTEXT_SYMBOL, %function
  .type CAPTURECONTEXT_SYMBOL2, %function
#elif defined(__mips__)
  .balign 4, 0x0
#endif

CAPTURECONTEXT_SYMBOL:
CAPTURECONTEXT_SYMBOL2:
  CRASHPAD_AARCH64_VALID_CALL_TARGET

#if defined(__i386__)

//----replace
// compatibility with both possibilities.
#define CAPTURECONTEXT_SYMBOL _ZN8crashpad14CaptureContextEP10ucontext_t
#define CAPTURECONTEXT_SYMBOL2 _ZN8crashpad14CaptureContextEP8ucontext
#define CAPTURECONTEXT_SYMBOL3 _ZN8crashpad14CaptureContextEPNS_16NativeCPUContextE

  .text
  .globl CAPTURECONTEXT_SYMBOL
  .globl CAPTURECONTEXT_SYMBOL2
  .globl CAPTURECONTEXT_SYMBOL3
#if defined(__i386__) || defined(__x86_64__)
  .balign 16, 0x90
#elif defined(__arm__) || defined(__aarch64__) || defined(__loongarch64)
  .balign 4, 0x0
  .type CAPTURECONTEXT_SYMBOL, %function
  .type CAPTURECONTEXT_SYMBOL2, %function
  .type CAPTURECONTEXT_SYMBOL3, %function
#elif defined(__mips__)
  .balign 4, 0x0
#endif

CAPTURECONTEXT_SYMBOL:
CAPTURECONTEXT_SYMBOL2:
CAPTURECONTEXT_SYMBOL3:
  CRASHPAD_AARCH64_VALID_CALL_TARGET

#if defined(__i386__)
