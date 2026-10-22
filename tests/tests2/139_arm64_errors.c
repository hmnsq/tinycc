/* ARM64 inline assembly error tests.
   Verify that invalid assembly produces proper error messages.
   Run with -dt; skipped on non-arm64 architectures. */

#include <stdio.h>

#ако defined test_unknown_instruction
цео main(void)
{
    __asm__("fubar x0, x1, x2");
    врати 0;
}

#elif defined test_shift_imm_range_32
цео main(void)
{
    /* LSL by 32 is out of range for 32-bit operand */
    __asm__("lsl w0, w1, #32");
    врати 0;
}

#elif defined test_shift_imm_range_64
цео main(void)
{
    /* LSL by 64 is out of range for 64-bit operand */
    __asm__("lsl x0, x1, #64");
    врати 0;
}

#elif defined test_invalid_sysreg
цео main(void)
{
    /* Bogus system register name */
    __asm__("mrs x0, bogusreg");
    врати 0;
}

#elif defined test_invalid_barrier_option
цео main(void)
{
    /* Invalid barrier scope name */
    __asm__("dmb xyz");
    врати 0;
}

#elif defined test_missing_third_operand
цео main(void)
{
    __asm__("add x0, x1");
    врати 0;
}

#elif defined test_movz_imm_range
цео main(void)
{
    __asm__("movz x0, #0x10000");
    врати 0;
}

#elif defined test_movz_shift_range
цео main(void)
{
    __asm__("movz x0, #1, lsl #8");
    врати 0;
}

#elif defined test_invalid_muls
цео main(void)
{
    __asm__("muls x0, x1, x2");
    врати 0;
}

#elif defined test_extended_inline_asm
цео main(void)
{
    цео x = 1;
    /* Invalid operand reference in extended inline asm */
    __asm__("add %0, %1, #1" : "=r"(x) : "2"(x));
    врати 0;
}

#elif defined test_extended_inline_clobber
цео main(void)
{
    /* Invalid clobber register name */
    __asm__ volatile ("nop" : : : "bogus");
    врати 0;
}

#endif
