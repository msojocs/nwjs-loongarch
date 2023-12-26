    ret = inout;
  }

#else
#error "Unimplemented architecture"
#endif

//----replace
    ret = inout;
  }

#elif defined(__loongarch64) // loongarch64
  intptr_t ret; // loongarch64
  { // loongarch64
    register intptr_t inout __asm__("$r4") = nr; // loongarch64
    register const intptr_t* data __asm__("$r10") = args; // loongarch64
    asm volatile("bl SyscallAsm\n" // loongarch64
		 : "=r"(inout) // loongarch64
		 : "0"(inout), "r"(data) // loongarch64
		 : "memory", "$r5", "$r6", "$r7", "$r8", "$r9", "$r11", "$r1"); // loongarch64
    ret = inout; // loongarch64
  } // loongarch64
#else
#error "Unimplemented architecture"
#endif
