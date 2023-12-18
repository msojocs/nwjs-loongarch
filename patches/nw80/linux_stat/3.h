#elif defined(__aarch64__)
struct kernel_stat {
  unsigned long st_dev;
  unsigned long st_ino;
  unsigned int st_mode;
  unsigned int st_nlink;
  unsigned int st_uid;
  unsigned int st_gid;
  unsigned long st_rdev;
  unsigned long __pad1;
  long st_size;
  int st_blksize;
  int __pad2;
  long st_blocks;
  long st_atime_;
  unsigned long st_atime_nsec_;
  long st_mtime_;
  unsigned long st_mtime_nsec_;
  long st_ctime_;
  unsigned long st_ctime_nsec_;
  unsigned int __unused4;
  unsigned int __unused5;
};
#endif
//----replace
#elif defined(__aarch64__) 
struct kernel_stat {
  unsigned long st_dev;
  unsigned long st_ino;
  unsigned int st_mode;
  unsigned int st_nlink;
  unsigned int st_uid;
  unsigned int st_gid;
  unsigned long st_rdev;
  unsigned long __pad1;
  long st_size;
  int st_blksize;
  int __pad2;
  long st_blocks;
  long st_atime_;
  unsigned long st_atime_nsec_;
  long st_mtime_;
  unsigned long st_mtime_nsec_;
  long st_ctime_;
  unsigned long st_ctime_nsec_;
  unsigned int __unused4;
  unsigned int __unused5;
};
#elif defined(__loongarch64)
struct kernel_timestamp {
  long         tv_sec;
  unsigned int tv_nsec;
  signed int   reserved;
};

struct kernel_stat {
  unsigned int st_mask;
  unsigned int st_blksize;
  unsigned long        st_attributes;
  unsigned int st_nlink;
  unsigned int st_uid;
  unsigned int st_gid;
  unsigned char st_mode;
  unsigned char __spare0[1];
  unsigned long        st_ino;
  unsigned long st_size;
  unsigned long st_blocks;
  unsigned long st_attributes_mask;
  struct kernel_timestamp st_atime_;
  struct kernel_timestamp st_btime_;
  struct kernel_timestamp st_ctime_;
  struct kernel_timestamp st_mtime_;
  unsigned int st_rdev_major;
  unsigned int st_rdev_minor;
  unsigned int st_dev_major;
  unsigned int st_dev_minor;
  unsigned long        st_mnt_id;
  unsigned long        __spare2;
  unsigned long        __spare3[12];
};
#endif