use_seccomp_bpf = (is_linux || is_chromeos || is_android) &&
                  (current_cpu == "x86" || current_cpu == "x64" ||
                   current_cpu == "arm" || current_cpu == "arm64" ||
                   current_cpu == "mipsel" || current_cpu == "mips64el")

# SSBD (Speculative Store Bypass Disable) is a mitigation of Spectre Variant 4.
# As Spectre Variant 4 can be mitigated by site isolation, opt-out SSBD on site

//----replace
use_seccomp_bpf = (is_linux || is_chromeos || is_android) &&
                  (current_cpu == "x86" || current_cpu == "x64" ||
                   current_cpu == "arm" || current_cpu == "arm64" ||
                   current_cpu == "mipsel" || current_cpu == "mips64el" ||// loongarch64
                   current_cpu == "loong64")// loongarch64

# SSBD (Speculative Store Bypass Disable) is a mitigation of Spectre Variant 4.
# As Spectre Variant 4 can be mitigated by site isolation, opt-out SSBD on site
