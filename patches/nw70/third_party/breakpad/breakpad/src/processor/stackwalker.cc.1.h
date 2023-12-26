                                             memory, modules,
                                             frame_symbolizer);
      break;
  }

  BPLOG_IF(ERROR, !cpu_stackwalker) << "Unknown CPU type " << HexString(cpu) <<

//----replace
                                             memory, modules,
                                             frame_symbolizer);
      break;
// loongarch64
    case MD_CONTEXT_LOONGARCH64:// loongarch64
      cpu_stackwalker = new StackwalkerLOONGARCH64(system_info,// loongarch64
		      				   context->GetContextLOONGARCH64(),// loongarch64
						   memory, modules, frame_symbolizer);// loongarch64
      break;// loongarch64
  }

  BPLOG_IF(ERROR, !cpu_stackwalker) << "Unknown CPU type " << HexString(cpu) <<
