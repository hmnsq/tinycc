/* ARM64 inline assembly error tests.
   Verify that invalid assembly produces proper error messages.
   Run with -dt; skipped on non-arm64 architectures. */

#include <stdio.h>

#ако defined test_unknown_instruction
цяло main(void)
{
    __asm__("fubar x0, x1, x2");
    върни 0;
}

#elif defined test_shift_imm_range_32
цяло main(void)
{
    /* LSL by 32 is out of range for 32-bit operand */
    __asm__("lsl w0, w1, #32");
    върни 0;
}

#elif defined test_shift_imm_range_64
цяло main(void)
{
    /* LSL by 64 is out of range for 64-bit operand */
    __asm__("lsl x0, x1, #64");
    върни 0;
}

#elif defined test_invalid_sysreg
цяло main(void)
{
    /* Bogus system register name */
    __asm__("mrs x0, bogusreg");
    върни 0;
}

#elif defined test_invalid_barrier_option
цяло main(void)
{
    /* Invalid barrier scope name */
    __asm__("dmb xyz");
    върни 0;
}

#elif defined test_missing_third_operand
цяло main(void)
{
    __asm__("add x0, x1");
    върни 0;
}

#elif defined test_movz_imm_range
цяло main(void)
{
    __asm__("movz x0, #0x10000");
    върни 0;
}

#elif defined test_movz_shift_range
цяло main(void)
{
    __asm__("movz x0, #1, lsl #8");
    върни 0;
}

#elif defined test_invalid_muls
цяло main(void)
{
    __asm__("muls x0, x1, x2");
    върни 0;
}

#elif defined test_extended_inline_asm
цяло main(void)
{
    цяло x = 1;
    /* Invalid operand reference in extended inline asm */
    __asm__("add %0, %1, #1" : "=r"(x) : "2"(x));
    върни 0;
}

#elif defined test_extended_inline_clobber
цяло main(void)
{
    /* Invalid clobber register name */
    __asm__ volatile ("nop" : : : "bogus");
    върни 0;
}

#endif
