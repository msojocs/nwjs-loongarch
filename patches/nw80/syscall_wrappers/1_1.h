#if !defined(__NR_stat) && !defined(__loongarch64)
  res = syscall(__NR_newfstatat, AT_FDCWD, path, stat_buf, 0);
#elif defined(__loongarch64)
  res = syscall(__NR_statx, AT_FDCWD, path, 0, STATX_ALL, stat_buf);
#else