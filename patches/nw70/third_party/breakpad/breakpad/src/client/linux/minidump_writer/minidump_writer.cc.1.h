        if (!cpu.Allocate())
          return false;
        my_memset(cpu.get(), 0, sizeof(RawContextCPU));
#if !defined(__ARM_EABI__) && !defined(__mips__)
        UContextReader::FillCPUContext(cpu.get(), ucontext_, float_state_);
#else
        UContextReader::FillCPUContext(cpu.get(), ucontext_);

//----replace
        if (!cpu.Allocate())
          return false;
        my_memset(cpu.get(), 0, sizeof(RawContextCPU));
#if !defined(__ARM_EABI__) && !defined(__mips__) && !defined(__loongarch64)// loongarch64
        UContextReader::FillCPUContext(cpu.get(), ucontext_, float_state_);
#else
        UContextReader::FillCPUContext(cpu.get(), ucontext_);
