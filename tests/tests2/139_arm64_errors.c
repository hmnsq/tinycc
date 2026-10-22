/* ARM64 inline assembly error tests.
   Verify that invalid assembly produces proper error messages.
   Run with -dt; skipped on non-arm64 architectures. */

#include <stdio.h>

#གལ་སྲིད defined test_unknown_instruction
ཧྲིལ main(void)
{
    __asm__("fubar x0, x1, x2");
    ལོག 0;
}

#elif defined test_shift_imm_range_32
ཧྲིལ main(void)
{
    /* LSL by 32 is out of range for 32-bit operand */
    __asm__("lsl w0, w1, #32");
    ལོག 0;
}

#elif defined test_shift_imm_range_64
ཧྲིལ main(void)
{
    /* LSL by 64 is out of range for 64-bit operand */
    __asm__("lsl x0, x1, #64");
    ལོག 0;
}

#elif defined test_invalid_sysreg
ཧྲིལ main(void)
{
    /* Bogus system register name */
    __asm__("mrs x0, bogusreg");
    ལོག 0;
}

#elif defined test_invalid_barrier_option
ཧྲིལ main(void)
{
    /* Invalid barrier scope name */
    __asm__("dmb xyz");
    ལོག 0;
}

#elif defined test_missing_third_operand
ཧྲིལ main(void)
{
    __asm__("add x0, x1");
    ལོག 0;
}

#elif defined test_movz_imm_range
ཧྲིལ main(void)
{
    __asm__("movz x0, #0x10000");
    ལོག 0;
}

#elif defined test_movz_shift_range
ཧྲིལ main(void)
{
    __asm__("movz x0, #1, lsl #8");
    ལོག 0;
}

#elif defined test_invalid_muls
ཧྲིལ main(void)
{
    __asm__("muls x0, x1, x2");
    ལོག 0;
}

#elif defined test_extended_inline_asm
ཧྲིལ main(void)
{
    ཧྲིལ x = 1;
    /* Invalid operand reference in extended inline asm */
    __asm__("add %0, %1, #1" : "=r"(x) : "2"(x));
    ལོག 0;
}

#elif defined test_extended_inline_clobber
ཧྲིལ main(void)
{
    /* Invalid clobber register name */
    __asm__ ca_ncala ("nop" : : : "bogus");
    ལོག 0;
}

#endif
