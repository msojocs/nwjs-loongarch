    dirent->location.rva = 0;
  }

#if defined(__i386__) || defined(__x86_64__) || defined(__mips__)
  bool WriteCPUInformation(MDRawSystemInfo* sys_info) {
    char vendor_id[sizeof(sys_info->cpu.x86_cpu_info.vendor_id) + 1] = {0};
    static const char vendor_id_name[] = "vendor_id";

//----replace
    dirent->location.rva = 0;
  }

#if defined(__i386__) || defined(__x86_64__) || defined(__mips__) || defined(__loongarch64)// loongarch64
  bool WriteCPUInformation(MDRawSystemInfo* sys_info) {
    char vendor_id[sizeof(sys_info->cpu.x86_cpu_info.vendor_id) + 1] = {0};
    static const char vendor_id_name[] = "vendor_id";
