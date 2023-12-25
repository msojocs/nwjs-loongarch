      break;
    }

    default: {
      break;
    }

//----replace
      break;
    }

    case MD_CONTEXT_LOONGARCH64: {
      const MDRawContextLOONGARCH64* context_loongarch = GetContextLOONGARCH64();
      printf("MDRawContextLOONGARCH64\n");
      printf("	context_flags		= 0x%x\n",
	     context_loongarch->context_flags);
      for (int ireg_index = 0;
	   ireg_index < MD_CONTEXT_LOONGARCH64_GPR_COUNT;
	   ++ireg_index) {
      printf("	iregs[%2d]		= 0x%" PRIx64 "\n",
		ireg_index, context_loongarch->iregs[ireg_index]);
      }

      printf("	csr_era			= 0x%" PRIx64 "\n",
	     context_loongarch->csr_era);
      for (int fpr_index = 0;
	   fpr_index < MD_FLOATINGSAVEAREA_LOONGARCH64_FPR_COUNT;
	   ++fpr_index) {
	 printf("  float_save.regs[%2d] = 0x%" PRIx64 "\n",
		fpr_index, context_loongarch->float_save.regs[fpr_index]);
      }

      printf("  float_save.fcc		= 0x%" PRIx64 "\n",
	     context_loongarch->float_save.fcc);
      printf("	float_save.fcsr		= 0x%" PRIx32 "\n",
	     context_loongarch->float_save.fcsr);
      break;
    }

    default: {
      break;
    }
