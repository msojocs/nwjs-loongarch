      return !fast_check || policy_->allowed_command_set.test(COMMAND_STAT);
#endif

#if !defined(__aarch64__) && !BUILDFLAG(IS_ANDROID)
    case __NR_unlink:
      return !fast_check || policy_->allowed_command_set.test(COMMAND_UNLINK);
#endif

//----replace
      return !fast_check || policy_->allowed_command_set.test(COMMAND_STAT);
#endif

#if !defined(__aarch64__) && !BUILDFLAG(IS_ANDROID) && !defined(__loongarch64)// loongarch64
    case __NR_unlink:
      return !fast_check || policy_->allowed_command_set.test(COMMAND_UNLINK);
#endif
