  return true;
}

#else
#error Port.
#endif  // ARCH_CPU_X86_FAMILY

//----replace
  return true;
}

#elif defined(ARCH_CPU_LOONG64) // loongarch64
 // loongarch64
#include <asm/ptrace.h> // loongarch64
 // loongarch64
bool GetFloatingPointRegisters32(pid_t tid, // loongarch64
                                 FloatContext* context, // loongarch64
                                 bool can_log) { // loongarch64
  return false; // loongarch64
} // loongarch64
 // loongarch64
bool GetFloatingPointRegisters64(pid_t tid, // loongarch64
                                 FloatContext* context, // loongarch64
                                 bool can_log) { // loongarch64
  iovec iov; // loongarch64
  iov.iov_base = context; // loongarch64
  iov.iov_len = sizeof(*context); // loongarch64
  if (ptrace(PTRACE_GETREGSET, tid, reinterpret_cast<void*>(NT_PRFPREG), &iov) != 0) { // loongarch64
    PLOG_IF(ERROR, can_log) << "ptrace"; // loongarch64
    return false; // loongarch64
  } // loongarch64
  if (iov.iov_len != sizeof(context->f64)) { // loongarch64
    LOG_IF(ERROR, can_log) << "Unexpected registers size " << iov.iov_len // loongarch64
                           << " != " << sizeof(context->f64); // loongarch64
    return false; // loongarch64
  } // loongarch64
 // loongarch64
  return true; // loongarch64
} // loongarch64
 // loongarch64
bool GetThreadArea32(pid_t tid, // loongarch64
                     const ThreadContext& context, // loongarch64
                     LinuxVMAddress* address, // loongarch64
                     bool can_log) { // loongarch64
  return false; // loongarch64
} // loongarch64
 // loongarch64
bool GetThreadArea64(pid_t tid, // loongarch64
                     const ThreadContext& context, // loongarch64
                     LinuxVMAddress* address, // loongarch64
                     bool can_log) { // loongarch64
  struct user_pt_regs loongarch_regs; // loongarch64
  struct iovec iov = { // loongarch64
     .iov_base = &loongarch_regs, // loongarch64
     .iov_len = sizeof(loongarch_regs) // loongarch64
  }; // loongarch64
 // loongarch64
  if (ptrace(PTRACE_GETREGSET, tid, NT_PRSTATUS, &iov) != 0) { // loongarch64
    PLOG_IF(ERROR, can_log) << "ptrace"; // loongarch64
    return false; // loongarch64
  } // loongarch64
  *address = loongarch_regs.regs[2]; // loongarch64
  return true; // loongarch64
} // loongarch64
 // loongarch64
#else
#error Port.
#endif  // ARCH_CPU_X86_FAMILY
