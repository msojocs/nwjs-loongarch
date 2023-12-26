  case MD_CONTEXT_MIPS64:
    *ip = GetContextMIPS()->epc;
    break;
  default:
    // This should never happen.
    BPLOG(ERROR) << "Unknown CPU architecture in GetInstructionPointer";

//----replace
  case MD_CONTEXT_MIPS64:
    *ip = GetContextMIPS()->epc;
    break;
  case MD_CONTEXT_LOONGARCH64: // loongarch64
    *ip = GetContextLOONGARCH64()->csr_era; // loongarch64
    break; // loongarch64
  default:
    // This should never happen.
    BPLOG(ERROR) << "Unknown CPU architecture in GetInstructionPointer";
