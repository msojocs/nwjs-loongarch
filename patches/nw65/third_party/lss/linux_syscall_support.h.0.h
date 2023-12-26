 */
#if (defined(__i386__) || defined(__x86_64__) || defined(__ARM_ARCH_3__) ||   \
     defined(__mips__) || defined(__PPC__) || defined(__ARM_EABI__) || \
     defined(__aarch64__) || defined(__s390__)) || defined(__e2k__)  \
  && (defined(__linux) || defined(__ANDROID__))

#ifndef SYS_CPLUSPLUS
#ifdef __cplusplus

//----replace
 */
#if (defined(__i386__) || defined(__x86_64__) || defined(__ARM_ARCH_3__) ||   \
     defined(__mips__) || defined(__PPC__) || defined(__ARM_EABI__) || \
     defined(__aarch64__) || defined(__s390__) || defined(__e2k__) || \
     defined(__loongarch64)) && (defined(__linux) || defined(__ANDROID__)) // loongarch64

#ifndef SYS_CPLUSPLUS
#ifdef __cplusplus
