  unsigned int __unused4;
  unsigned int __unused5;
};
#endif

#if !defined(AT_EMPTY_PATH)

//----replace
  unsigned int __unused4;
  unsigned int __unused5;
};
#elif defined(__loongarch64) // loongarch64
struct kernel_timestamp { // loongarch64
  long         tv_sec; // loongarch64
  unsigned int tv_nsec; // loongarch64
  signed int   reserved; // loongarch64
}; // loongarch64
 // loongarch64
struct kernel_stat { // loongarch64
  unsigned int st_mask; // loongarch64
  unsigned int st_blksize; // loongarch64
  unsigned long        st_attributes; // loongarch64
  unsigned int st_nlink; // loongarch64
  unsigned int st_uid; // loongarch64
  unsigned int st_gid; // loongarch64
  unsigned char st_mode; // loongarch64
  unsigned char __spare0[1]; // loongarch64
  unsigned long        st_ino; // loongarch64
  unsigned long st_size; // loongarch64
  unsigned long st_blocks; // loongarch64
  unsigned long st_attributes_mask; // loongarch64
  struct kernel_timestamp st_atime_; // loongarch64
  struct kernel_timestamp st_btime_; // loongarch64
  struct kernel_timestamp st_ctime_; // loongarch64
  struct kernel_timestamp st_mtime_; // loongarch64
  unsigned int st_rdev_major; // loongarch64
  unsigned int st_rdev_minor; // loongarch64
  unsigned int st_dev_major; // loongarch64
  unsigned int st_dev_minor; // loongarch64
  unsigned long        st_mnt_id; // loongarch64
  unsigned long        __spare2; // loongarch64
  unsigned long        __spare3[12]; // loongarch64
}; // loongarch64
#endif // loongarch64
 // loongarch64
#if defined(__loongarch64) // loongarch64
#define AT_STATX_SYNC_AS_STAT 0x0000 // loongarch64
#define STATX_ALL 0x00000fffU // loongarch64
#endif

#if !defined(AT_EMPTY_PATH)
