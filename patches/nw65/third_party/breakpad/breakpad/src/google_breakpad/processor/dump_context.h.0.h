  const MDRawContextPPC64* GetContextPPC64() const;
  const MDRawContextSPARC* GetContextSPARC() const;
  const MDRawContextX86*   GetContextX86() const;

  // A convenience method to get the instruction pointer out of the
  // MDRawContext, since it varies per-CPU architecture.

//----replace
  const MDRawContextPPC64* GetContextPPC64() const;
  const MDRawContextSPARC* GetContextSPARC() const;
  const MDRawContextX86*   GetContextX86() const;
  const MDRawContextLOONGARCH64* GetContextLOONGARCH64() const; // loongarch64

  // A convenience method to get the instruction pointer out of the
  // MDRawContext, since it varies per-CPU architecture.
