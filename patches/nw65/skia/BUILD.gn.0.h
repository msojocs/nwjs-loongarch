    sources = skia_opts.none_sources
  } else if (current_cpu == "s390x") {
    sources = skia_opts.none_sources
  } else {
    assert(false, "Need to port cpu specific stuff from skia_library_opts.gyp")
  }

//----replace
    sources = skia_opts.none_sources
  } else if (current_cpu == "s390x") {
    sources = skia_opts.none_sources
  } else if (current_cpu == "loong64") { # loongarch64
    sources = skia_opts.none_sources # loongarch64
  } else {
    assert(false, "Need to port cpu specific stuff from skia_library_opts.gyp")
  }
