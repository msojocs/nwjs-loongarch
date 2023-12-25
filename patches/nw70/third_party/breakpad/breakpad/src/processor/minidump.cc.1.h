        break;
      }

      default: {
        // Unknown context type - Don't log as an error yet. Let the
        // caller work that out.

//----replace
        break;
      }

      case MD_CONTEXT_LOONGARCH64: {
        if (expected_size != sizeof(MDRawContextLOONGARCH64)) {
          BPLOG(ERROR) << "MinidumpContext LOONGARCH64 size mismatch, "
                       << expected_size
                       << " != "
                       << sizeof(MDRawContextLOONGARCH64);
          return false;
        }

        scoped_ptr<MDRawContextLOONGARCH64> context_loongarch(new MDRawContextLOONGARCH64());

        // Set the context_flags member, which has already been read, and
        // read the rest of the structure beginning with the first member
        // after context_flags.
        context_loongarch->context_flags = context_flags;

        size_t flags_size = sizeof(context_loongarch->context_flags);
        uint8_t* context_after_flags =
            reinterpret_cast<uint8_t*>(context_loongarch.get()) + flags_size;
        if (!minidump_->ReadBytes(context_after_flags,
                                  sizeof(MDRawContextLOONGARCH64) - flags_size)) {
          BPLOG(ERROR) << "MinidumpContext could not read LOONGARCH64 context";
          return false;
        }

        // Do this after reading the entire MDRawContext structure because
        // GetSystemInfo may seek minidump to a new position.
        if (!CheckAgainstSystemInfo(cpu_type)) {
          BPLOG(ERROR) << "MinidumpContext LOONGARCH64 does not match system info";
          return false;
        }

        if (minidump_->swap()) {
          // context_loongarch->context_flags was already swapped.
          for (int ireg_index = 0;
               ireg_index < MD_CONTEXT_LOONGARCH64_GPR_COUNT;
               ++ireg_index) {
            Swap(&context_loongarch->iregs[ireg_index]);
          }
          Swap(&context_loongarch->csr_era);
          for (int fpr_index = 0;
               fpr_index < MD_FLOATINGSAVEAREA_LOONGARCH64_FPR_COUNT;
               ++fpr_index) {
            Swap(&context_loongarch->float_save.regs[fpr_index]);
          }
	  Swap(&context_loongarch->float_save.fcc);
	  Swap(&context_loongarch->float_save.fcsr);
        }
        SetContextLOONGARCH64(context_loongarch.release());

        break;
      }

      default: {
        // Unknown context type - Don't log as an error yet. Let the
        // caller work that out.
