      case MD_CPU_ARCHITECTURE_SPARC:
        *context_cpu_flags = MD_CONTEXT_SPARC;
        break;
      case MD_CPU_ARCHITECTURE_UNKNOWN:
        *context_cpu_flags = 0;
        break;

//----replace
      case MD_CPU_ARCHITECTURE_SPARC:
        *context_cpu_flags = MD_CONTEXT_SPARC;
        break;
      case MD_CPU_ARCHITECTURE_LOONGARCH64:
	*context_cpu_flags = MD_CONTEXT_LOONGARCH64;
	break;
      case MD_CPU_ARCHITECTURE_UNKNOWN:
        *context_cpu_flags = 0;
        break;
