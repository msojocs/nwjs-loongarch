  timespec timeout;
  timeout.tv_sec = 5;
  timeout.tv_nsec = 0;
  if (HANDLE_EINTR(sys_sigtimedwait(&dump_done_sigset, &siginfo, &timeout)) <
      0) {
    return errno;
  }

//----replace
  timespec timeout;
  timeout.tv_sec = 5;
  timeout.tv_nsec = 0;
  if (HANDLE_EINTR(sigtimedwait(&dump_done_sigset, &siginfo, &timeout)) <
      0) {
    return errno;
  }
