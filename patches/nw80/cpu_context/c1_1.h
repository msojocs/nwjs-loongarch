case kCPUArchitectureRISCV64:
      return riscv64->pc;
    case kCPUArchitectureLOONGARCH64:
      return loongarch64->csr_era;
    default:
      NOTREACHED();