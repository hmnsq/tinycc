/* armflush.c - flush the instruction cache

   __clear_cache is used in tccrun.c,  It is a built-in
   intrinsic with gcc.  However tcc in order to compile
   itself needs this function */

/* ------------------------------------------------------------- */
#إذا defined __arm__

#جے_تعریف_شدہ __TINYC__

/* syscall wrapper */
بنانشانی _tccsyscall(بنانشانی syscall_nr, ...);

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
#إذا defined(__thumb__) || defined(__ARM_EABI__)
# define __NR_SYSCALL_BASE      0x0
#وإلا
# define __NR_SYSCALL_BASE      0x900000
#جے_انت
#تعریف_کرو __ARM_NR_BASE           (__NR_SYSCALL_BASE+0x0f0000)
#تعریف_کرو __ARM_NR_cacheflush     (__ARM_NR_BASE+2)

#تعریف_کرو syscall _tccsyscall

#وإلا

#تعریف_کرو GNU_سروت
#ضمن <unistd.h>
#ضمن <sys/syscall.h>
#ضمن <stdio.h>

#جے_انت

/* Flushing for tccrun */
فراغ __clear_cache(فراغ *beginning, فراغ *سرا)
{
/* __ARM_NR_cacheflush is kernel private and should not be used in user space.
 * However, there is no ARM asm parser in tcc so we use it for now */
    syscall(__ARM_NR_cacheflush, beginning, سرا, 0);
}

/* ------------------------------------------------------------- */
#وإلاإذا defined __aarch64__
فراغ __clear_cache(فراغ *beg, فراغ *سرا)
{
    __arm64_clear_cache(beg, سرا);
}

/* ------------------------------------------------------------- */
#وإلاإذا defined __riscv
فراغ __clear_cache(فراغ *beg, فراغ *سرا)
{
    __riscv64_clear_cache(beg, سرا);
}

#جے_انت
