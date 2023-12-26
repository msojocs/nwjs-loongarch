      break;
    }

    default: {
      break;
    }

//----replace
      break;
    }

    case MD_CONTEXT_LOONGARCH64: { // loongarch64
      const MDRawContextLOONGARCH64* context_loongarch = GetContextLOONGARCH64(); // loongarch64
      printf("MDRawContextLOONGARCH64\n"); // loongarch64
      printf("	context_flags		= 0x%x\n", // loongarch64
	     context_loongarch->context_flags); // loongarch64
      for (int ireg_index = 0; // loongarch64
	   ireg_index < MD_CONTEXT_LOONGARCH64_GPR_COUNT; // loongarch64
	   ++ireg_index) { // loongarch64
      printf("	iregs[%2d]		= 0x%" PRIx64 "\n", // loongarch64
		ireg_index, context_loongarch->iregs[ireg_index]); // loongarch64
      } // loongarch64
 // loongarch64
      printf("	csr_era			= 0x%" PRIx64 "\n", // loongarch64
	     context_loongarch->csr_era); // loongarch64
      for (int fpr_index = 0; // loongarch64
	   fpr_index < MD_FLOATINGSAVEAREA_LOONGARCH64_FPR_COUNT; // loongarch64
	   ++fpr_index) { // loongarch64
	 printf("  float_save.regs[%2d] = 0x%" PRIx64 "\n", // loongarch64
		fpr_index, context_loongarch->float_save.regs[fpr_index]); // loongarch64
      } // loongarch64
 // loongarch64
      printf("  float_save.fcc		= 0x%" PRIx64 "\n", // loongarch64
	     context_loongarch->float_save.fcc); // loongarch64
      printf("	float_save.fcsr		= 0x%" PRIx32 "\n", // loongarch64
	     context_loongarch->float_save.fcsr); // loongarch64
      break; // loongarch64
    } // loongarch64
 // loongarch64
    default: {
      break;
    }
