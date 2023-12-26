      : fd_(minidump_fd),
        path_(minidump_path),
        ucontext_(context ? &context->context : NULL),
#if !defined(__ARM_EABI__) && !defined(__mips__)
        float_state_(context ? &context->float_state : NULL),
#endif
        dumper_(dumper),

//----replace
      : fd_(minidump_fd),
        path_(minidump_path),
        ucontext_(context ? &context->context : NULL),
#if !defined(__ARM_EABI__) && !defined(__mips__) && !defined(__loongarch64) // loongarch64
        float_state_(context ? &context->float_state : NULL),
#endif
        dumper_(dumper),
