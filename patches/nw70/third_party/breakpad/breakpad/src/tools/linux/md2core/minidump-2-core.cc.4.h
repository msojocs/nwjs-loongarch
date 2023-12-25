# else
#  error "This mips ABI is currently not supported (n32)"
# endif
#else
#error "This code has not been ported to your platform yet"
#endif

//----replace
# else
#  error "This mips ABI is currently not supported (n32)"
# endif
#elif defined(__loongarch64)
  if (sysinfo->processor_architecture != MD_CPU_ARCHITECTURE_LOONGARCH64) {
    fprintf(stderr,
	    "This version of minidump-2-core only supports Loongarch64.\n");
    exit(1);
  }
#else
#error "This code has not been ported to your platform yet"
#endif
