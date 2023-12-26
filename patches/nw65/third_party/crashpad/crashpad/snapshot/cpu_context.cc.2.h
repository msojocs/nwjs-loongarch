    case kCPUArchitectureX86_64:
    case kCPUArchitectureARM64:
    case kCPUArchitectureMIPS64EL:
      return true;
    case kCPUArchitectureX86:
    case kCPUArchitectureARM:

//----replace
    case kCPUArchitectureX86_64:
    case kCPUArchitectureARM64:
    case kCPUArchitectureMIPS64EL:
    case kCPUArchitectureLOONGARCH64: // loongarch64
      return true;
    case kCPUArchitectureX86:
    case kCPUArchitectureARM:
