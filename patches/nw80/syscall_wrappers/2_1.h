#if !defined(__NR_lstat) && !defined(__loongarch64)
  res = syscall(__NR_newfstatat, AT_FDCWD, path, stat_buf, AT_SYMLINK_NOFOLLOW);
#elif defined(__loongarch64)
  res = syscall(__NR_statx, AT_FDCWD, path, AT_SYMLINK_NOFOLLOW, STATX_ALL, stat_buf);
#else