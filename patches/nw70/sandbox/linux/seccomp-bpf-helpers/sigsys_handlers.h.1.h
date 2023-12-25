SANDBOX_EXPORT bpf_dsl::ResultExpr CrashSIGSYSPtrace();
SANDBOX_EXPORT bpf_dsl::ResultExpr RewriteSchedSIGSYS();
SANDBOX_EXPORT bpf_dsl::ResultExpr RewriteFstatatSIGSYS(int fs_denied_errno);

// Allocates a crash key so that Seccomp information can be recorded.
void AllocateCrashKeys();

//----replace
SANDBOX_EXPORT bpf_dsl::ResultExpr CrashSIGSYSPtrace();
SANDBOX_EXPORT bpf_dsl::ResultExpr RewriteSchedSIGSYS();
SANDBOX_EXPORT bpf_dsl::ResultExpr RewriteFstatatSIGSYS(int fs_denied_errno);
#if defined(__loongarch64)
SANDBOX_EXPORT bpf_dsl::ResultExpr RewriteStatxSIGSYS(int fs_denied_errno);
#endif

// Allocates a crash key so that Seccomp information can be recorded.
void AllocateCrashKeys();
