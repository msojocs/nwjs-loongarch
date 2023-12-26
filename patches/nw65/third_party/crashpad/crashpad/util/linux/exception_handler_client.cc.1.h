
  ~ScopedSigprocmaskRestore() {
    if (mask_is_set_ &&
        sys_sigprocmask(SIG_SETMASK, &orig_mask_, nullptr) != 0) {
      DPLOG(ERROR) << "sigprocmask";
    }
  }

 private:
  kernel_sigset_t orig_mask_;
  bool mask_is_set_;
};


//----replace

  ~ScopedSigprocmaskRestore() {
    if (mask_is_set_ &&
        sigprocmask(SIG_SETMASK, &orig_mask_, nullptr) != 0) { // loongarch64
      DPLOG(ERROR) << "sigprocmask";
    }
  }

 private:
  sigset_t orig_mask_; // loongarch64
  bool mask_is_set_;
};

