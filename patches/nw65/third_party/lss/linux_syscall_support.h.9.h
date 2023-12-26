
  #undef  LSS_RETURN
  #if (defined(__i386__) || defined(__x86_64__) || defined(__ARM_ARCH_3__) \
       || defined(__ARM_EABI__) || defined(__aarch64__) || defined(__s390__)) \
       || defined(__e2k__)
  /* Failing system calls return a negative result in the range of
   * -1..-4095. These are "errno" values with the sign inverted.
   */

//----replace

  #undef  LSS_RETURN
  #if (defined(__i386__) || defined(__x86_64__) || defined(__ARM_ARCH_3__) \
       || defined(__ARM_EABI__) || defined(__aarch64__) || defined(__s390__) \
       || defined(__e2k__) || defined(__loongarch64)) // loongarch64
  /* Failing system calls return a negative result in the range of
   * -1..-4095. These are "errno" values with the sign inverted.
   */
