  return -ENOSYS;
}

bpf_dsl::ResultExpr CrashSIGSYS() {
  return bpf_dsl::Trap(CrashSIGSYS_Handler, NULL);
}

//----replace
  return -ENOSYS;
}

#if defined(__loongarch64) // loongarch64
intptr_t SIGSYSStatxHandler(const struct arch_seccomp_data& args, // loongarch64
                           void* fs_denied_errno) { // loongarch64
  if (args.nr == __NR_fstatat_default) { // loongarch64
    if (*reinterpret_cast<const char*>(args.args[1]) == '\0' && // loongarch64
       args.args[2] == static_cast<uint64_t>(AT_EMPTY_PATH)) { // loongarch64
      return syscall(__NR_fstat_default, static_cast<int>(args.args[0]), // loongarch64
                    NULL, AT_EMPTY_PATH, STATX_ALL, reinterpret_cast<default_stat_struct*>(args.args[4])); // loongarch64
    } // loongarch64
    return -reinterpret_cast<intptr_t>(fs_denied_errno); // loongarch64
  } // loongarch64
 // loongarch64
  CrashSIGSYS_Handler(args, fs_denied_errno); // loongarch64
 // loongarch64
  // Shoule never be reached. // loongarch64
  RAW_CHECK(false); // loongarch64
  return -ENOSYS; // loongarch64
} // loongarch64
#endif // loongarch64
 // loongarch64
bpf_dsl::ResultExpr CrashSIGSYS() {
  return bpf_dsl::Trap(CrashSIGSYS_Handler, NULL);
}
