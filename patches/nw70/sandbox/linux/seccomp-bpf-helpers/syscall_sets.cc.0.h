// Both EPERM and ENOENT are valid errno unless otherwise noted in comment.
bool SyscallSets::IsFileSystem(int sysno) {
  switch (sysno) {
#if !defined(__aarch64__)
    case __NR_access:  // EPERM not a valid errno.
    case __NR_chmod:
    case __NR_chown:

//----replace
// Both EPERM and ENOENT are valid errno unless otherwise noted in comment.
bool SyscallSets::IsFileSystem(int sysno) {
  switch (sysno) {
#if !defined(__aarch64__) && !defined(__loongarch64)// loongarch64
    case __NR_access:  // EPERM not a valid errno.
    case __NR_chmod:
    case __NR_chown:
