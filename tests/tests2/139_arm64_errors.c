/* ARM64 inline assembly error tests.
   Verify that invalid assembly produces proper error messages.
   Run with -dt; skipped on non-arm64 architectures. */

#include <stdio.h>

#གལ་ཏེ defined test_unknown_instruction
ཧྲིལ གཙོ(void)
{
    __asm__("fubar x0, x1, x2");
    ཕྱིར 0;
}

#elif defined test_shift_imm_range_32
ཧྲིལ གཙོ(void)
{
    /* LSL by 32 is out of range for 32-bit operand */
    __asm__("lsl w0, w1, #32");
    ཕྱིར 0;
}

#elif defined test_shift_imm_range_64
ཧྲིལ གཙོ(void)
{
    /* LSL by 64 is out of range for 64-bit operand */
    __asm__("lsl x0, x1, #64");
    ཕྱིར 0;
}

#elif defined test_invalid_sysreg
ཧྲིལ གཙོ(void)
{
    /* Bogus system register name */
    __asm__("mrs x0, bogusreg");
    ཕྱིར 0;
}

#elif defined test_invalid_barrier_option
ཧྲིལ གཙོ(void)
{
    /* Invalid barrier scope name */
    __asm__("dmb xyz");
    ཕྱིར 0;
}

#elif defined test_missing_third_operand
ཧྲིལ གཙོ(void)
{
    __asm__("add x0, x1");
    ཕྱིར 0;
}

#elif defined test_movz_imm_range
ཧྲིལ གཙོ(void)
{
    __asm__("movz x0, #0x10000");
    ཕྱིར 0;
}

#elif defined test_movz_shift_range
ཧྲིལ གཙོ(void)
{
    __asm__("movz x0, #1, lsl #8");
    ཕྱིར 0;
}

#elif defined test_invalid_muls
ཧྲིལ གཙོ(void)
{
    __asm__("muls x0, x1, x2");
    ཕྱིར 0;
}

#elif defined test_extended_inline_asm
ཧྲིལ གཙོ(void)
{
    ཧྲིལ x = 1;
    /* Invalid operand reference in extended inline asm */
    __asm__("add %0, %1, #1" : "=r"(x) : "2"(x));
    ཕྱིར 0;
}

#elif defined test_extended_inline_clobber
ཧྲིལ གཙོ(void)
{
    /* Invalid clobber register name */
    __asm__ ca_ncala ("nop" : : : "bogus");
    ཕྱིར 0;
}

#endif
