    info->arch = extensions::api::runtime::PLATFORM_ARCH_MIPS;
  } else if (strcmp(arch, "mips64el") == 0) {
    info->arch = extensions::api::runtime::PLATFORM_ARCH_MIPS64;
  } else {
    NOTREACHED();
    return false;

//----replace
    info->arch = extensions::api::runtime::PLATFORM_ARCH_MIPS;
  } else if (strcmp(arch, "mips64el") == 0) {
    info->arch = extensions::api::runtime::PLATFORM_ARCH_MIPS64;
  } else if (strcmp(arch, "loong64") == 0) {// loongarch64
    info->arch = extensions::api::runtime::PLATFORM_ARCH_LOONG64;// loongarch64
  } else {
    NOTREACHED();
    return false;
