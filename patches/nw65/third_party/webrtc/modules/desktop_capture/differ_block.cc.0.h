  static bool (*diff_proc)(const uint8_t*, const uint8_t*) = nullptr;

  if (!diff_proc) {
#if defined(WEBRTC_ARCH_ARM_FAMILY) || defined(WEBRTC_ARCH_MIPS_FAMILY)
    // For ARM and MIPS processors, always use C version.
    // TODO(hclam): Implement a NEON version.
    diff_proc = &VectorDifference_C;

//----replace
  static bool (*diff_proc)(const uint8_t*, const uint8_t*) = nullptr;

  if (!diff_proc) {
#if defined(WEBRTC_ARCH_ARM_FAMILY) || defined(WEBRTC_ARCH_MIPS_FAMILY) || defined(WEBRTC_ARCH_LOONG_FAMILY) // loongarch64
    // For ARM and MIPS processors, always use C version.
    // TODO(hclam): Implement a NEON version.
    diff_proc = &VectorDifference_C;
