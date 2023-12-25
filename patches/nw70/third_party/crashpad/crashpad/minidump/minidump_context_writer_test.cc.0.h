                   TypeParam>(context, ExpectMinidumpContextMIPS64, kSeed);
}

}  // namespace
}  // namespace test
}  // namespace crashpad

//----replace
                   TypeParam>(context, ExpectMinidumpContextMIPS64, kSeed);
}

TYPED_TEST(MinidumpContextWriter, LOONGARCH64_Zeros) {
  EmptyContextTest<MinidumpContextLOONGARCH64Writer, MinidumpContextLOONGARCH64>(
      ExpectMinidumpContextLOONGARCH64);
}

TYPED_TEST(MinidumpContextWriter, LOONGARCH64_FromSnapshot) {
  constexpr uint32_t kSeed = 64;
  CPUContextLOONGARCH64 context_loongarch64;
  CPUContext context;
  context.loongarch64 = &context_loongarch64;
  InitializeCPUContextLOONGARCH64(&context, kSeed);
  FromSnapshotTest<MinidumpContextLOONGARCH64Writer, MinidumpContextLOONGARCH64>(
      context, ExpectMinidumpContextLOONGARCH64, kSeed);
}

}  // namespace
}  // namespace test
}  // namespace crashpad
