SIGSYSFstatatHandler(const struct arch_seccomp_data& args,
                     void* fs_denied_errno);

// Variants of the above functions for use with bpf_dsl.
SANDBOX_EXPORT bpf_dsl::ResultExpr CrashSIGSYS();
SANDBOX_EXPORT bpf_dsl::ResultExpr CrashSIGSYSClone();

//----replace
SIGSYSFstatatHandler(const struct arch_seccomp_data& args,
                     void* fs_denied_errno);

#if defined(__loongarch64)
SANDBOX_EXPORT intptr_t
SIGSYSStatxHandler(const struct arch_seccomp_data& args,
		   void* fs_denied_errno);
#endif

// Variants of the above functions for use with bpf_dsl.
SANDBOX_EXPORT bpf_dsl::ResultExpr CrashSIGSYS();
SANDBOX_EXPORT bpf_dsl::ResultExpr CrashSIGSYSClone();
