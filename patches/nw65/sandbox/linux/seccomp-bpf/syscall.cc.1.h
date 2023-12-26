    "2:ret\n"
    ".cfi_endproc\n"
    ".size SyscallAsm, .-SyscallAsm\n"
#endif
    );  // asm


//----replace
    "2:ret\n"
    ".cfi_endproc\n"
    ".size SyscallAsm, .-SyscallAsm\n"
#elif defined(__loongarch64) // loongarch64
    ".text\n" // loongarch64
    ".align 2\n" // loongarch64
    ".type SyscallAsm, %function\n" // loongarch64
    "SyscallAsm:\n" // loongarch64
    ".cfi_startproc\n" // loongarch64
    "bge $a0, $zero, 1f\n" // loongarch64
    "la.local $a0, 2f\n" // loongarch64
    "b 2f\n" // loongarch64
    "1:\n" // loongarch64
    "ld.d $a5, $a6, 40\n" // loongarch64
    "ld.d $a4, $a6, 32\n" // loongarch64
    "ld.d $a3, $a6, 24\n" // loongarch64
    "ld.d $a2, $a6, 16\n" // loongarch64
    "ld.d $a1, $a6, 8\n" // loongarch64
    "move $a7, $a0\n" // loongarch64
    "ld.d $a0, $a6, 0\n" // loongarch64
    "syscall 0\n" // loongarch64
    "2:\n" // loongarch64
    "jirl $zero, $ra, 0\n" // loongarch64
    ".cfi_endproc\n" // loongarch64
    ".size SyscallAsm, .-SyscallAsm\n" // loongarch64
#endif
    );  // asm

