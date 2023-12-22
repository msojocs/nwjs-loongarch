  } else if (current_cpu == "s390x") {
    sources = skia_opts.none_sources
  } else {
    assert(false, "Need to port cpu specific stuff from skia_library_opts.gyp")
  }
//----replace
  } else if (current_cpu == "s390x") {
    sources = skia_opts.none_sources
  } else if (current_cpu == "loong64") {
    sources = skia_opts.none_sources
  } else {
    assert(false, "Need to port cpu specific stuff from skia_library_opts.gyp")
  }