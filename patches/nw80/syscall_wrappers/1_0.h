#if !defined(__NR_stat)
  res = syscall(__NR_newfstatat, AT_FDCWD, path, stat_buf, 0);
#else