  return true;
}

#else
#error Port.
#endif  // ARCH_CPU_X86_FAMILY

//----replace
  return true;
}

#elif defined(ARCH_CPU_LOONG64)

#include <asm/ptrace.h>

bool GetFloatingPointRegisters32(pid_t tid,
                                 FloatContext* context,
                                 bool can_log) {
  return false;
}

bool GetFloatingPointRegisters64(pid_t tid,
                                 FloatContext* context,
                                 bool can_log) {
  iovec iov;
  iov.iov_base = context;
  iov.iov_len = sizeof(*context);
  if (ptrace(PTRACE_GETREGSET, tid, reinterpret_cast<void*>(NT_PRFPREG), &iov) != 0) {
    PLOG_IF(ERROR, can_log) << "ptrace";
    return false;
  }
  if (iov.iov_len != sizeof(context->f64)) {
    LOG_IF(ERROR, can_log) << "Unexpected registers size " << iov.iov_len
                           << " != " << sizeof(context->f64);
    return false;
  }

  return true;
}

bool GetThreadArea32(pid_t tid,
                     const ThreadContext& context,
                     LinuxVMAddress* address,
                     bool can_log) {
  return false;
}

bool GetThreadArea64(pid_t tid,
                     const ThreadContext& context,
                     LinuxVMAddress* address,
                     bool can_log) {
  struct user_pt_regs loongarch_regs;
  struct iovec iov = {
     .iov_base = &loongarch_regs,
     .iov_len = sizeof(loongarch_regs)
  };

  if (ptrace(PTRACE_GETREGSET, tid, NT_PRSTATUS, &iov) != 0) {
    PLOG_IF(ERROR, can_log) << "ptrace";
    return false;
  }
  *address = loongarch_regs.regs[2];
  return true;
}

#else
#error Port.
#endif  // ARCH_CPU_X86_FAMILY
