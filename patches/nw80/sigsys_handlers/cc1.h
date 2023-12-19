  RAW_CHECK(false);
  return -ENOSYS;
}

bpf_dsl::ResultExpr CrashSIGSYS() {
//----replace
  RAW_CHECK(false);
  return -ENOSYS;
}

#if defined(__loongarch64)
intptr_t SIGSYSStatxHandler(const struct arch_seccomp_data& args,
                           void* fs_denied_errno) {
  if (args.nr == __NR_fstatat_default) {
    if (*reinterpret_cast<const char*>(args.args[1]) == '\0' &&
       args.args[2] == static_cast<uint64_t>(AT_EMPTY_PATH)) {
      return syscall(__NR_fstat_default, static_cast<int>(args.args[0]),
                    NULL, AT_EMPTY_PATH, STATX_ALL, reinterpret_cast<default_stat_struct*>(args.args[4]));
    }
    return -reinterpret_cast<intptr_t>(fs_denied_errno);
  }

  CrashSIGSYS_Handler(args, fs_denied_errno);

  // Shoule never be reached.
  RAW_CHECK(false);
  return -ENOSYS;
}
#endif

bpf_dsl::ResultExpr CrashSIGSYS() {