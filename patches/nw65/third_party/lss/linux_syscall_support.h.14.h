      LSS_SC_BODY(4, int, 8, d, type, protocol, sv);
    }
  #endif
  #if defined(__ARM_EABI__) || defined (__aarch64__)
    LSS_INLINE _syscall3(ssize_t, recvmsg, int, s, struct kernel_msghdr*, msg,
                         int, flags)
    LSS_INLINE _syscall3(ssize_t, sendmsg, int, s, const struct kernel_msghdr*,

//----replace
      LSS_SC_BODY(4, int, 8, d, type, protocol, sv);
    }
  #endif
  #if defined(__ARM_EABI__) || defined (__aarch64__) || defined(__loongarch64) // loongarch64
    LSS_INLINE _syscall3(ssize_t, recvmsg, int, s, struct kernel_msghdr*, msg,
                         int, flags)
    LSS_INLINE _syscall3(ssize_t, sendmsg, int, s, const struct kernel_msghdr*,
