                        (is_mac && use_egl) || is_chromeos_ash || is_fuchsia) &&
                       (target_cpu == "x86" || target_cpu == "x64" ||
                        target_cpu == "arm" || target_cpu == "arm64" ||
                        target_cpu == "mipsel" || target_cpu == "mips64el")
}

//----replace
                        (is_mac && use_egl) || is_chromeos_ash || is_fuchsia) &&
                       (target_cpu == "x86" || target_cpu == "x64" ||
                        target_cpu == "arm" || target_cpu == "arm64" ||
                        target_cpu == "mipsel" || target_cpu == "mips64el" || # loongarch64
                        target_cpu == "loong64") # loongarch64
}
