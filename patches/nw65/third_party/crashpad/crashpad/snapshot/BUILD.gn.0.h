  }

  if ((crashpad_is_linux || crashpad_is_android || crashpad_is_fuchsia) &&
      target_cpu != "mipsel" && target_cpu != "mips64el") {
    data_deps += [ ":crashpad_snapshot_test_both_dt_hash_styles" ]
  }


//----replace
  }

  if ((crashpad_is_linux || crashpad_is_android || crashpad_is_fuchsia) &&
      target_cpu != "mipsel" && target_cpu != "mips64el" && # loongarch64
      target_cpu != "loongarch64") { # loongarch64
    data_deps += [ ":crashpad_snapshot_test_both_dt_hash_styles" ]
  }

