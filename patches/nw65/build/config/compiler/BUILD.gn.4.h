      # Use constructor homing for debug info. This option reduces debug info
      # by emitting class type info only when constructors are emitted.
      cflags += [
        "-Xclang",
        "-fuse-ctor-homing",
      ]
    }
  }

//----replace
      # Use constructor homing for debug info. This option reduces debug info
      # by emitting class type info only when constructors are emitted.
      cflags += [
        #"-Xclang", # loongarch64
        #"-fuse-ctor-homing", # loongarch64
      ]
    }
  }
