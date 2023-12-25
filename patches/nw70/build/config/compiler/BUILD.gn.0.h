    } else if (current_cpu == "s390x") {
      cflags += [ "-m64" ]
      ldflags += [ "-m64" ]
    }
  }


//----replace
    } else if (current_cpu == "s390x") {
      cflags += [ "-m64" ]
      ldflags += [ "-m64" ]
    } else if (current_cpu == "loong64") {
      cflags += [ "-mcmodel=medium" ]
      if (is_clang) {
        cflags += [ "--target=loongarch64-linux-gnu" ]
        ldflags += [ "--target=loongarch64-linux-gnu" ]
      }
    }
  }

