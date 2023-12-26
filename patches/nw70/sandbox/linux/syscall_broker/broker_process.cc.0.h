  // and are default disabled in Android. So, we should refuse to broker them
  // to be consistent with the platform's restrictions.
  switch (sysno) {
#if !defined(__aarch64__) && !BUILDFLAG(IS_ANDROID)
    case __NR_access:
#endif
    case __NR_faccessat:
    case __NR_faccessat2:
      return !fast_check || policy_->allowed_command_set.test(COMMAND_ACCESS);

#if !defined(__aarch64__) && !BUILDFLAG(IS_ANDROID)
    case __NR_mkdir:
#endif
    case __NR_mkdirat:
      return !fast_check || policy_->allowed_command_set.test(COMMAND_MKDIR);

#if !defined(__aarch64__) && !BUILDFLAG(IS_ANDROID)
    case __NR_open:
#endif
    case __NR_openat:
      return !fast_check || policy_->allowed_command_set.test(COMMAND_OPEN);

#if !defined(__aarch64__) && !BUILDFLAG(IS_ANDROID)
    case __NR_readlink:
#endif
    case __NR_readlinkat:
      return !fast_check || policy_->allowed_command_set.test(COMMAND_READLINK);

#if !defined(__aarch64__) && !BUILDFLAG(IS_ANDROID)
    case __NR_rename:
#endif
    case __NR_renameat:
    case __NR_renameat2:
      return !fast_check || policy_->allowed_command_set.test(COMMAND_RENAME);

#if !defined(__aarch64__) && !BUILDFLAG(IS_ANDROID)
    case __NR_rmdir:
      return !fast_check || policy_->allowed_command_set.test(COMMAND_RMDIR);
#endif

#if !defined(__aarch64__) && !BUILDFLAG(IS_ANDROID)
    case __NR_stat:
    case __NR_lstat:
#endif

//----replace
  // and are default disabled in Android. So, we should refuse to broker them
  // to be consistent with the platform's restrictions.
  switch (sysno) {
#if !defined(__aarch64__) && !BUILDFLAG(IS_ANDROID) && !defined(__loongarch64)// loongarch64
    case __NR_access:
#endif
    case __NR_faccessat:
    case __NR_faccessat2:
      return !fast_check || policy_->allowed_command_set.test(COMMAND_ACCESS);

#if !defined(__aarch64__) && !BUILDFLAG(IS_ANDROID) && !defined(__loongarch64)// loongarch64
    case __NR_mkdir:
#endif
    case __NR_mkdirat:
      return !fast_check || policy_->allowed_command_set.test(COMMAND_MKDIR);

#if !defined(__aarch64__) && !BUILDFLAG(IS_ANDROID) && !defined(__loongarch64)// loongarch64
    case __NR_open:
#endif
    case __NR_openat:
      return !fast_check || policy_->allowed_command_set.test(COMMAND_OPEN);

#if !defined(__aarch64__) && !BUILDFLAG(IS_ANDROID) && !defined(__loongarch64)// loongarch64
    case __NR_readlink:
#endif
    case __NR_readlinkat:
      return !fast_check || policy_->allowed_command_set.test(COMMAND_READLINK);

#if !defined(__aarch64__) && !BUILDFLAG(IS_ANDROID) && !defined(__loongarch64)// loongarch64
    case __NR_rename:
#endif
#if !defined(__loongarch64)// loongarch64
    case __NR_renameat:
#endif// loongarch64
    case __NR_renameat2:
      return !fast_check || policy_->allowed_command_set.test(COMMAND_RENAME);

#if !defined(__aarch64__) && !BUILDFLAG(IS_ANDROID) && !defined(__loongarch64)// loongarch64
    case __NR_rmdir:
      return !fast_check || policy_->allowed_command_set.test(COMMAND_RMDIR);
#endif

#if !defined(__aarch64__) && !BUILDFLAG(IS_ANDROID) && !defined(__loongarch64)// loongarch64
    case __NR_stat:
    case __NR_lstat:
#endif
