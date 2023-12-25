  # chrome build scheme. This variable permits controlling this for GN builds
  # in similar fashion by setting the `system_libdir` variable in the build's
  # args.gn file to 'lib' or 'lib64' as appropriate for the target architecture.
  system_libdir = "lib"
}

pkg_config_script = "//build/config/linux/pkg-config.py"

//----replace
  # chrome build scheme. This variable permits controlling this for GN builds
  # in similar fashion by setting the `system_libdir` variable in the build's
  # args.gn file to 'lib' or 'lib64' as appropriate for the target architecture.
  if (current_cpu == "loong64") {
    system_libdir = "lib64"
  } else {
    system_libdir = "lib"
  }
}

pkg_config_script = "//build/config/linux/pkg-config.py"
