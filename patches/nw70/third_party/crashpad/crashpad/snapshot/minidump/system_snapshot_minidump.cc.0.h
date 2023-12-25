    case kMinidumpCPUArchitectureMIPS:
      return kCPUArchitectureMIPSEL;
    // No word on how MIPS64 is signalled

    default:
      return CPUArchitecture::kCPUArchitectureUnknown;
  }

//----replace
    case kMinidumpCPUArchitectureMIPS:
      return kCPUArchitectureMIPSEL;
    // No word on how MIPS64 is signalled
    case kMinidumpCPUArchitectureLOONGARCH64:
      return kCPUArchitectureLOONGARCH64;
    default:
      return CPUArchitecture::kCPUArchitectureUnknown;
  }
