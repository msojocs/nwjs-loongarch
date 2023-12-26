                       reinterpret_cast<void*>(fs_denied_errno));
}

void AllocateCrashKeys() {
  if (seccomp_crash_key)
    return;

//----replace
                       reinterpret_cast<void*>(fs_denied_errno));
}

#if defined(__loongarch64)// loongarch64
bpf_dsl::ResultExpr RewriteStatxSIGSYS(int fs_denied_errno) {// loongarch64
  return bpf_dsl::Trap(SIGSYSStatxHandler,// loongarch64
                      reinterpret_cast<void*>(fs_denied_errno));// loongarch64
}// loongarch64
#endif// loongarch64
// loongarch64
void AllocateCrashKeys() {
  if (seccomp_crash_key)
    return;
