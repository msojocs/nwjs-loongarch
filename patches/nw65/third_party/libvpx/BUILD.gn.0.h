      sources = libvpx_srcs_arm64
      public_deps = [ ":libvpx_arm64_headers" ]
    }
  }

  configs -= [ "//build/config/compiler:chromium_code" ]

//----replace
      sources = libvpx_srcs_arm64
      public_deps = [ ":libvpx_arm64_headers" ]
    }
  } else if (current_cpu == "loong64") { # loongarch64
    sources = libvpx_srcs_generic # loongarch64
  }

  configs -= [ "//build/config/compiler:chromium_code" ]
