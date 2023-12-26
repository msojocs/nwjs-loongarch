};
#endif


/* Definitions missing from the standard header files                        */
#ifndef O_DIRECTORY

//----replace
};
#endif

#if defined(__loongarch64) // loongarch64
struct kernel_stat { // loongarch64
 unsigned int	st_mask; // loongarch64
 unsigned int	st_blksize; // loongarch64
 unsigned long	st_attributes; // loongarch64
 unsigned int	st_nlink; // loongarch64
 unsigned int	st_uid; // loongarch64
 unsigned int	st_gid; // loongarch64
 unsigned char	st_mode; // loongarch64
 unsigned char	__spare0[1]; // loongarch64
 unsigned long	st_ino; // loongarch64
 unsigned long	st_size; // loongarch64
 unsigned long	st_blocks; // loongarch64
 unsigned long	st_attributes_mask; // loongarch64
 struct kernel_timestamp  st_atime_; // loongarch64
 struct kernel_timestamp  st_btime_; // loongarch64
 struct kernel_timestamp  st_ctime_; // loongarch64
 struct kernel_timestamp  st_mtime_; // loongarch64
 unsigned int	st_rdev_major; // loongarch64
 unsigned int	st_rdev_minor; // loongarch64
 unsigned int	st_dev_major; // loongarch64
 unsigned int	st_dev_minor; // loongarch64
 unsigned long	st_mnt_id; // loongarch64
 unsigned long	__spare2; // loongarch64
 unsigned long	__spare3[12]; // loongarch64
}; // loongarch64
#endif // loongarch64

/* Definitions missing from the standard header files                        */
#ifndef O_DIRECTORY
