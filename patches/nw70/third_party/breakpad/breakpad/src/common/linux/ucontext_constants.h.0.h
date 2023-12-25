#define  UCONTEXT_SIGMASK_OFFSET   640
#endif

#elif defined(__x86_64__)

#define MCONTEXT_GREGS_OFFSET     40

//----replace
#define  UCONTEXT_SIGMASK_OFFSET   640
#endif

#elif defined(__loongarch64)

#define MCONTEXT_GREG_SIZE 8
#define MCONTEXT_SIGMASK_OFFSET 40
#define MCONTEXT_PC_OFFSET 176
#define MCONTEXT_GREGS_OFFSET 184

#define STORE_GPR(X) st.d $r##X, $a0, MCONTEXT_GREGS_OFFSET + X * MCONTEXT_GREG_SIZE
#define STORE_PC st.d $ra, $a0, MCONTEXT_PC_OFFSET

#elif defined(__x86_64__)

#define MCONTEXT_GREGS_OFFSET     40
