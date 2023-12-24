
    public_configs = [ ":commit_id_config" ]
}

if (is_linux) {
  copy("copy_icd") {
    sources = [
      "$root_out_dir/vk_swiftshader_icd.json",
    ]
    outputs = [ "$root_out_dir/lib/{{source_file_part}}" ]
    deps = [
      "//third_party/swiftshader/src/Vulkan:icd_file",
    ]
  }
}

if (is_mac) {
  copy("copy_ffmpeg") {
//----replace

    public_configs = [ ":commit_id_config" ]
}

if (is_mac) {
  copy("copy_ffmpeg") {