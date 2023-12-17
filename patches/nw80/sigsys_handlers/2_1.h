SANDBOX_EXPORT bpf_dsl::ResultExpr RewriteFstatatSIGSYS(int fs_denied_errno);
#if defined(__loongarch64)
SANDBOX_EXPORT bpf_dsl::ResultExpr RewriteStatxSIGSYS(int fs_denied_errno);
#endif

#if defined(__NR_socketcall)