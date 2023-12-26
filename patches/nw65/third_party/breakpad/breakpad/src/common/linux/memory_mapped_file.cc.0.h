  }

#if defined(__x86_64__) || defined(__aarch64__) || \
   (defined(__mips__) && _MIPS_SIM == _ABI64)

  struct kernel_stat st;
  if (sys_fstat(fd, &st) == -1 || st.st_size < 0) {
#else
  struct kernel_stat64 st;
  if (sys_fstat64(fd, &st) == -1 || st.st_size < 0) {

//----replace
  }

#if defined(__x86_64__) || defined(__aarch64__) || \
   (defined(__mips__) && _MIPS_SIM == _ABI64) \

  struct kernel_stat st;
  if (sys_fstat(fd, &st) == -1 || st.st_size < 0) {
#elif defined(__loongarch64) // loongarch64
  struct kernel_stat st; // loongarch64
  if (sys_statx(fd, NULL, AT_EMPTY_PATH, STATX_SIZE, &st) // loongarch64
      == -1 || st.st_size < 0) { // loongarch64
#else
  struct kernel_stat64 st;
  if (sys_fstat64(fd, &st) == -1 || st.st_size < 0) {
