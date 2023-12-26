      (is_chromeos || is_linux || is_win) &&
      (target_cpu == "x86" || target_cpu == "x64" ||
      target_cpu == "arm" || target_cpu == "arm64" ||
      target_cpu == "ppc64")
}

//----replace
      (is_chromeos || is_linux || is_win) &&
      (target_cpu == "x86" || target_cpu == "x64" ||
      target_cpu == "arm" || target_cpu == "arm64" ||
      target_cpu == "ppc64" || target_cpu == "loong64")// loongarch64
}
