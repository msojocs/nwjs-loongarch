
class ScopedSigprocmaskRestore {
 public:
  explicit ScopedSigprocmaskRestore(const kernel_sigset_t& set_to_block)
      : orig_mask_(), mask_is_set_(false) {
    mask_is_set_ = sys_sigprocmask(SIG_BLOCK, &set_to_block, &orig_mask_) == 0;
    DPLOG_IF(ERROR, !mask_is_set_) << "sigprocmask";
  }


//----replace

class ScopedSigprocmaskRestore {
 public:
  explicit ScopedSigprocmaskRestore(const sigset_t& set_to_block)// loongarch64
      : orig_mask_(), mask_is_set_(false) {
    mask_is_set_ = sigprocmask(SIG_BLOCK, &set_to_block, &orig_mask_) == 0;// loongarch64
    DPLOG_IF(ERROR, !mask_is_set_) << "sigprocmask";
  }

