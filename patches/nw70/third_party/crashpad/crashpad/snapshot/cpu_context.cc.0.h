      return arm->pc;
    case kCPUArchitectureARM64:
      return arm64->pc;
    default:
      NOTREACHED();
      return ~0ull;

//----replace
      return arm->pc;
    case kCPUArchitectureARM64:
      return arm64->pc;
    case kCPUArchitectureLOONGARCH64:
      return loongarch64->csr_era;
    default:
      NOTREACHED();
      return ~0ull;
