/* ARM64 inline assembly error tests.
   Verify that invalid assembly produces proper error messages.
   Run with -dt; skipped on non-arm64 architectures. */

#include <stdio.h>

#만약 defined test_unknown_instruction
정수 main(void)
{
    __asm__("fubar x0, x1, x2");
    반환 0;
}

#elif defined test_shift_imm_range_32
정수 main(void)
{
    /* LSL by 32 is out of range for 32-bit operand */
    __asm__("lsl w0, w1, #32");
    반환 0;
}

#elif defined test_shift_imm_range_64
정수 main(void)
{
    /* LSL by 64 is out of range for 64-bit operand */
    __asm__("lsl x0, x1, #64");
    반환 0;
}

#elif defined test_invalid_sysreg
정수 main(void)
{
    /* Bogus system register name */
    __asm__("mrs x0, bogusreg");
    반환 0;
}

#elif defined test_invalid_barrier_option
정수 main(void)
{
    /* Invalid barrier scope name */
    __asm__("dmb xyz");
    반환 0;
}

#elif defined test_missing_third_operand
정수 main(void)
{
    __asm__("add x0, x1");
    반환 0;
}

#elif defined test_movz_imm_range
정수 main(void)
{
    __asm__("movz x0, #0x10000");
    반환 0;
}

#elif defined test_movz_shift_range
정수 main(void)
{
    __asm__("movz x0, #1, lsl #8");
    반환 0;
}

#elif defined test_invalid_muls
정수 main(void)
{
    __asm__("muls x0, x1, x2");
    반환 0;
}

#elif defined test_extended_inline_asm
정수 main(void)
{
    정수 x = 1;
    /* Invalid operand reference in extended inline asm */
    __asm__("add %0, %1, #1" : "=r"(x) : "2"(x));
    반환 0;
}

#elif defined test_extended_inline_clobber
정수 main(void)
{
    /* Invalid clobber register name */
    __asm__ volatile ("nop" : : : "bogus");
    반환 0;
}

#endif
