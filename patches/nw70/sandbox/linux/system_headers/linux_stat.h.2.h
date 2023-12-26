#define __NR_fstatat_default __NR_newfstatat
#define __NR_fstat_default __NR_fstat

#else
#error "one of fstatat64 and newfstatat must be defined"
#endif

//----replace
#define __NR_fstatat_default __NR_newfstatat
#define __NR_fstat_default __NR_fstat

#elif defined(__loongarch64)// loongarch64
// loongarch64
namespace sandbox {// loongarch64
using default_stat_struct = struct kernel_stat;// loongarch64
} // namespace sandbox// loongarch64
// loongarch64
#define __NR_fstatat_default __NR_statx// loongarch64
#define __NR_fstat_default __NR_statx// loongarch64
// loongarch64
#else
#error "one of fstatat64 and newfstatat must be defined"
#endif
