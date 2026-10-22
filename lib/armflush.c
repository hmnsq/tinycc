/* armflush.c - flush the instruction cache

   __clear_cache is used in tccrun.c,  It is a built-in
   intrinsic with gcc.  However tcc in order to compile
   itself needs this function */

/* ------------------------------------------------------------- */
#जर defined __arm__

#ifdef __TINYC__

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
#जर defined(__thumb__) || defined(__ARM_EABI__)
# define __NR_SYSCALL_BASE      0x0
#अन्यथा
# define __NR_SYSCALL_BASE      0x900000
#endif
#define __ARM_NR_BASE           (__NR_SYSCALL_BASE+0x0f0000)
#define __ARM_NR_cacheflush     (__ARM_NR_BASE+2)

#define syscall _tccsyscall

#अन्यथा

#define _GNU_SOURCE
#अन्तर्भाव <unistd.h>
#अन्तर्भाव <sys/syscall.h>
#अन्तर्भाव <stdio.h>

#endif

/* Flushing for tccrun */
शून्य __clear_cache(शून्य *beginning, शून्य *end)
{
/* __ARM_NR_cacheflush is kernel private and should not be used in user space.
 * However, there is no ARM asm parser in tcc so we use it for now */
    syscall(__ARM_NR_cacheflush, beginning, end, 0);
}

/* ------------------------------------------------------------- */
#किंवाजर defined __aarch64__
शून्य __clear_cache(शून्य *beg, शून्य *end)
{
    __arm64_clear_cache(beg, end);
}

/* ------------------------------------------------------------- */
#किंवाजर defined __riscv
शून्य __clear_cache(शून्य *beg, शून्य *end)
{
    __riscv64_clear_cache(beg, end);
}

#endif
