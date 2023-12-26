        # Outline atomics crash on Exynos 9810. http://crbug.com/1272795
        cflags += [ "-mno-outline-atomics" ]
      }
    } else if (current_cpu == "mipsel" && !is_nacl) {
      ldflags += [ "-Wl,--hash-style=sysv" ]
      if (custom_toolchain == "") {

//----replace
        # Outline atomics crash on Exynos 9810. http://crbug.com/1272795
        cflags += [ "-mno-outline-atomics" ]
      }
    } else if (current_cpu == "loong64") { # loongarch64
      cflags += [ "-mcmodel=large" ] # loongarch64
      if (is_clang && !is_android && !is_nacl && !is_fuchsia) { # loongarch64
        cflags += [ "--target=loongarch64-linux-gnu" ] # loongarch64
        ldflags += [ "--target=loongarch64-linux-gnu" ] # loongarch64
      } # loongarch64
    } else if (current_cpu == "mipsel" && !is_nacl) {
      ldflags += [ "-Wl,--hash-style=sysv" ]
      if (custom_toolchain == "") {
