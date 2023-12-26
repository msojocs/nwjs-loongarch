
int sys_stat(const char* path, struct kernel_stat* stat_buf) {
  int res;
#if !defined(__NR_stat)
  res = syscall(__NR_newfstatat, AT_FDCWD, path, stat_buf, 0);
#else
  res = syscall(__NR_stat, path, stat_buf);
#endif

//----replace

int sys_stat(const char* path, struct kernel_stat* stat_buf) {
  int res;
#if !defined(__NR_stat) && !defined(__loongarch64)// loongarch64
  res = syscall(__NR_newfstatat, AT_FDCWD, path, stat_buf, 0);
#elif defined(__loongarch64)// loongarch64
  res = syscall(__NR_statx, AT_FDCWD, path, 0, STATX_ALL, stat_buf);// loongarch64
#else
  res = syscall(__NR_stat, path, stat_buf);
#endif
