SIGSYSFstatatHandler(const struct arch_seccomp_data& args,
                     void* fs_denied_errno);

// Variants of the above functions for use with bpf_dsl.
SANDBOX_EXPORT bpf_dsl::ResultExpr CrashSIGSYS();
SANDBOX_EXPORT bpf_dsl::ResultExpr CrashSIGSYSClone();

//----replace
SIGSYSFstatatHandler(const struct arch_seccomp_data& args,
                     void* fs_denied_errno);

#if defined(__loongarch64)// loongarch64
SANDBOX_EXPORT intptr_t// loongarch64
SIGSYSStatxHandler(const struct arch_seccomp_data& args,// loongarch64
		   void* fs_denied_errno);// loongarch64
#endif// loongarch64
// loongarch64
// Variants of the above functions for use with bpf_dsl.
SANDBOX_EXPORT bpf_dsl::ResultExpr CrashSIGSYS();
SANDBOX_EXPORT bpf_dsl::ResultExpr CrashSIGSYSClone();
