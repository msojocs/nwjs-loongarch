int ExceptionHandlerClient::SignalCrashDump(
    const ExceptionHandlerProtocol::ClientInformation& info,
    VMAddress stack_pointer) {
  kernel_sigset_t dump_done_sigset;
  sys_sigemptyset(&dump_done_sigset);
  sys_sigaddset(&dump_done_sigset, ExceptionHandlerProtocol::kDumpDoneSignal);
  ScopedSigprocmaskRestore scoped_block(dump_done_sigset);

  int status = SendCrashDumpRequest(info, stack_pointer);

//----replace
int ExceptionHandlerClient::SignalCrashDump(
    const ExceptionHandlerProtocol::ClientInformation& info,
    VMAddress stack_pointer) {
  sigset_t dump_done_sigset; // loongarch64
  sigemptyset(&dump_done_sigset); // loongarch64
  sigaddset(&dump_done_sigset, ExceptionHandlerProtocol::kDumpDoneSignal); // loongarch64
  ScopedSigprocmaskRestore scoped_block(dump_done_sigset);

  int status = SendCrashDumpRequest(info, stack_pointer);
