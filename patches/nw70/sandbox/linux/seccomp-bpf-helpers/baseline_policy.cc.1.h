  }

#if defined(__i386__) || defined(__x86_64__) || defined(__mips__) || \
    defined(__aarch64__)
  if (sysno == __NR_mmap)
    return RestrictMmapFlags();
#endif

//----replace
  }

#if defined(__i386__) || defined(__x86_64__) || defined(__mips__) || \
    defined(__aarch64__) || defined(__loongarch64)
  if (sysno == __NR_mmap)
    return RestrictMmapFlags();
#endif
