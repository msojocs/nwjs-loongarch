#if defined(__NR_fstatat64)
    case __NR_fstatat64:
#endif
#if defined(__x86_64__) || defined(__aarch64__)
    case __NR_newfstatat:
#endif
      return !fast_check || policy_->allowed_command_set.test(COMMAND_STAT);

//----replace
#if defined(__NR_fstatat64)
    case __NR_fstatat64:
#endif
#if defined(__x86_64__) || defined(__aarch64__)  // loongarch64
    case __NR_newfstatat:
#endif
      return !fast_check || policy_->allowed_command_set.test(COMMAND_STAT);
