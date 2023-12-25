      break;
    }

    default: {
      LOG(ERROR) << "unknown context architecture "
                 << context_snapshot->architecture;

//----replace
      break;
    }

    case kCPUArchitectureLOONGARCH64: {
      context = std::make_unique<MinidumpContextLOONGARCH64Writer>();
      reinterpret_cast<MinidumpContextLOONGARCH64Writer*>(context.get())
          ->InitializeFromSnapshot(context_snapshot->loongarch64);
      break;
    }

    default: {
      LOG(ERROR) << "unknown context architecture "
                 << context_snapshot->architecture;
