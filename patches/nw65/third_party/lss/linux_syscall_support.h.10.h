      }
      LSS_RETURN(int, __res);
    }
  #elif defined(__mips__)
    #undef LSS_REG
    #define LSS_REG(r,a) register unsigned long __r##r __asm__("$"#r) =       \

//----replace
      }
      LSS_RETURN(int, __res);
    }
  #elif defined(__loongarch64) // loongarch64
    #undef LSS_REG // loongarch64
    #define LSS_REG(r,a) register int64_t __r##r __asm__("$a"#r) = (int64_t)a // loongarch64
    #undef  LSS_BODY // loongarch64
    #define LSS_BODY(type,name,args...)                                       \
          register int64_t __res_a0 __asm__("$a0");                           \
          register int64_t __a7 __asm__("$a7") = __NR_##name;                 \
          int64_t __res;                                                      \
          __asm__ __volatile__ ("syscall 0\n"                                 \
                                : "=r"(__res_a0)                              \
                                : "r"(__a7) , ## args                         \
                                : "memory");                                  \
          __res = __res_a0;                                                   \
          LSS_RETURN(type, __res) // loongarch64
    #undef _syscall0 // loongarch64
    #define _syscall0(type, name)                                             \
      type LSS_NAME(name)(void) {                                             \
        LSS_BODY(type, name);                                                 \
      } // loongarch64
    #undef _syscall1 // loongarch64
    #define _syscall1(type, name, type1, arg1)                                \
      type LSS_NAME(name)(type1 arg1) {                                       \
        LSS_REG(0, arg1); LSS_BODY(type, name, "r"(__r0));                    \
      } // loongarch64
    #undef _syscall2 // loongarch64
    #define _syscall2(type, name, type1, arg1, type2, arg2)                   \
      type LSS_NAME(name)(type1 arg1, type2 arg2) {                           \
        LSS_REG(0, arg1); LSS_REG(1, arg2);                                   \
        LSS_BODY(type, name, "r"(__r0), "r"(__r1));                           \
      } // loongarch64
    #undef _syscall3 // loongarch64
    #define _syscall3(type, name, type1, arg1, type2, arg2, type3, arg3)      \
      type LSS_NAME(name)(type1 arg1, type2 arg2, type3 arg3) {               \
        LSS_REG(0, arg1); LSS_REG(1, arg2); LSS_REG(2, arg3);                 \
        LSS_BODY(type, name, "r"(__r0), "r"(__r1), "r"(__r2));                \
      } // loongarch64
    #undef _syscall4 // loongarch64
    #define _syscall4(type,name,type1,arg1,type2,arg2,type3,arg3,type4,arg4)  \
      type LSS_NAME(name)(type1 arg1, type2 arg2, type3 arg3, type4 arg4) {   \
        LSS_REG(0, arg1); LSS_REG(1, arg2); LSS_REG(2, arg3);                 \
        LSS_REG(3, arg4);                                                     \
        LSS_BODY(type, name, "r"(__r0), "r"(__r1), "r"(__r2), "r"(__r3));     \
      } // loongarch64
    #undef _syscall5 // loongarch64
    #define _syscall5(type,name,type1,arg1,type2,arg2,type3,arg3,type4,arg4,  \
                      type5,arg5)                                             \
      type LSS_NAME(name)(type1 arg1, type2 arg2, type3 arg3, type4 arg4,     \
                          type5 arg5) {                                       \
        LSS_REG(0, arg1); LSS_REG(1, arg2); LSS_REG(2, arg3);                 \
        LSS_REG(3, arg4); LSS_REG(4, arg5);                                   \
        LSS_BODY(type, name, "r"(__r0), "r"(__r1), "r"(__r2), "r"(__r3),      \
                             "r"(__r4));                                      \
      } // loongarch64
    #undef _syscall6 // loongarch64
    #define _syscall6(type,name,type1,arg1,type2,arg2,type3,arg3,type4,arg4,  \
                      type5,arg5,type6,arg6)                                  \
      type LSS_NAME(name)(type1 arg1, type2 arg2, type3 arg3, type4 arg4,     \
                          type5 arg5, type6 arg6) {                           \
        LSS_REG(0, arg1); LSS_REG(1, arg2); LSS_REG(2, arg3);                 \
        LSS_REG(3, arg4); LSS_REG(4, arg5); LSS_REG(5, arg6);                 \
        LSS_BODY(type, name, "r"(__r0), "r"(__r1), "r"(__r2), "r"(__r3),      \
                             "r"(__r4), "r"(__r5));                           \
      } // loongarch64
 // loongarch64
    LSS_INLINE int LSS_NAME(clone)(int (*fn)(void *), void *child_stack, // loongarch64
                                   int flags, void *arg, int *parent_tidptr, // loongarch64
                                   void *newtls, int *child_tidptr) { // loongarch64
      int64_t __res; // loongarch64
      { // loongarch64
        register uint64_t __flags __asm__("$a0") = flags; // loongarch64
        register void *__stack __asm__("$a1") = child_stack; // loongarch64
        register void *__ptid  __asm__("$a2") = parent_tidptr; // loongarch64
        register void *__tls   __asm__("$a3") = newtls; // loongarch64
        register int  *__ctid  __asm__("$a4") = child_tidptr; // loongarch64
        __asm__ __volatile__(/* Push "arg" and "fn" onto the stack that will be // loongarch64
                              * used by the child. // loongarch64
                              */ // loongarch64
                             "addi.d  %2,%2, -16\n" // loongarch64
                             "st.d    %1,%2, 8\n" // loongarch64
                             "st.d    %4,%2, 0\n" // loongarch64
 // loongarch64
                             /* %a0 = syscall(%a0 = flags, // loongarch64
                              *               %a1 = child_stack, // loongarch64
                              *               %a2 = parent_tidptr, // loongarch64
                              *               %a3 = newtls, // loongarch64
                              *               %a4 = child_tidptr) // loongarch64
                              */ // loongarch64
                             "li.w    $a7, %8\n" // loongarch64
                             "syscall 0\n" // loongarch64
 // loongarch64
                             /* if (%a0 != 0) // loongarch64
                              *   return %a0; // loongarch64
                              */ // loongarch64
			     "move    %0, $a0\n" // loongarch64
                             "bnez    $a0, 1f\n" // loongarch64
 // loongarch64
                             /* In the child, now. Call "fn(arg)". // loongarch64
                              */ // loongarch64
                             "ld.d    $a0, $sp, 0\n" // loongarch64
                             "ld.d    $a1, $sp, 8\n" // loongarch64
                             "jirl    $ra, $a1, 0\n" // loongarch64
 // loongarch64
                             /* Call _exit(%a0). // loongarch64
                              */ // loongarch64
                             "li.w     $a7, %9\n" // loongarch64
                             "syscall  0\n" // loongarch64
                           "1:\n" // loongarch64
                             : "=r" (__res) // loongarch64
                             : "r"(fn), "r"(__stack), "r"(__flags), "r"(arg), // loongarch64
                               "r"(__ptid), "r"(__tls), "r"(__ctid), // loongarch64
                               "i"(__NR_clone), "i"(__NR_exit) // loongarch64
                             : "cc", "memory"); // loongarch64
      } // loongarch64
      LSS_RETURN(int, __res); // loongarch64
    } // loongarch64
  #elif defined(__mips__)
    #undef LSS_REG
    #define LSS_REG(r,a) register unsigned long __r##r __asm__("$"#r) =       \
