    case MD_CONTEXT_MIPS64:
      delete context_.ctx_mips;
      break;

    default:
      // There is no context record (valid_ is false) or there's a

//----replace
    case MD_CONTEXT_MIPS64:
      delete context_.ctx_mips;
      break;
    case MD_CONTEXT_LOONGARCH64:
      delete context_.loongarch64;
      break;

    default:
      // There is no context record (valid_ is false) or there's a
