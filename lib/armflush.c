/* armflush.c - flush the instruction cache

   __clear_cache is used in tccrun.c,  It is a built-in
   intrinsic with gcc.  However tcc in order to compile
   itself needs this function */

/* ------------------------------------------------------------- */
#अगर defined __arm__

#अगर_घोषित __TINYC__

/* syscall wrapper */
अचिन्हित _tccsyscall(अचिन्हित syscall_nr, ...);

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
#अगर defined(__thumb__) || defined(__ARM_EABI__)
# define __NR_SYSCALL_BASE      0x0
#अन्यथा
# define __NR_SYSCALL_BASE      0x900000
#पूर्ण_अगर
#घोषणा __ARM_NR_BASE           (__NR_SYSCALL_BASE+0x0f0000)
#घोषणा __ARM_NR_cacheflush     (__ARM_NR_BASE+2)

#घोषणा syscall _tccsyscall

#अन्यथा

#घोषणा _GNU_SOURCE
#समावेश <unistd.h>
#समावेश <sys/syscall.h>
#समावेश <stdio.h>

#पूर्ण_अगर

/* Flushing for tccrun */
व्योम __clear_cache(व्योम *beginning, व्योम *end)
{
/* __ARM_NR_cacheflush is kernel private and should not be used in user space.
 * However, there is no ARM asm parser in tcc so we use it for now */
    syscall(__ARM_NR_cacheflush, beginning, end, 0);
}

/* ------------------------------------------------------------- */
#या_अगर defined __aarch64__
व्योम __clear_cache(व्योम *beg, व्योम *end)
{
    __arm64_clear_cache(beg, end);
}

/* ------------------------------------------------------------- */
#या_अगर defined __riscv
व्योम __clear_cache(व्योम *beg, व्योम *end)
{
    __riscv64_clear_cache(beg, end);
}

#पूर्ण_अगर
