/* armflush.c - flush the instruction cache

   __clear_cache is used in tccrun.c,  It is a built-in
   intrinsic with gcc.  However tcc in order to compile
   itself needs this function */

/* ------------------------------------------------------------- */
#ଯଦି defined __arm__

#ifdef __TINYC__

/* syscall wrapper */
unsigned _tccsyscall(unsigned syscall_nr, ...);

/* arm-tcc supports only fake asm currently */
__asm__(
    ".global _tccsyscall\n"
    "_tccsyscall:\n"
    "push    {r7, lr}\n\t"
    "mov     r7, r0\n\t"
    "mov     r0, r1\n\t"
    "mov     r1, r2\n\t"
    "mov     r2, r3\n\t"
    "svc     #0\n\t"
    "pop     {r7, pc}"
    );

/* from unistd.h: */
#ଯଦି defined(__thumb__) || defined(__ARM_EABI__)
# define __NR_SYSCALL_BASE      0x0
#ଅନ୍ୟଥା
# define __NR_SYSCALL_BASE      0x900000
#endif
#define __ARM_NR_BASE           (__NR_SYSCALL_BASE+0x0f0000)
#define __ARM_NR_cacheflush     (__ARM_NR_BASE+2)

#define syscall _tccsyscall

#ଅନ୍ୟଥା

#define _GNU_SOURCE
#ଅନ୍ତର୍ଭାଵ <unistd.h>
#ଅନ୍ତର୍ଭାଵ <sys/syscall.h>
#ଅନ୍ତର୍ଭାଵ <stdio.h>

#endif

/* Flushing for tccrun */
ଶୂନ୍ୟ __clear_cache(ଶୂନ୍ୟ *beginning, ଶୂନ୍ୟ *end)
{
/* __ARM_NR_cacheflush is kernel private and should not be used in user space.
 * However, there is no ARM asm parser in tcc so we use it for now */
    syscall(__ARM_NR_cacheflush, beginning, end, 0);
}

/* ------------------------------------------------------------- */
#ନଚେତଯଦି defined __aarch64__
ଶୂନ୍ୟ __clear_cache(ଶୂନ୍ୟ *beg, ଶୂନ୍ୟ *end)
{
    __arm64_clear_cache(beg, end);
}

/* ------------------------------------------------------------- */
#ନଚେତଯଦି defined __riscv
ଶୂନ୍ୟ __clear_cache(ଶୂନ୍ୟ *beg, ଶୂନ୍ୟ *end)
{
    __riscv64_clear_cache(beg, end);
}

#endif
