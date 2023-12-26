      break;
    }

    default: {
      LOG(ERROR) << "unknown context architecture "
                 << context_snapshot->architecture;

//----replace
      break;
    }

    case kCPUArchitectureLOONGARCH64: { // loongarch64
      context = std::make_unique<MinidumpContextLOONGARCH64Writer>(); // loongarch64
      reinterpret_cast<MinidumpContextLOONGARCH64Writer*>(context.get()) // loongarch64
          ->InitializeFromSnapshot(context_snapshot->loongarch64); // loongarch64
      break; // loongarch64
    } // loongarch64
 // loongarch64
    default: {
      LOG(ERROR) << "unknown context architecture "
                 << context_snapshot->architecture;
