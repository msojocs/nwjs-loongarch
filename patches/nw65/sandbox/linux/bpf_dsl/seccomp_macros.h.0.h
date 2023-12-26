#define SECCOMP_PT_PARM4(_regs) (_regs).regs[3]
#define SECCOMP_PT_PARM5(_regs) (_regs).regs[4]
#define SECCOMP_PT_PARM6(_regs) (_regs).regs[5]
#else
#error Unsupported target platform


//----replace
#define SECCOMP_PT_PARM4(_regs) (_regs).regs[3]
#define SECCOMP_PT_PARM5(_regs) (_regs).regs[4]
#define SECCOMP_PT_PARM6(_regs) (_regs).regs[5]
 // loongarch64
#elif defined(__loongarch64) // loongarch64
struct regs_struct { // loongarch64
  uint64_t regs[32]; // loongarch64
  uint64_t orig_a0; // loongarch64
  uint64_t csr_era; // loongarch64
  uint64_t csr_badv; // loongarch64
  uint64_t reserved[10]; // loongarch64
}; // loongarch64
 // loongarch64
typedef unsigned long int greg_t; // loongarch64
 // loongarch64
#define SECCOMP_ARCH AUDIT_ARCH_LOONGARCH64 // loongarch64
 // loongarch64
#define SECCOMP_REG(_ctx, _reg) ((_ctx)->uc_mcontext.__gregs[_reg]) // loongarch64
 // loongarch64
#define SECCOMP_RESULT(_ctx) SECCOMP_REG(_ctx, 4) // loongarch64
#define SECCOMP_SYSCALL(_ctx) SECCOMP_REG(_ctx, 11) // loongarch64
#define SECCOMP_IP(_ctx) (_ctx)->uc_mcontext.__pc // loongarch64
#define SECCOMP_PARM1(_ctx) SECCOMP_REG(_ctx, 4) // loongarch64
#define SECCOMP_PARM2(_ctx) SECCOMP_REG(_ctx, 5) // loongarch64
#define SECCOMP_PARM3(_ctx) SECCOMP_REG(_ctx, 6) // loongarch64
#define SECCOMP_PARM4(_ctx) SECCOMP_REG(_ctx, 7) // loongarch64
#define SECCOMP_PARM5(_ctx) SECCOMP_REG(_ctx, 8) // loongarch64
#define SECCOMP_PARM6(_ctx) SECCOMP_REG(_ctx, 9) // loongarch64
 // loongarch64
#define SECCOMP_NR_IDX (offsetof(struct arch_seccomp_data, nr)) // loongarch64
#define SECCOMP_ARCH_IDX (offsetof(struct arch_seccomp_data, arch)) // loongarch64
#define SECCOMP_IP_MSB_IDX \
	(offsetof(struct arch_seccomp_data, instruction_pointer) + 4) // loongarch64
#define SECCOMP_IP_LSB_IDX \
	(offsetof(struct arch_seccomp_data, instruction_pointer) + 0) // loongarch64
#define SECCOMP_ARG_MSB_IDX(nr) \
	(offsetof(struct arch_seccomp_data, args) + 8 * (nr) + 4) // loongarch64
#define SECCOMP_ARG_LSB_IDX(nr) \
	(offsetof(struct arch_seccomp_data, args) + 8 * (nr) + 0) // loongarch64
 // loongarch64
#define SECCOMP_PT_RESULT(_regs) (_regs).regs[4] // loongarch64
#define SECCOMP_PT_SYSCALL(_regs) (_regs).regs[11] // loongarch64
#define SECCOMP_PT_IP(_regs) (_regs).csr_era // loongarch64
#define SECCOMP_PT_PARM1(_regs) (_regs).regs[4] // loongarch64
#define SECCOMP_PT_PARM2(_regs) (_regs).regs[5] // loongarch64
#define SECCOMP_PT_PARM3(_regs) (_regs).regs[6] // loongarch64
#define SECCOMP_PT_PARM4(_regs) (_regs).regs[7] // loongarch64
#define SECCOMP_PT_PARM5(_regs) (_regs).regs[8] // loongarch64
#define SECCOMP_PT_PARM6(_regs) (_regs).regs[9] // loongarch64
 // loongarch64
#else
#error Unsupported target platform

