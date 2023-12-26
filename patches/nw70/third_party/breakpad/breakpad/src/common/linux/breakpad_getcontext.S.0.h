  .cfi_endproc
  .size breakpad_getcontext, . - breakpad_getcontext

#elif defined(__i386__)

  .text

//----replace
  .cfi_endproc
  .size breakpad_getcontext, . - breakpad_getcontext

#elif defined(__loongarch64)// loongarch64
// loongarch64
#define  _NSIG                       64// loongarch64
#define  __NR_rt_sigprocmask         135// loongarch64
// loongarch64
  .text// loongarch64
  .global breakpad_getcontext// loongarch64
  .hidden breakpad_getcontext// loongarch64
  .type breakpad_getcontext, @function// loongarch64
  .align 4// loongarch64
  .cfi_startproc// loongarch64
breakpad_getcontext:// loongarch64
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
  /* rt_sigprocmask (SIG_BLOCK, NULL, &ucp->uc_sigmask, _NSIG8) */// loongarch64
  addi.d $a2, $a0, MCONTEXT_SIGMASK_OFFSET// loongarch64
  move  $a1, $zero// loongarch64
  li.d  $a0, 0// loongarch64
  li.d  $a3, _NSIG / 8// loongarch64
  li.d  $a7, __NR_rt_sigprocmask// loongarch64
// loongarch64
  syscall 0// loongarch64
// loongarch64
  /* Return zero for success */// loongarch64
  move $a0, $zero// loongarch64
// loongarch64
 jirl $zero, $ra, 0// loongarch64
// loongarch64
  .cfi_endproc// loongarch64
  .size breakpad_getcontext, . - breakpad_getcontext// loongarch64
// loongarch64
#elif defined(__i386__)

  .text
