// TODO: define this in an arch-independant way instead of inlining the clone
//       syscall body.

# if defined(__aarch64__)
  LSS_INLINE pid_t LSS_NAME(fork)(void) {
    // No fork syscall on aarch64 - implement by means of the clone syscall.
    // Note that this does not reset glibc's cached view of the PID/TID, so

//----replace
// TODO: define this in an arch-independant way instead of inlining the clone
//       syscall body.

# if defined(__aarch64__) || defined(__loongarch64) // loongarch64
  LSS_INLINE pid_t LSS_NAME(fork)(void) {
    // No fork syscall on aarch64 - implement by means of the clone syscall.
    // Note that this does not reset glibc's cached view of the PID/TID, so
