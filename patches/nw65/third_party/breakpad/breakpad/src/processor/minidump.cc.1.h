        break;
      }

      default: {
        // Unknown context type - Don't log as an error yet. Let the
        // caller work that out.

//----replace
        break;
      }

      case MD_CONTEXT_LOONGARCH64: { // loongarch64
        if (expected_size != sizeof(MDRawContextLOONGARCH64)) { // loongarch64
          BPLOG(ERROR) << "MinidumpContext LOONGARCH64 size mismatch, " // loongarch64
                       << expected_size // loongarch64
                       << " != " // loongarch64
                       << sizeof(MDRawContextLOONGARCH64); // loongarch64
          return false; // loongarch64
        } // loongarch64
 // loongarch64
        scoped_ptr<MDRawContextLOONGARCH64> context_loongarch(new MDRawContextLOONGARCH64()); // loongarch64
 // loongarch64
        // Set the context_flags member, which has already been read, and // loongarch64
        // read the rest of the structure beginning with the first member // loongarch64
        // after context_flags. // loongarch64
        context_loongarch->context_flags = context_flags; // loongarch64
 // loongarch64
        size_t flags_size = sizeof(context_loongarch->context_flags); // loongarch64
        uint8_t* context_after_flags = // loongarch64
            reinterpret_cast<uint8_t*>(context_loongarch.get()) + flags_size; // loongarch64
        if (!minidump_->ReadBytes(context_after_flags, // loongarch64
                                  sizeof(MDRawContextLOONGARCH64) - flags_size)) { // loongarch64
          BPLOG(ERROR) << "MinidumpContext could not read LOONGARCH64 context"; // loongarch64
          return false; // loongarch64
        } // loongarch64
 // loongarch64
        // Do this after reading the entire MDRawContext structure because // loongarch64
        // GetSystemInfo may seek minidump to a new position. // loongarch64
        if (!CheckAgainstSystemInfo(cpu_type)) { // loongarch64
          BPLOG(ERROR) << "MinidumpContext LOONGARCH64 does not match system info"; // loongarch64
          return false; // loongarch64
        } // loongarch64
 // loongarch64
        if (minidump_->swap()) { // loongarch64
          // context_loongarch->context_flags was already swapped. // loongarch64
          for (int ireg_index = 0; // loongarch64
               ireg_index < MD_CONTEXT_LOONGARCH64_GPR_COUNT; // loongarch64
               ++ireg_index) { // loongarch64
            Swap(&context_loongarch->iregs[ireg_index]); // loongarch64
          } // loongarch64
          Swap(&context_loongarch->csr_era); // loongarch64
          for (int fpr_index = 0; // loongarch64
               fpr_index < MD_FLOATINGSAVEAREA_LOONGARCH64_FPR_COUNT; // loongarch64
               ++fpr_index) { // loongarch64
            Swap(&context_loongarch->float_save.regs[fpr_index]); // loongarch64
          } // loongarch64
	  Swap(&context_loongarch->float_save.fcc); // loongarch64
	  Swap(&context_loongarch->float_save.fcsr); // loongarch64
        } // loongarch64
        SetContextLOONGARCH64(context_loongarch.release()); // loongarch64
 // loongarch64
        break; // loongarch64
      } // loongarch64
 // loongarch64
      default: {
        // Unknown context type - Don't log as an error yet. Let the
        // caller work that out.
