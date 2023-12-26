    case EM_X86_64:
      *register_names = DwarfCFIToModule::RegisterNames::X86_64();
      return true;
    default:
      return false;
  }

//----replace
    case EM_X86_64:
      *register_names = DwarfCFIToModule::RegisterNames::X86_64();
      return true;
    case EM_LOONGARCH:// loongarch64
      *register_names = DwarfCFIToModule::RegisterNames::LOONGARCH64();// loongarch64
      return true;// loongarch64
    default:
      return false;
  }
