/* ARM64 inline assembly error tests.
   Verify that invalid assembly produces proper error messages.
   Run with -dt; skipped on non-arm64 architectures. */

#include <stdio.h>

#ᬬᬾᬦ᭄ defined test_unknown_instruction
puur_naa_nka main(void)
{
    __asm__("fubar x0, x1, x2");
    ᬯᬮᬶ 0;
}

#elif defined test_shift_imm_range_32
puur_naa_nka main(void)
{
    /* LSL by 32 is out of range for 32-bit operand */
    __asm__("lsl w0, w1, #32");
    ᬯᬮᬶ 0;
}

#elif defined test_shift_imm_range_64
puur_naa_nka main(void)
{
    /* LSL by 64 is out of range for 64-bit operand */
    __asm__("lsl x0, x1, #64");
    ᬯᬮᬶ 0;
}

#elif defined test_invalid_sysreg
puur_naa_nka main(void)
{
    /* Bogus system register name */
    __asm__("mrs x0, bogusreg");
    ᬯᬮᬶ 0;
}

#elif defined test_invalid_barrier_option
puur_naa_nka main(void)
{
    /* Invalid barrier scope name */
    __asm__("dmb xyz");
    ᬯᬮᬶ 0;
}

#elif defined test_missing_third_operand
puur_naa_nka main(void)
{
    __asm__("add x0, x1");
    ᬯᬮᬶ 0;
}

#elif defined test_movz_imm_range
puur_naa_nka main(void)
{
    __asm__("movz x0, #0x10000");
    ᬯᬮᬶ 0;
}

#elif defined test_movz_shift_range
puur_naa_nka main(void)
{
    __asm__("movz x0, #1, lsl #8");
    ᬯᬮᬶ 0;
}

#elif defined test_invalid_muls
puur_naa_nka main(void)
{
    __asm__("muls x0, x1, x2");
    ᬯᬮᬶ 0;
}

#elif defined test_extended_inline_asm
puur_naa_nka main(void)
{
    puur_naa_nka x = 1;
    /* Invalid operand reference in extended inline asm */
    __asm__("add %0, %1, #1" : "=r"(x) : "2"(x));
    ᬯᬮᬶ 0;
}

#elif defined test_extended_inline_clobber
puur_naa_nka main(void)
{
    /* Invalid clobber register name */
    __asm__ ca_ncala ("nop" : : : "bogus");
    ᬯᬮᬶ 0;
}

#endif
