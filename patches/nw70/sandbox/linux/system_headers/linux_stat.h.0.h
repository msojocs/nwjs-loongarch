  int st_blocks;
  int st_pad4[14];
};
#elif defined(__aarch64__)
struct kernel_stat {
  unsigned long st_dev;
  unsigned long st_ino;

//----replace
  int st_blocks;
  int st_pad4[14];
};
#elif defined(__aarch64__) 
struct kernel_stat {
  unsigned long st_dev;
  unsigned long st_ino;
