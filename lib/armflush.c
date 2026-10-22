/* armflush.c - flush the instruction cache

   __clear_cache is used in tccrun.c,  It is a built-in
   intrinsic with gcc.  However tcc in order to compile
   itself needs this function */

/* ------------------------------------------------------------- */
#ਜੇ defined __arm__

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __TINYC__

/* syscall wrapper */
ਬਿਨਾਨਿਸ਼ਾਨੀ _tccsyscall(ਬਿਨਾਨਿਸ਼ਾਨੀ syscall_nr, ...);

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
#ਜੇ defined(__thumb__) || defined(__ARM_EABI__)
# define __NR_SYSCALL_BASE      0x0
#ਨਹੀਂਤਾਂ
# define __NR_SYSCALL_BASE      0x900000
#ਜੇ_ਅੰਤ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __ARM_NR_BASE           (__NR_SYSCALL_BASE+0x0f0000)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __ARM_NR_cacheflush     (__ARM_NR_BASE+2)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ syscall _tccsyscall

#ਨਹੀਂਤਾਂ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GNU_ਸਰੋਤ
#ਅਨ੍ਤਰ੍ਭਾਵ <unistd.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <sys/syscall.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>

#ਜੇ_ਅੰਤ

/* Flushing for tccrun */
ਖਾਲੀ __clear_cache(ਖਾਲੀ *beginning, ਖਾਲੀ *ਸਿਰਾ)
{
/* __ARM_NR_cacheflush is kernel private and should not be used in user space.
 * However, there is no ARM asm parser in tcc so we use it for now */
    syscall(__ARM_NR_cacheflush, beginning, ਸਿਰਾ, 0);
}

/* ------------------------------------------------------------- */
#ਜਾਂਜੇ defined __aarch64__
ਖਾਲੀ __clear_cache(ਖਾਲੀ *beg, ਖਾਲੀ *ਸਿਰਾ)
{
    __arm64_clear_cache(beg, ਸਿਰਾ);
}

/* ------------------------------------------------------------- */
#ਜਾਂਜੇ defined __riscv
ਖਾਲੀ __clear_cache(ਖਾਲੀ *beg, ਖਾਲੀ *ਸਿਰਾ)
{
    __riscv64_clear_cache(beg, ਸਿਰਾ);
}

#ਜੇ_ਅੰਤ
