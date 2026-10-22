/* ARM64 inline assembly error tests.
   Verify that invalid assembly produces proper error messages.
   Run with -dt; skipped on non-arm64 architectures. */

#include <stdio.h>

#nếu defined test_unknown_instruction
số_nguyên main(void)
{
    __asm__("fubar x0, x1, x2");
    trả_về 0;
}

#elif defined test_shift_imm_range_32
số_nguyên main(void)
{
    /* LSL by 32 is out of range for 32-bit operand */
    __asm__("lsl w0, w1, #32");
    trả_về 0;
}

#elif defined test_shift_imm_range_64
số_nguyên main(void)
{
    /* LSL by 64 is out of range for 64-bit operand */
    __asm__("lsl x0, x1, #64");
    trả_về 0;
}

#elif defined test_invalid_sysreg
số_nguyên main(void)
{
    /* Bogus system register name */
    __asm__("mrs x0, bogusreg");
    trả_về 0;
}

#elif defined test_invalid_barrier_option
số_nguyên main(void)
{
    /* Invalid barrier scope name */
    __asm__("dmb xyz");
    trả_về 0;
}

#elif defined test_missing_third_operand
số_nguyên main(void)
{
    __asm__("add x0, x1");
    trả_về 0;
}

#elif defined test_movz_imm_range
số_nguyên main(void)
{
    __asm__("movz x0, #0x10000");
    trả_về 0;
}

#elif defined test_movz_shift_range
số_nguyên main(void)
{
    __asm__("movz x0, #1, lsl #8");
    trả_về 0;
}

#elif defined test_invalid_muls
số_nguyên main(void)
{
    __asm__("muls x0, x1, x2");
    trả_về 0;
}

#elif defined test_extended_inline_asm
số_nguyên main(void)
{
    số_nguyên x = 1;
    /* Invalid operand reference in extended inline asm */
    __asm__("add %0, %1, #1" : "=r"(x) : "2"(x));
    trả_về 0;
}

#elif defined test_extended_inline_clobber
số_nguyên main(void)
{
    /* Invalid clobber register name */
    __asm__ volatile ("nop" : : : "bogus");
    trả_về 0;
}

#endif
