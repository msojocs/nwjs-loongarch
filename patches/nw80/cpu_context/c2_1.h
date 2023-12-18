case kCPUArchitectureRISCV64:
      return riscv64->regs[1];
    case kCPUArchitectureLOONGARCH64:
      return loongarch64->regs[3];
    default:
      NOTREACHED();