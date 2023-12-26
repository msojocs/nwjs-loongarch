  jr $ra

  .set at
#endif  // __i386__

//----replace
  jr $ra

  .set at
#elif defined(__loongarch64)// loongarch64
// loongarch64
#define MCONTEXT_GREG_SIZE 8// loongarch64
#define MCONTEXT_PC_OFFSET 176// loongarch64
#define MCONTEXT_GREGS_OFFSET 184// loongarch64
// loongarch64
#define STORE_GPR(X) st.d $r##X, $a0, MCONTEXT_GREGS_OFFSET + X * MCONTEXT_GREG_SIZE// loongarch64
#define STORE_PC st.d $ra, $a0, MCONTEXT_PC_OFFSET// loongarch64
// loongarch64
  STORE_PC// loongarch64
  STORE_GPR(0)// loongarch64
  STORE_GPR(1)// loongarch64
  STORE_GPR(2)// loongarch64
  STORE_GPR(3)// loongarch64
  STORE_GPR(4)// loongarch64
  STORE_GPR(5)// loongarch64
  STORE_GPR(6)// loongarch64
  STORE_GPR(7)// loongarch64
  STORE_GPR(8)// loongarch64
  STORE_GPR(9)// loongarch64
  STORE_GPR(10)// loongarch64
  STORE_GPR(11)// loongarch64
  STORE_GPR(12)// loongarch64
  STORE_GPR(13)// loongarch64
  STORE_GPR(14)// loongarch64
  STORE_GPR(15)// loongarch64
  STORE_GPR(16)// loongarch64
  STORE_GPR(17)// loongarch64
  STORE_GPR(18)// loongarch64
  STORE_GPR(19)// loongarch64
  STORE_GPR(20)// loongarch64
  STORE_GPR(21)// loongarch64
  STORE_GPR(22)// loongarch64
  STORE_GPR(23)// loongarch64
  STORE_GPR(24)// loongarch64
  STORE_GPR(25)// loongarch64
  STORE_GPR(26)// loongarch64
  STORE_GPR(27)// loongarch64
  STORE_GPR(28)// loongarch64
  STORE_GPR(29)// loongarch64
  STORE_GPR(30)// loongarch64
  STORE_GPR(31)// loongarch64
// loongarch64
  jirl $zero, $ra, 0// loongarch64
#endif  // __i386__
