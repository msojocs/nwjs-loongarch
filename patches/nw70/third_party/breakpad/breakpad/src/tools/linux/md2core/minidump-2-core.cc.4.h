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
#elif defined(__loongarch64)// loongarch64
  if (sysinfo->processor_architecture != MD_CPU_ARCHITECTURE_LOONGARCH64) {// loongarch64
    fprintf(stderr,// loongarch64
	    "This version of minidump-2-core only supports Loongarch64.\n");// loongarch64
    exit(1);// loongarch64
  }// loongarch64
#else
#error "This code has not been ported to your platform yet"
#endif
