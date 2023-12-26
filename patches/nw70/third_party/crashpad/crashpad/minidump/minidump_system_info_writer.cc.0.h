    case kCPUArchitectureARM64:
      cpu_architecture = kMinidumpCPUArchitectureARM64;
      break;
    default:
      NOTREACHED();
      cpu_architecture = kMinidumpCPUArchitectureUnknown;

//----replace
    case kCPUArchitectureARM64:
      cpu_architecture = kMinidumpCPUArchitectureARM64;
      break;
    case kCPUArchitectureLOONGARCH64:// loongarch64
      cpu_architecture = kMinidumpCPUArchitectureLOONGARCH64;// loongarch64
      break;// loongarch64
    default:
      NOTREACHED();
      cpu_architecture = kMinidumpCPUArchitectureUnknown;
