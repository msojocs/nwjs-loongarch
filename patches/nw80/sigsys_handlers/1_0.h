SANDBOX_EXPORT intptr_t
SIGSYSFstatatHandler(const struct arch_seccomp_data& args,
                     void* fs_denied_errno);

// Variants of the above functions for use with bpf_dsl.
SANDBOX_EXPORT bpf_dsl::ResultExpr CrashSIGSYS();
