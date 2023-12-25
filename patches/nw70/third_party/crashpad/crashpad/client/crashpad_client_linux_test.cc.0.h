
  void Initialize() {
    ScopedMmap local_stack_mem;
    constexpr size_t stack_size = MINSIGSTKSZ;
    ASSERT_TRUE(local_stack_mem.ResetMmap(nullptr,
                                          stack_size,
                                          PROT_READ | PROT_WRITE,

//----replace

  void Initialize() {
    ScopedMmap local_stack_mem;
    size_t stack_size = MINSIGSTKSZ;
    ASSERT_TRUE(local_stack_mem.ResetMmap(nullptr,
                                          stack_size,
                                          PROT_READ | PROT_WRITE,
