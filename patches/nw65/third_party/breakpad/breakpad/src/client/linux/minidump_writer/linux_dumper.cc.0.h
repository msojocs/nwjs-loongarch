  // Check to see if someone actually named their executable 'foo (deleted)'.
  struct kernel_stat exe_stat;
  struct kernel_stat new_path_stat;
  if (sys_stat(exe_link, &exe_stat) == 0 &&
      sys_stat(new_path, &new_path_stat) == 0 &&
      exe_stat.st_dev == new_path_stat.st_dev &&
      exe_stat.st_ino == new_path_stat.st_ino) {
    return false;
  }


//----replace
  // Check to see if someone actually named their executable 'foo (deleted)'.
  struct kernel_stat exe_stat;
  struct kernel_stat new_path_stat;
#if defined(__loongarch64) // loongarch64
  if (sys_statx(AT_FDCWD, exe_link, AT_STATX_SYNC_AS_STAT, STATX_ALL, &exe_stat) == 0 && // loongarch64
      sys_statx(AT_FDCWD, new_path, AT_STATX_SYNC_AS_STAT, STATX_ALL, &new_path_stat) == 0 && // loongarch64
      exe_stat.st_dev_major == new_path_stat.st_dev_major && // loongarch64
      exe_stat.st_dev_minor == new_path_stat.st_dev_minor && // loongarch64
      exe_stat.st_ino == new_path_stat.st_ino) { // loongarch64
#else // loongarch64
  if (sys_stat(exe_link, &exe_stat) == 0 &&
      sys_stat(new_path, &new_path_stat) == 0 &&
      exe_stat.st_dev == new_path_stat.st_dev &&
      exe_stat.st_ino == new_path_stat.st_ino) {
#endif // loongarch64
    return false;
  }

