            ? "MIPS"
            : sysinfo->processor_architecture == MD_CPU_ARCHITECTURE_MIPS64
            ? "MIPS64"
            : "???",
            sysinfo->number_of_processors,
            sysinfo->processor_level,

//----replace
            ? "MIPS"
            : sysinfo->processor_architecture == MD_CPU_ARCHITECTURE_MIPS64
            ? "MIPS64"
	    : sysinfo->processor_architecture == MD_CPU_ARCHITECTURE_LOONGARCH64// loongarch64
	    ? "LOONGARCH64"// loongarch64
            : "???",
            sysinfo->number_of_processors,
            sysinfo->processor_level,
