    } else if (current_cpu == "s390x") {
      cflags += [ "-m64" ]
      ldflags += [ "-m64" ]
    }
  }


//----replace
    } else if (current_cpu == "s390x") {
      cflags += [ "-m64" ]
      ldflags += [ "-m64" ]
    } else if (current_cpu == "loong64") {# loongarch64
      cflags += [ "-mcmodel=medium" ]# loongarch64
      if (is_clang) {# loongarch64
        cflags += [ "--target=loongarch64-linux-gnu" ]# loongarch64
        ldflags += [ "--target=loongarch64-linux-gnu" ]# loongarch64
      }# loongarch64
    }
  }

