#include <sys/syscall.h>
#include <unistd.h>
#include <linux/unistd.h>
#include <endian.h>

#ifdef __mips__
/* Include definitions of the ABI currently in use.                          */
#ifdef __ANDROID__
/* Android doesn't have sgidefs.h, but does have asm/sgidefs.h,
 * which has the definitions we need.

//----replace
#include <sys/syscall.h>
#include <unistd.h>
#include <linux/unistd.h>
#include <linux/stat.h> // loongarch64
#include <endian.h>

#ifdef __mips__
/* Include definitions of the ABI currently in use.				*/ // loongarch64
#ifdef __ANDROID__
/* Android doesn't have sgidefs.h, but does have asm/sgidefs.h,
 * which has the definitions we need.
