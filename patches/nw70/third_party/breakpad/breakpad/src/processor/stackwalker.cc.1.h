                                             memory, modules,
                                             frame_symbolizer);
      break;
  }

  BPLOG_IF(ERROR, !cpu_stackwalker) << "Unknown CPU type " << HexString(cpu) <<

//----replace
                                             memory, modules,
                                             frame_symbolizer);
      break;

    case MD_CONTEXT_LOONGARCH64:
      cpu_stackwalker = new StackwalkerLOONGARCH64(system_info,
		      				   context->GetContextLOONGARCH64(),
						   memory, modules, frame_symbolizer);
      break;
  }

  BPLOG_IF(ERROR, !cpu_stackwalker) << "Unknown CPU type " << HexString(cpu) <<
