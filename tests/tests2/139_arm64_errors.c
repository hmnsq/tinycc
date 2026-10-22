/* ARM64 inline assembly error tests.
   Verify that invalid assembly produces proper error messages.
   Run with -dt; skipped on non-arm64 architectures. */

#include <stdio.h>

#если defined test_unknown_instruction
целое основной(void)
{
    __asm__("fubar x0, x1, x2");
    вернуть 0;
}

#elif defined test_shift_imm_range_32
целое основной(void)
{
    /* LSL by 32 is out of range for 32-bit operand */
    __asm__("lsl w0, w1, #32");
    вернуть 0;
}

#elif defined test_shift_imm_range_64
целое основной(void)
{
    /* LSL by 64 is out of range for 64-bit operand */
    __asm__("lsl x0, x1, #64");
    вернуть 0;
}

#elif defined test_invalid_sysreg
целое основной(void)
{
    /* Bogus system register name */
    __asm__("mrs x0, bogusreg");
    вернуть 0;
}

#elif defined test_invalid_barrier_option
целое основной(void)
{
    /* Invalid barrier scope name */
    __asm__("dmb xyz");
    вернуть 0;
}

#elif defined test_missing_third_operand
целое основной(void)
{
    __asm__("add x0, x1");
    вернуть 0;
}

#elif defined test_movz_imm_range
целое основной(void)
{
    __asm__("movz x0, #0x10000");
    вернуть 0;
}

#elif defined test_movz_shift_range
целое основной(void)
{
    __asm__("movz x0, #1, lsl #8");
    вернуть 0;
}

#elif defined test_invalid_muls
целое основной(void)
{
    __asm__("muls x0, x1, x2");
    вернуть 0;
}

#elif defined test_extended_inline_asm
целое основной(void)
{
    целое x = 1;
    /* Invalid operand reference in extended inline asm */
    __asm__("add %0, %1, #1" : "=r"(x) : "2"(x));
    вернуть 0;
}

#elif defined test_extended_inline_clobber
целое основной(void)
{
    /* Invalid clobber register name */
    __asm__ volatile ("nop" : : : "bogus");
    вернуть 0;
}

#endif
