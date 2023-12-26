  }

#if defined(__x86_64__) || defined(__aarch64__) || \
   (defined(__mips__) && _MIPS_SIM == _ABI64)

  struct kernel_stat st;
  if (sys_fstat(fd, &st) == -1 || st.st_size < 0) {

//----replace
  }

#if defined(__x86_64__) || defined(__aarch64__) || \
   (defined(__mips__) && _MIPS_SIM == _ABI64) || \// loongarch64
    defined(__loongarch64)// loongarch64

  struct kernel_stat st;
  if (sys_fstat(fd, &st) == -1 || st.st_size < 0) {
