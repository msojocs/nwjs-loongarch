#endif
#elif defined(__i386__)
        MD_CPU_ARCHITECTURE_X86;
#else
        MD_CPU_ARCHITECTURE_AMD64;
#endif

//----replace
#endif
#elif defined(__i386__)
        MD_CPU_ARCHITECTURE_X86;
#elif defined(__loongarch64)
	MD_CPU_ARCHITECTURE_LOONGARCH64;
#else
        MD_CPU_ARCHITECTURE_AMD64;
#endif
