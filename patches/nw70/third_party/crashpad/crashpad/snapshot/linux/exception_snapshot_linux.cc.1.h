      reader, context_address, context_.mips64);
}

#endif  // ARCH_CPU_X86_FAMILY

bool ExceptionSnapshotLinux::Initialize(

//----replace
      reader, context_address, context_.mips64);
}

#elif defined(ARCH_CPU_LOONG64)

template <typename Traits>
static bool ReadContext(ProcessReaderLinux* reader,
                        LinuxVMAddress context_address,
                        typename Traits::CPUContext* dest_context) {
  const ProcessMemory* memory = reader->Memory();

  LinuxVMAddress gregs_address = context_address +
                                 offsetof(UContext<Traits>, mcontext);

  ThreadContext::t64_t thread_context;
  typename Traits::MContext mcontext;
  if (!memory->Read(gregs_address, sizeof(mcontext), &mcontext)) {
    LOG(ERROR) << "Couldn't read gregs";
    return false;
  }
  static_assert(sizeof(thread_context.regs) == sizeof(mcontext.gregs),
                "gpr context size mismtach");
  memcpy(thread_context.regs, mcontext.gregs, sizeof(mcontext.gregs));
  thread_context.csr_era = mcontext.pc;
  thread_context.orig_a0 = 0;
  thread_context.csr_badv = 0;
  InitializeCPUContextLOONGARCH64_NoFloatingPoint(thread_context, dest_context);

  LinuxVMAddress reserved_address =
        context_address + offsetof(UContext<Traits>, mcontext.extcontext);

  if ((reserved_address & 15) != 0) {
    LOG(ERROR) << "invalid alignment 0x" << std::hex << reserved_address;
    return false;
   }

  constexpr VMSize kMaxContextSpace = 4096;

  ProcessMemoryRange range;
  if (!range.Initialize(memory, true, reserved_address, kMaxContextSpace)) {
    return false;
  }

  do {
    struct sctx_info head;
    if (!range.Read(reserved_address, sizeof(head), &head)) {
      LOG(ERROR) << "missing context terminator";
      return false;
    }
    reserved_address += sizeof(head);
    switch (head.magic) {
      case FPU_CTX_MAGIC:
        if (head.size != sizeof(struct fpu_context) + sizeof(head)) {
          LOG(ERROR) << "unexpected fpu context size " << head.size;
          return false;
        }
        FloatContext::f64_t fpucontext;
        if (!range.Read(reserved_address, sizeof(fpucontext), &fpucontext)) {
          LOG(ERROR) << "Couldn't read fpu " << head.size;
          return false;
        }

        InitializeCPUContextLOONGARCH64_OnlyFPU(fpucontext, dest_context);
        return true;

      //TODO: not support LSX_CTX_MAGIC and LASX_CTX_MAGIC
      //case LSX_CTX_MAGIC:
      //case LASX_CTX_MAGIC:
      //  reserved_address += head.size - sizeof(head);
      //  continue;
      case 0:
        return true;

      default:
        LOG(ERROR) << "invalid magic number 0x" << std::hex << head.magic;
        return false;
    }
  } while (true);
}

template <>
bool ExceptionSnapshotLinux::ReadContext<ContextTraits64>(
    ProcessReaderLinux* reader,
    LinuxVMAddress context_address) {
  context_.architecture = kCPUArchitectureLOONGARCH64;
  context_.loongarch64 = &context_union_.loongarch64;

  return internal::ReadContext<ContextTraits64>(
      reader, context_address, context_.loongarch64);
}

#endif  // ARCH_CPU_X86_FAMILY

bool ExceptionSnapshotLinux::Initialize(
