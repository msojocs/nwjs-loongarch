template <class Traits>
struct Siginfo {
  int32_t signo;
#ifdef ARCH_CPU_MIPS_FAMILY
  // Attribute order for signo_t defined in kernel is different for MIPS.
  int32_t code;
  int32_t err;

//----replace
template <class Traits>
struct Siginfo {
  int32_t signo;
#if defined(ARCH_CPU_MIPS_FAMILY) || defined(ARCH_CPU_LOONG64_FAMILY)
  // Attribute order for signo_t defined in kernel is different for MIPS.
  int32_t code;
  int32_t err;
