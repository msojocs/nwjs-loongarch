}

if (sysroot == "") {
  if (current_os == target_os && current_cpu == target_cpu &&
      target_sysroot != "") {
    sysroot = target_sysroot

//----replace
}

if (sysroot == "") {
  if (target_sysroot == "" && current_cpu == "loong64") { # loongarch64
    target_sysroot = "$target_sysroot_dir/debian_bullseye_loong64-sysroot" # loongarch64
  } # loongarch64
  if (current_os == target_os && current_cpu == target_cpu &&
      target_sysroot != "") {
    sysroot = target_sysroot
