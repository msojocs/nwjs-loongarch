    ret = inout;
  }

// loongarch start
#elif defined(__loongarch64)
  intptr_t ret;
  {
    register intptr_t inout __asm__("$r4") = nr;
    register const intptr_t* data __asm__("$r10") = args;
    asm volatile("bl SyscallAsm\n"
		 : "=r"(inout)
		 : "0"(inout), "r"(data)
		 : "memory", "$r5", "$r6", "$r7", "$r8", "$r9", "$r11", "$r1");
    ret = inout;
  }
// loongarch end
#else
#error "Unimplemented architecture"