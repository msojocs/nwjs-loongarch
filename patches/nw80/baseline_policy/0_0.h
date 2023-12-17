  // libc implementations to fstatat syscalls, and we need to rewrite them back.
  if (sysno == __NR_fstatat_default) {
    return RewriteFstatatSIGSYS(fs_denied_errno);
  }