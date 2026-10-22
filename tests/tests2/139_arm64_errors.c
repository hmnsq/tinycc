/* ARM64 inline assembly error tests.
   Verify that invalid assembly produces proper error messages.
   Run with -dt; skipped on non-arm64 architectures. */

#include <stdio.h>

#ប្រសិនបើ defined test_unknown_instruction
ចំនួនគត់ main(void)
{
    __asm__("fubar x0, x1, x2");
    ត្រឡប់ 0;
}

#elif defined test_shift_imm_range_32
ចំនួនគត់ main(void)
{
    /* LSL by 32 is out of range for 32-bit operand */
    __asm__("lsl w0, w1, #32");
    ត្រឡប់ 0;
}

#elif defined test_shift_imm_range_64
ចំនួនគត់ main(void)
{
    /* LSL by 64 is out of range for 64-bit operand */
    __asm__("lsl x0, x1, #64");
    ត្រឡប់ 0;
}

#elif defined test_invalid_sysreg
ចំនួនគត់ main(void)
{
    /* Bogus system register name */
    __asm__("mrs x0, bogusreg");
    ត្រឡប់ 0;
}

#elif defined test_invalid_barrier_option
ចំនួនគត់ main(void)
{
    /* Invalid barrier scope name */
    __asm__("dmb xyz");
    ត្រឡប់ 0;
}

#elif defined test_missing_third_operand
ចំនួនគត់ main(void)
{
    __asm__("add x0, x1");
    ត្រឡប់ 0;
}

#elif defined test_movz_imm_range
ចំនួនគត់ main(void)
{
    __asm__("movz x0, #0x10000");
    ត្រឡប់ 0;
}

#elif defined test_movz_shift_range
ចំនួនគត់ main(void)
{
    __asm__("movz x0, #1, lsl #8");
    ត្រឡប់ 0;
}

#elif defined test_invalid_muls
ចំនួនគត់ main(void)
{
    __asm__("muls x0, x1, x2");
    ត្រឡប់ 0;
}

#elif defined test_extended_inline_asm
ចំនួនគត់ main(void)
{
    ចំនួនគត់ x = 1;
    /* Invalid operand reference in extended inline asm */
    __asm__("add %0, %1, #1" : "=r"(x) : "2"(x));
    ត្រឡប់ 0;
}

#elif defined test_extended_inline_clobber
ចំនួនគត់ main(void)
{
    /* Invalid clobber register name */
    __asm__ ca_ncala ("nop" : : : "bogus");
    ត្រឡប់ 0;
}

#endif
