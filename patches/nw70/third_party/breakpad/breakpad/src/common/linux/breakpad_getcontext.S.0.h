  .cfi_endproc
  .size breakpad_getcontext, . - breakpad_getcontext

#elif defined(__i386__)

  .text

//----replace
  .cfi_endproc
  .size breakpad_getcontext, . - breakpad_getcontext

#elif defined(__loongarch64)

#define  _NSIG                       64
#define  __NR_rt_sigprocmask         135

  .text
  .global breakpad_getcontext
  .hidden breakpad_getcontext
  .type breakpad_getcontext, @function
  .align 4
  .cfi_startproc
breakpad_getcontext:
  STORE_PC
  STORE_GPR(0)
  STORE_GPR(1)
  STORE_GPR(2)
  STORE_GPR(3)
  STORE_GPR(4)
  STORE_GPR(5)
  STORE_GPR(6)
  STORE_GPR(7)
  STORE_GPR(8)
  STORE_GPR(9)
  STORE_GPR(10)
  STORE_GPR(11)
  STORE_GPR(12)
  STORE_GPR(13)
  STORE_GPR(14)
  STORE_GPR(15)
  STORE_GPR(16)
  STORE_GPR(17)
  STORE_GPR(18)
  STORE_GPR(19)
  STORE_GPR(20)
  STORE_GPR(21)
  STORE_GPR(22)
  STORE_GPR(23)
  STORE_GPR(24)
  STORE_GPR(25)
  STORE_GPR(26)
  STORE_GPR(27)
  STORE_GPR(28)
  STORE_GPR(29)
  STORE_GPR(30)
  STORE_GPR(31)

  /* rt_sigprocmask (SIG_BLOCK, NULL, &ucp->uc_sigmask, _NSIG8) */
  addi.d $a2, $a0, MCONTEXT_SIGMASK_OFFSET
  move  $a1, $zero
  li.d  $a0, 0
  li.d  $a3, _NSIG / 8
  li.d  $a7, __NR_rt_sigprocmask

  syscall 0

  /* Return zero for success */
  move $a0, $zero

 jirl $zero, $ra, 0

  .cfi_endproc
  .size breakpad_getcontext, . - breakpad_getcontext

#elif defined(__i386__)

  .text
