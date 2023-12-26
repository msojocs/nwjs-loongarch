  unsigned int       f_flags;
  unsigned int       f_spare[4];
};
#else
struct kernel_statfs {
  unsigned long      f_type;

//----replace
  unsigned int       f_flags;
  unsigned int       f_spare[4];
};
#elif defined(__loongarch64) // loongarch64
struct kernel_statfs { // loongarch64
  unsigned long      f_type; // loongarch64
  unsigned long      f_bsize; // loongarch64
  unsigned long      f_blocks; // loongarch64
  unsigned long      f_bfree; // loongarch64
  unsigned long      f_bavail; // loongarch64
  unsigned long      f_files; // loongarch64
  unsigned long      f_ffree; // loongarch64
  struct { int val[2]; } f_fsid; // loongarch64
  unsigned long      f_namelen; // loongarch64
  unsigned long      f_frsize; // loongarch64
  unsigned long      f_flags; // loongarch64
  unsigned long      f_sparep[4]; // loongarch64
}; // loongarch64
#else
struct kernel_statfs {
  unsigned long      f_type;
