  } else if (current_cpu == "riscv64") {
    sources = libvpx_srcs_generic
    public_deps = [ ":libvpx_generic_headers" ]
  }

  configs -= [ "//build/config/compiler:chromium_code" ]

//----replace
  } else if (current_cpu == "riscv64") {
    sources = libvpx_srcs_generic
    public_deps = [ ":libvpx_generic_headers" ]
  } else if (current_cpu == "loong64") {# loongarch64
    sources = libvpx_srcs_generic# loongarch64
    public_deps = [ ":libvpx_generic_headers" ]# loongarch64
  }

  configs -= [ "//build/config/compiler:chromium_code" ]
