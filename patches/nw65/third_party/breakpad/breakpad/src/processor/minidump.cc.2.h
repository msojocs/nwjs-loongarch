      if (system_info_cpu_type == MD_CPU_ARCHITECTURE_MIPS64)
        return_value = true;
      break;
  }

  BPLOG_IF(ERROR, !return_value) << "MinidumpContext CPU " <<

//----replace
      if (system_info_cpu_type == MD_CPU_ARCHITECTURE_MIPS64)
        return_value = true;
      break;
     // loongarch64
    case MD_CONTEXT_LOONGARCH64: // loongarch64
      if (system_info_cpu_type == MD_CPU_ARCHITECTURE_LOONGARCH64) // loongarch64
	return_value = true; // loongarch64
      break; // loongarch64
  }

  BPLOG_IF(ERROR, !return_value) << "MinidumpContext CPU " <<
