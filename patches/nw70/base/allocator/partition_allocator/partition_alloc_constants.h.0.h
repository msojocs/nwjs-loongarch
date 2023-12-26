// other constant values, we pack _all_ `PartitionRoot::Alloc` sizes perfectly
// up against the end of a system page.

#if defined(_MIPS_ARCH_LOONGSON)
PAGE_ALLOCATOR_CONSTANTS_DECLARE_CONSTEXPR PA_ALWAYS_INLINE size_t
PartitionPageShift() {
  return 16;  // 64 KiB

//----replace
// other constant values, we pack _all_ `PartitionRoot::Alloc` sizes perfectly
// up against the end of a system page.

#if defined(_MIPS_ARCH_LOONGSON) || defined(ARCH_CPU_LOONG64)// loongarch64
PAGE_ALLOCATOR_CONSTANTS_DECLARE_CONSTEXPR PA_ALWAYS_INLINE size_t
PartitionPageShift() {
  return 16;  // 64 KiB
