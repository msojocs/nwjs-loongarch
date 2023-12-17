#if !defined(__NR_lstat)
  res = syscall(__NR_newfstatat, AT_FDCWD, path, stat_buf, AT_SYMLINK_NOFOLLOW);
#else