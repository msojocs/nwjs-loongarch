      reader, context_address, context_.mips64);
}

#endif  // ARCH_CPU_X86_FAMILY

bool ExceptionSnapshotLinux::Initialize(

//----replace
      reader, context_address, context_.mips64);
}

#elif defined(ARCH_CPU_LOONG64) // loongarch64
 // loongarch64
template <typename Traits> // loongarch64
static bool ReadContext(ProcessReaderLinux* reader, // loongarch64
                        LinuxVMAddress context_address, // loongarch64
                        typename Traits::CPUContext* dest_context) { // loongarch64
  const ProcessMemory* memory = reader->Memory(); // loongarch64
 // loongarch64
  LinuxVMAddress gregs_address = context_address + // loongarch64
                                 offsetof(UContext<Traits>, mcontext); // loongarch64
 // loongarch64
  ThreadContext::t64_t thread_context; // loongarch64
  typename Traits::MContext mcontext; // loongarch64
  if (!memory->Read(gregs_address, sizeof(mcontext), &mcontext)) { // loongarch64
    LOG(ERROR) << "Couldn't read gregs"; // loongarch64
    return false; // loongarch64
  } // loongarch64
  static_assert(sizeof(thread_context.regs) == sizeof(mcontext.gregs), // loongarch64
                "gpr context size mismtach"); // loongarch64
  memcpy(thread_context.regs, mcontext.gregs, sizeof(mcontext.gregs)); // loongarch64
  thread_context.csr_era = mcontext.pc; // loongarch64
  thread_context.orig_a0 = 0; // loongarch64
  thread_context.csr_badv = 0; // loongarch64
  InitializeCPUContextLOONGARCH64_NoFloatingPoint(thread_context, dest_context); // loongarch64
 // loongarch64
  LinuxVMAddress reserved_address = // loongarch64
        context_address + offsetof(UContext<Traits>, mcontext.extcontext); // loongarch64
 // loongarch64
  if ((reserved_address & 15) != 0) { // loongarch64
    LOG(ERROR) << "invalid alignment 0x" << std::hex << reserved_address; // loongarch64
    return false; // loongarch64
   } // loongarch64
 // loongarch64
  constexpr VMSize kMaxContextSpace = 4096; // loongarch64
 // loongarch64
  ProcessMemoryRange range; // loongarch64
  if (!range.Initialize(memory, true, reserved_address, kMaxContextSpace)) { // loongarch64
    return false; // loongarch64
  } // loongarch64
 // loongarch64
  do { // loongarch64
    struct sctx_info head; // loongarch64
    if (!range.Read(reserved_address, sizeof(head), &head)) { // loongarch64
      LOG(ERROR) << "missing context terminator"; // loongarch64
      return false; // loongarch64
    } // loongarch64
    reserved_address += sizeof(head); // loongarch64
    switch (head.magic) { // loongarch64
      case FPU_CTX_MAGIC: // loongarch64
        if (head.size != sizeof(struct fpu_context) + sizeof(head)) { // loongarch64
          LOG(ERROR) << "unexpected fpu context size " << head.size; // loongarch64
          return false; // loongarch64
        } // loongarch64
        FloatContext::f64_t fpucontext; // loongarch64
        if (!range.Read(reserved_address, sizeof(fpucontext), &fpucontext)) { // loongarch64
          LOG(ERROR) << "Couldn't read fpu " << head.size; // loongarch64
          return false; // loongarch64
        } // loongarch64
 // loongarch64
        InitializeCPUContextLOONGARCH64_OnlyFPU(fpucontext, dest_context); // loongarch64
        return true; // loongarch64
 // loongarch64
      //TODO: not support LSX_CTX_MAGIC and LASX_CTX_MAGIC // loongarch64
      //case LSX_CTX_MAGIC: // loongarch64
      //case LASX_CTX_MAGIC: // loongarch64
      //  reserved_address += head.size - sizeof(head); // loongarch64
      //  continue; // loongarch64
      case 0: // loongarch64
        return true; // loongarch64
 // loongarch64
      default: // loongarch64
        LOG(ERROR) << "invalid magic number 0x" << std::hex << head.magic; // loongarch64
        return false; // loongarch64
    } // loongarch64
  } while (true); // loongarch64
} // loongarch64
 // loongarch64
template <> // loongarch64
bool ExceptionSnapshotLinux::ReadContext<ContextTraits64>( // loongarch64
    ProcessReaderLinux* reader, // loongarch64
    LinuxVMAddress context_address) { // loongarch64
  context_.architecture = kCPUArchitectureLOONGARCH64; // loongarch64
  context_.loongarch64 = &context_union_.loongarch64; // loongarch64
 // loongarch64
  return internal::ReadContext<ContextTraits64>( // loongarch64
      reader, context_address, context_.loongarch64); // loongarch64
} // loongarch64
 // loongarch64
#endif  // ARCH_CPU_X86_FAMILY

bool ExceptionSnapshotLinux::Initialize(
