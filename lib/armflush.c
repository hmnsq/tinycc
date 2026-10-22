/* armflush.c - flush the instruction cache

   __clear_cache is used in tccrun.c,  It is a built-in
   intrinsic with gcc.  However tcc in order to compile
   itself needs this function */

/* ------------------------------------------------------------- */
#എങ്കിൽ defined __arm__

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
#എങ്കിൽ defined(__thumb__) || defined(__ARM_EABI__)
# define __NR_SYSCALL_BASE      0x0
#അല്ലെങ്കിൽ
# define __NR_SYSCALL_BASE      0x900000
#endif
#define __ARM_NR_BASE           (__NR_SYSCALL_BASE+0x0f0000)
#define __ARM_NR_cacheflush     (__ARM_NR_BASE+2)

#define syscall _tccsyscall

#അല്ലെങ്കിൽ

#define _GNU_SOURCE
#അന്തര്ഭാവ <unistd.h>
#അന്തര്ഭാവ <sys/syscall.h>
#അന്തര്ഭാവ <stdio.h>

#endif

/* Flushing for tccrun */
ശൂന്യം __clear_cache(ശൂന്യം *beginning, ശൂന്യം *end)
{
/* __ARM_NR_cacheflush is kernel private and should not be used in user space.
 * However, there is no ARM asm parser in tcc so we use it for now */
    syscall(__ARM_NR_cacheflush, beginning, end, 0);
}

/* ------------------------------------------------------------- */
#അല്ലെങ്കിലെങ്കിൽ defined __aarch64__
ശൂന്യം __clear_cache(ശൂന്യം *beg, ശൂന്യം *end)
{
    __arm64_clear_cache(beg, end);
}

/* ------------------------------------------------------------- */
#അല്ലെങ്കിലെങ്കിൽ defined __riscv
ശൂന്യം __clear_cache(ശൂന്യം *beg, ശൂന്യം *end)
{
    __riscv64_clear_cache(beg, end);
}

#endif
