  // libc implementations to fstatat syscalls, and we need to rewrite them back.
  if (sysno == __NR_fstatat_default) {
#if defined(__loongarch64)
    return RewriteStatxSIGSYS(fs_denied_errno);
#else
    return RewriteFstatatSIGSYS(fs_denied_errno);
#endif
  }