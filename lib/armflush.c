/* armflush.c - flush the instruction cache

   __clear_cache is used in tccrun.c,  It is a built-in
   intrinsic with gcc.  However tcc in order to compile
   itself needs this function */

/* ------------------------------------------------------------- */
#ಆದರೆ defined __arm__

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __TINYC__

/* syscall wrapper */
ಚಿಹ್ನೆರಹಿತ _tccsyscall(ಚಿಹ್ನೆರಹಿತ syscall_nr, ...);

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
#ಆದರೆ defined(__thumb__) || defined(__ARM_EABI__)
# define __NR_SYSCALL_BASE      0x0
#ಇಲ್ಲದಿದ್ದರೆ
# define __NR_SYSCALL_BASE      0x900000
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿಸು __ARM_NR_BASE           (__NR_SYSCALL_BASE+0x0f0000)
#ವ್ಯಾಖ್ಯಾನಿಸು __ARM_NR_cacheflush     (__ARM_NR_BASE+2)

#ವ್ಯಾಖ್ಯಾನಿಸು syscall _tccsyscall

#ಇಲ್ಲದಿದ್ದರೆ

#ವ್ಯಾಖ್ಯಾನಿಸು GNU_ಮೂಲ
#ಅನ್ತರ್ಭಾವ <unistd.h>
#ಅನ್ತರ್ಭಾವ <sys/syscall.h>
#ಅನ್ತರ್ಭಾವ <stdio.h>

#ಆದರೆ_ಅಂತ್ಯ

/* Flushing for tccrun */
ಶೂನ್ಯ __clear_cache(ಶೂನ್ಯ *beginning, ಶೂನ್ಯ *ಕೊನೆ)
{
/* __ARM_NR_cacheflush is kernel private and should not be used in user space.
 * However, there is no ARM asm parser in tcc so we use it for now */
    syscall(__ARM_NR_cacheflush, beginning, ಕೊನೆ, 0);
}

/* ------------------------------------------------------------- */
#ಅಥವಾಆದರೆ defined __aarch64__
ಶೂನ್ಯ __clear_cache(ಶೂನ್ಯ *beg, ಶೂನ್ಯ *ಕೊನೆ)
{
    __arm64_clear_cache(beg, ಕೊನೆ);
}

/* ------------------------------------------------------------- */
#ಅಥವಾಆದರೆ defined __riscv
ಶೂನ್ಯ __clear_cache(ಶೂನ್ಯ *beg, ಶೂನ್ಯ *ಕೊನೆ)
{
    __riscv64_clear_cache(beg, ಕೊನೆ);
}

#ಆದರೆ_ಅಂತ್ಯ
