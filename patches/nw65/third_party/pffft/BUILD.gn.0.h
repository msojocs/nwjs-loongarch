  # PFFFT doesn't support SIMD on some cpus, so build a scalar version.
  if ((current_cpu == "arm" && !arm_use_neon) || current_cpu == "mipsel" ||
      current_cpu == "mips64el" || current_cpu == "ppc64" ||
      current_cpu == "s390x") {
    defines = [ "PFFFT_SIMD_DISABLE" ]
  }
}

//----replace
  # PFFFT doesn't support SIMD on some cpus, so build a scalar version.
  if ((current_cpu == "arm" && !arm_use_neon) || current_cpu == "mipsel" ||
      current_cpu == "mips64el" || current_cpu == "ppc64" ||
      current_cpu == "s390x" || current_cpu == "loong64") { # loongarch64
    defines = [ "PFFFT_SIMD_DISABLE" ]
  }
}
