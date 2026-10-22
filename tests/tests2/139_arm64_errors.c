/* ARM64 inline assembly error tests.
   Verify that invalid assembly produces proper error messages.
   Run with -dt; skipped on non-arm64 architectures. */

#include <stdio.h>

#якщо defined test_unknown_instruction
ціле main(void)
{
    __asm__("fubar x0, x1, x2");
    повернути 0;
}

#elif defined test_shift_imm_range_32
ціле main(void)
{
    /* LSL by 32 is out of range for 32-bit operand */
    __asm__("lsl w0, w1, #32");
    повернути 0;
}

#elif defined test_shift_imm_range_64
ціле main(void)
{
    /* LSL by 64 is out of range for 64-bit operand */
    __asm__("lsl x0, x1, #64");
    повернути 0;
}

#elif defined test_invalid_sysreg
ціле main(void)
{
    /* Bogus system register name */
    __asm__("mrs x0, bogusreg");
    повернути 0;
}

#elif defined test_invalid_barrier_option
ціле main(void)
{
    /* Invalid barrier scope name */
    __asm__("dmb xyz");
    повернути 0;
}

#elif defined test_missing_third_operand
ціле main(void)
{
    __asm__("add x0, x1");
    повернути 0;
}

#elif defined test_movz_imm_range
ціле main(void)
{
    __asm__("movz x0, #0x10000");
    повернути 0;
}

#elif defined test_movz_shift_range
ціле main(void)
{
    __asm__("movz x0, #1, lsl #8");
    повернути 0;
}

#elif defined test_invalid_muls
ціле main(void)
{
    __asm__("muls x0, x1, x2");
    повернути 0;
}

#elif defined test_extended_inline_asm
ціле main(void)
{
    ціле x = 1;
    /* Invalid operand reference in extended inline asm */
    __asm__("add %0, %1, #1" : "=r"(x) : "2"(x));
    повернути 0;
}

#elif defined test_extended_inline_clobber
ціле main(void)
{
    /* Invalid clobber register name */
    __asm__ volatile ("nop" : : : "bogus");
    повернути 0;
}

#endif
