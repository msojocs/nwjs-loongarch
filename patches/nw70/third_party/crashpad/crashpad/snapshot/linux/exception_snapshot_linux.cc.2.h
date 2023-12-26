        !ReadSiginfo<Traits64>(process_reader, siginfo_address)) {
      return false;
    }
  } else {
    if (!ReadContext<ContextTraits32>(process_reader, context_address) ||
        !ReadSiginfo<Traits32>(process_reader, siginfo_address)) {
      return false;
    }
  }

  CaptureMemoryDelegateLinux capture_memory_delegate(

//----replace
        !ReadSiginfo<Traits64>(process_reader, siginfo_address)) {
      return false;
    }
#if !defined(ARCH_CPU_LOONG64)// loongarch64
  } else {
    if (!ReadContext<ContextTraits32>(process_reader, context_address) ||
        !ReadSiginfo<Traits32>(process_reader, siginfo_address)) {
      return false;
    }
#endif// loongarch64
  }

  CaptureMemoryDelegateLinux capture_memory_delegate(
