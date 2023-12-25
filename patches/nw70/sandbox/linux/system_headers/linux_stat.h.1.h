  unsigned int __unused4;
  unsigned int __unused5;
};
#endif

#if !defined(AT_EMPTY_PATH)

//----replace
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

#if defined(__loongarch64)
#define AT_STATX_SYNC_AS_STAT 0x0000
#define STATX_ALL 0x00000fffU
#endif

#if !defined(AT_EMPTY_PATH)
