    case MD_CONTEXT_MIPS64:
      delete context_.ctx_mips;
      break;

    default:
      // There is no context record (valid_ is false) or there's a

//----replace
    case MD_CONTEXT_MIPS64:
      delete context_.ctx_mips;
      break;
    case MD_CONTEXT_LOONGARCH64:// loongarch64
      delete context_.loongarch64;// loongarch64
      break;// loongarch64

    default:
      // There is no context record (valid_ is false) or there's a
