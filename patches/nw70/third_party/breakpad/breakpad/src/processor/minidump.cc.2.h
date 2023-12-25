      if (system_info_cpu_type == MD_CPU_ARCHITECTURE_MIPS64)
        return_value = true;
      break;
  }

  BPLOG_IF(ERROR, !return_value) << "MinidumpContext CPU " <<

//----replace
      if (system_info_cpu_type == MD_CPU_ARCHITECTURE_MIPS64)
        return_value = true;
      break;
    
    case MD_CONTEXT_LOONGARCH64:
      if (system_info_cpu_type == MD_CPU_ARCHITECTURE_LOONGARCH64)
	return_value = true;
      break;
  }

  BPLOG_IF(ERROR, !return_value) << "MinidumpContext CPU " <<
