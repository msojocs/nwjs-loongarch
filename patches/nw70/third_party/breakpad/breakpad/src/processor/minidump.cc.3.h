      cpu = "arm64";
      break;

    default:
      BPLOG(ERROR) << "MinidumpSystemInfo unknown CPU for architecture " <<
                      HexString(system_info_.processor_architecture);

//----replace
      cpu = "arm64";
      break;

    case MD_CPU_ARCHITECTURE_LOONGARCH64:
      cpu = "loongarch64";
    default:
      BPLOG(ERROR) << "MinidumpSystemInfo unknown CPU for architecture " <<
                      HexString(system_info_.processor_architecture);
