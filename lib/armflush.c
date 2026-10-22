/* armflush.c - flush the instruction cache

   __clear_cache is used in tccrun.c,  It is a built-in
   intrinsic with gcc.  However tcc in order to compile
   itself needs this function */

/* ------------------------------------------------------------- */
#ఒకవేళ defined __arm__

#నిర్వచితమైతే __TINYC__

/* syscall wrapper */
గుర్తులేని _tccsyscall(గుర్తులేని syscall_nr, ...);

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
#ఒకవేళ defined(__thumb__) || defined(__ARM_EABI__)
# define __NR_SYSCALL_BASE      0x0
#లేకపోతే
# define __NR_SYSCALL_BASE      0x900000
#అయితే_ముగింపు
#నిర్వచించు __ARM_NR_BASE           (__NR_SYSCALL_BASE+0x0f0000)
#నిర్వచించు __ARM_NR_cacheflush     (__ARM_NR_BASE+2)

#నిర్వచించు syscall _tccsyscall

#లేకపోతే

#నిర్వచించు GNU_ఆధారం
#అన్తర్భావ <unistd.h>
#అన్తర్భావ <sys/syscall.h>
#అన్తర్భావ <stdio.h>

#అయితే_ముగింపు

/* Flushing for tccrun */
శూన్య __clear_cache(శూన్య *beginning, శూన్య *చివర)
{
/* __ARM_NR_cacheflush is kernel private and should not be used in user space.
 * However, there is no ARM asm parser in tcc so we use it for now */
    syscall(__ARM_NR_cacheflush, beginning, చివర, 0);
}

/* ------------------------------------------------------------- */
#లేదావేళ defined __aarch64__
శూన్య __clear_cache(శూన్య *beg, శూన్య *చివర)
{
    __arm64_clear_cache(beg, చివర);
}

/* ------------------------------------------------------------- */
#లేదావేళ defined __riscv
శూన్య __clear_cache(శూన్య *beg, శూన్య *చివర)
{
    __riscv64_clear_cache(beg, చివర);
}

#అయితే_ముగింపు
