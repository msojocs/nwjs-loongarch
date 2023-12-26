#define AUDIT_ARCH_AARCH64 (EM_AARCH64 | __AUDIT_ARCH_64BIT | __AUDIT_ARCH_LE)
#endif

// For prctl.h
#ifndef PR_SET_SECCOMP
#define PR_SET_SECCOMP               22

//----replace
#define AUDIT_ARCH_AARCH64 (EM_AARCH64 | __AUDIT_ARCH_64BIT | __AUDIT_ARCH_LE)
#endif

#ifndef AUDIT_ARCH_LOONGARCH64 // loongarch64
#define AUDIT_ARCH_LOONGARCH64 (EM_LOONGARCH | __AUDIT_ARCH_64BIT | __AUDIT_ARCH_LE) // loongarch64
#endif // loongarch64
 // loongarch64
// For prctl.h
#ifndef PR_SET_SECCOMP
#define PR_SET_SECCOMP               22
