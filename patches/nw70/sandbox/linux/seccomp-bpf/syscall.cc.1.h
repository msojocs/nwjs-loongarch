    "2:ret\n"
    ".cfi_endproc\n"
    ".size SyscallAsm, .-SyscallAsm\n"
#endif
    );  // asm


//----replace
    "2:ret\n"
    ".cfi_endproc\n"
    ".size SyscallAsm, .-SyscallAsm\n"
#elif defined(__loongarch64)
    ".text\n"
    ".align 2\n"
    ".type SyscallAsm, %function\n"
    "SyscallAsm:\n"
    ".cfi_startproc\n"
    "bge $a0, $zero, 1f\n"
    "la.local $a0, 2f\n"
    "b 2f\n"
    "1:\n"
    "ld.d $a5, $a6, 40\n"
    "ld.d $a4, $a6, 32\n"
    "ld.d $a3, $a6, 24\n"
    "ld.d $a2, $a6, 16\n"
    "ld.d $a1, $a6, 8\n"
    "move $a7, $a0\n"
    "ld.d $a0, $a6, 0\n"
    "syscall 0\n"
    "2:\n"
    "jirl $zero, $ra, 0\n"
    ".cfi_endproc\n"
    ".size SyscallAsm, .-SyscallAsm\n"
#endif
    );  // asm

