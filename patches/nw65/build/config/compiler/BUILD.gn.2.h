        # Ignore warnings about MSVC optimization pragmas.
        # TODO(thakis): Only for no_chromium_code? http://crbug.com/912662
        "-Wno-ignored-pragma-optimize",
      ]

      if (!is_nacl) {
        # TODO(https://crbug.com/1300731) Clean up and enable.
        cflags += [ "-Wno-unqualified-std-cast-call" ]

        # TODO(https://crbug.com/1314867): Clean up and enable.
        cflags += [ "-Wno-deprecated-non-prototype" ]
      }

      if (!is_nacl && !(is_chromeos ||
                        default_toolchain == "//build/toolchain/cros:target")) {
        # TODO(https://crbug.com/1316298): Re-enable once test failure is figured out
        cflags += [
          "-Xclang",
          "-no-opaque-pointers",
        ]
      }


//----replace
        # Ignore warnings about MSVC optimization pragmas.
        # TODO(thakis): Only for no_chromium_code? http://crbug.com/912662
        "-Wno-ignored-pragma-optimize",
        # clang 11 compiler on loongarch64  # loongarch64
        "-Wno-invalid-constexpr", # loongarch64
      ]

      if (!is_nacl) {
        # TODO(https://crbug.com/1300731) Clean up and enable.
        #cflags += [ "-Wno-unqualified-std-cast-call" ] # loongarch64

        # TODO(https://crbug.com/1314867): Clean up and enable.
        #cflags += [ "-Wno-deprecated-non-prototype" ] # loongarch64
      }

      if (!is_nacl && !(is_chromeos ||
                        default_toolchain == "//build/toolchain/cros:target")) {
        # TODO(https://crbug.com/1316298): Re-enable once test failure is figured out
        cflags += [
          #"-Xclang", # loongarch64
          #"-no-opaque-pointers", # loongarch64
        ]
      }

