    } else {
      # -ffile-compilation-dir is an alias for both -fdebug-compilation-dir=
      # and -fcoverage-compilation-dir=.
      cflags += [ "-ffile-compilation-dir=." ]
    }
    if (!is_win) {
      # We don't use clang -cc1as on Windows (yet? https://crbug.com/762167)

//----replace
    } else {
      # -ffile-compilation-dir is an alias for both -fdebug-compilation-dir=
      # and -fcoverage-compilation-dir=.
      #cflags += [ "-ffile-compilation-dir=." ] # loongarch64
    }
    if (!is_win) {
      # We don't use clang -cc1as on Windows (yet? https://crbug.com/762167)
