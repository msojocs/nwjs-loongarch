  void DumpCPUState() {
    RawContextCPU cpu;
    my_memset(&cpu, 0, sizeof(RawContextCPU));
#if !defined(__ARM_EABI__) && !defined(__mips__)
    UContextReader::FillCPUContext(&cpu, ucontext_, float_state_);
#else
    UContextReader::FillCPUContext(&cpu, ucontext_);

//----replace
  void DumpCPUState() {
    RawContextCPU cpu;
    my_memset(&cpu, 0, sizeof(RawContextCPU));
#if !defined(__ARM_EABI__) && !defined(__mips__) && !defined(__loongarch64)
    UContextReader::FillCPUContext(&cpu, ucontext_, float_state_);
#else
    UContextReader::FillCPUContext(&cpu, ucontext_);
