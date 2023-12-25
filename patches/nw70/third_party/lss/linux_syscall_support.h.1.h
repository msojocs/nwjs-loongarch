                                   void *newtls, int *child_tidptr) {
      int64_t __res;
      {
        register int64_t __res_a0 __asm__("a0");
        register uint64_t __flags __asm__("a0") = flags;
        register void *__stack __asm__("a1") = child_stack;
        register void *__ptid  __asm__("a2") = parent_tidptr;
        register void *__tls   __asm__("a3") = newtls;
        register int  *__ctid  __asm__("a4") = child_tidptr;
        __asm__ __volatile__(/* Push "arg" and "fn" onto the stack that will be
                              * used by the child.
                              */

//----replace
                                   void *newtls, int *child_tidptr) {
      int64_t __res;
      {
        register int64_t __res_a0 __asm__("$a0");
        register uint64_t __flags __asm__("$a0") = flags;
        register void *__stack __asm__("$a1") = child_stack;
        register void *__ptid  __asm__("$a2") = parent_tidptr;
        register void *__tls   __asm__("$a3") = newtls;
        register int  *__ctid  __asm__("$a4") = child_tidptr;
        __asm__ __volatile__(/* Push "arg" and "fn" onto the stack that will be
                              * used by the child.
                              */
