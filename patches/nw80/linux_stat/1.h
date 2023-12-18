#define __NR_fstatat_default __NR_newfstatat
#define __NR_fstat_default __NR_fstat

#else
#error "one of fstatat64 and newfstatat must be defined"
//----replace
#define __NR_fstatat_default __NR_newfstatat
#define __NR_fstat_default __NR_fstat

#elif defined(__loongarch64)

namespace sandbox {
using default_stat_struct = struct kernel_stat;
} // namespace sandbox

#define __NR_fstatat_default __NR_statx
#define __NR_fstat_default __NR_statx
// loong64
#else
#error "one of fstatat64 and newfstatat must be defined"