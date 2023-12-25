namespace {

#if defined(ARCH_CPU_X86_FAMILY) || defined(ARCH_CPU_ARM_FAMILY) || \
    defined(ARCH_CPU_MIPS_FAMILY)
// Number that's not currently used by any Linux kernel ABIs.
const int kInvalidSyscallNumber = 0x351d3;
#else

//----replace
namespace {

#if defined(ARCH_CPU_X86_FAMILY) || defined(ARCH_CPU_ARM_FAMILY) || \
    defined(ARCH_CPU_MIPS_FAMILY) || defined(ARCH_CPU_LOONG_FAMILY)
// Number that's not currently used by any Linux kernel ABIs.
const int kInvalidSyscallNumber = 0x351d3;
#else
