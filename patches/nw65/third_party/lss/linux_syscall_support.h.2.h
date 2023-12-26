  long               ru_nivcsw;
};

#if defined(__i386__) || defined(__ARM_EABI__) || defined(__ARM_ARCH_3__) \
  || defined(__PPC__) || (defined(__s390__) && !defined(__s390x__)) \
  || defined(__e2k__)

//----replace
  long               ru_nivcsw;
};

#if defined(__loongarch64) // loongarch64
/* include/linux/stat.h								*/ // loongarch64
struct kernel_timestamp { // loongarch64
  long		tv_sec; // loongarch64
  unsigned int 	tv_nsec; // loongarch64
  signed int	reserved; // loongarch64
}; // loongarch64
#endif // loongarch64
 // loongarch64
#if defined(__i386__) || defined(__ARM_EABI__) || defined(__ARM_ARCH_3__) \
  || defined(__PPC__) || (defined(__s390__) && !defined(__s390x__)) \
  || defined(__e2k__)
