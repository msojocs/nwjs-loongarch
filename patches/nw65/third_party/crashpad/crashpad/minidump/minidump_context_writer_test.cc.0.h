      context, ExpectMinidumpContextMIPS64, kSeed);
}

}  // namespace
}  // namespace test
}  // namespace crashpad

//----replace
      context, ExpectMinidumpContextMIPS64, kSeed);
}

TEST(MinidumpContextWriter, LOONGARCH64_Zeros) { // loongarch64
  EmptyContextTest<MinidumpContextLOONGARCH64Writer, MinidumpContextLOONGARCH64>( // loongarch64
      ExpectMinidumpContextLOONGARCH64); // loongarch64
} // loongarch64
 // loongarch64
TEST(MinidumpContextWriter, LOONGARCH64_FromSnapshot) { // loongarch64
  constexpr uint32_t kSeed = 64; // loongarch64
  CPUContextLOONGARCH64 context_loongarch64; // loongarch64
  CPUContext context; // loongarch64
  context.loongarch64 = &context_loongarch64; // loongarch64
  InitializeCPUContextLOONGARCH64(&context, kSeed); // loongarch64
  FromSnapshotTest<MinidumpContextLOONGARCH64Writer, MinidumpContextLOONGARCH64>( // loongarch64
      context, ExpectMinidumpContextLOONGARCH64, kSeed); // loongarch64
} // loongarch64
 // loongarch64
}  // namespace
}  // namespace test
}  // namespace crashpad
