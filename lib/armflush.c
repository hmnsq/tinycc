/* armflush.c - flush the instruction cache

   __clear_cache is used in tccrun.c,  It is a built-in
   intrinsic with gcc.  However tcc in order to compile
   itself needs this function */

/* ------------------------------------------------------------- */
#اگر defined __arm__

#اگر_تعریف_شدہ __TINYC__

/* syscall wrapper */
غیرعلامتی _tccsyscall(غیرعلامتی syscall_nr, ...);

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
#اگر defined(__thumb__) || defined(__ARM_EABI__)
# define __NR_SYSCALL_BASE      0x0
#ورنہ
# define __NR_SYSCALL_BASE      0x900000
#اگر_ختم
#تعریف_کرو __ARM_NR_BASE           (__NR_SYSCALL_BASE+0x0f0000)
#تعریف_کرو __ARM_NR_cacheflush     (__ARM_NR_BASE+2)

#تعریف_کرو syscall _tccsyscall

#ورنہ

#تعریف_کرو GNU_ماخذ
#شامل <unistd.h>
#شامل <sys/syscall.h>
#شامل <stdio.h>

#اگر_ختم

/* Flushing for tccrun */
خالی __clear_cache(خالی *beginning, خالی *انتہا)
{
/* __ARM_NR_cacheflush is kernel private and should not be used in user space.
 * However, there is no ARM asm parser in tcc so we use it for now */
    syscall(__ARM_NR_cacheflush, beginning, انتہا, 0);
}

/* ------------------------------------------------------------- */
#وگرنہ_اگر defined __aarch64__
خالی __clear_cache(خالی *beg, خالی *انتہا)
{
    __arm64_clear_cache(beg, انتہا);
}

/* ------------------------------------------------------------- */
#وگرنہ_اگر defined __riscv
خالی __clear_cache(خالی *beg, خالی *انتہا)
{
    __riscv64_clear_cache(beg, انتہا);
}

#اگر_ختم
