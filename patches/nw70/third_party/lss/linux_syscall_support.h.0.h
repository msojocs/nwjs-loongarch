     * So, we just have to redefine all of the _syscallX() macros.
     */
    #undef LSS_REG
    #define LSS_REG(ar,a) register int64_t __r##ar __asm__("a"#ar) = (int64_t)a
    /* syscall is like subroutine calls, all caller-saved registers may be
     * clobbered, we should add them to the |Clobbers| list.
     * a0 is not included because it's in the output list.
     */
    #define LSS_SYSCALL_CLOBBERS "t0", "t1", "t2", "t3", "t4", "t5", "t6",    \
                                 "t7", "t8", "memory"
    #undef  LSS_BODY
    #define LSS_BODY(type,name,args...)                                       \
          register int64_t __res_a0 __asm__("a0");                            \
          int64_t __res;                                                      \
          __asm__ __volatile__ ("li.d $a7, %1\n"                              \
                                "syscall 0x0\n"                               \

//----replace
     * So, we just have to redefine all of the _syscallX() macros.
     */
    #undef LSS_REG
    #define LSS_REG(ar,a) register int64_t __r##ar __asm__("$a"#ar) = (int64_t)a
    /* syscall is like subroutine calls, all caller-saved registers may be
     * clobbered, we should add them to the |Clobbers| list.
     * a0 is not included because it's in the output list.
     */
    #define LSS_SYSCALL_CLOBBERS "$t0", "$t1", "$t2", "$t3", "$t4", "$t5", "$t6",    \
                                 "$t7", "$t8", "memory"
    #undef  LSS_BODY
    #define LSS_BODY(type,name,args...)                                       \
          register int64_t __res_a0 __asm__("$a0");                            \
          int64_t __res;                                                      \
          __asm__ __volatile__ ("li.d $a7, %1\n"                              \
                                "syscall 0x0\n"                               \
