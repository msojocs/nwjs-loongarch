    case __NR_rename:
#endif
    case __NR_renameat:
    case __NR_renameat2:
      return !fast_check || policy_->allowed_command_set.test(COMMAND_RENAME);
//----replace
    case __NR_rename:
#endif
#if !defined(__loongarch64)
    case __NR_renameat:
#endif
    case __NR_renameat2:
      return !fast_check || policy_->allowed_command_set.test(COMMAND_RENAME);