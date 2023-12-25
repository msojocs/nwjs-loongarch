  case MD_CONTEXT_MIPS64:
    *sp = GetContextMIPS()->iregs[MD_CONTEXT_MIPS_REG_SP];
    break;
  default:
    // This should never happen.
    BPLOG(ERROR) << "Unknown CPU architecture in GetStackPointer";

//----replace
  case MD_CONTEXT_MIPS64:
    *sp = GetContextMIPS()->iregs[MD_CONTEXT_MIPS_REG_SP];
    break;
  case MD_CONTEXT_LOONGARCH64:
    *sp = GetContextLOONGARCH64()->iregs[MD_CONTEXT_LOONGARCH64_REG_SP];
    break;
  default:
    // This should never happen.
    BPLOG(ERROR) << "Unknown CPU architecture in GetStackPointer";
