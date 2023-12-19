  return bpf_dsl::Trap(SIGSYSFstatatHandler,
                       reinterpret_cast<void*>(fs_denied_errno));
}

#if defined(__NR_socketcall)
//----replace
  return bpf_dsl::Trap(SIGSYSFstatatHandler,
                       reinterpret_cast<void*>(fs_denied_errno));
}

#if defined(__loongarch64)
bpf_dsl::ResultExpr RewriteStatxSIGSYS(int fs_denied_errno) {
  return bpf_dsl::Trap(SIGSYSStatxHandler,
                      reinterpret_cast<void*>(fs_denied_errno));
}
#endif

#if defined(__NR_socketcall)