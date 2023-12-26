  Context(const Dump& dump, const MDRawContextX86& context);
  Context(const Dump& dump, const MDRawContextARM& context);
  Context(const Dump& dump, const MDRawContextMIPS& context);
  // Add an empty context to the dump.
  Context(const Dump& dump) : Section(dump) {}
  // Add constructors for other architectures here. Remember to byteswap.

//----replace
  Context(const Dump& dump, const MDRawContextX86& context);
  Context(const Dump& dump, const MDRawContextARM& context);
  Context(const Dump& dump, const MDRawContextMIPS& context);
  Context(const Dump& dump, const MDRawContextLOONGARCH64& context);// loongarch64
  // Add an empty context to the dump.
  Context(const Dump& dump) : Section(dump) {}
  // Add constructors for other architectures here. Remember to byteswap.
