/* ARM64 inline assembly error tests.
   Verify that invalid assembly produces proper error messages.
   Run with -dt; skipped on non-arm64 architectures. */

#include <stdio.h>

#ถ้า defined test_unknown_instruction
จำนวนเต็ม หลัก(void)
{
    __asm__("fubar x0, x1, x2");
    คืน 0;
}

#elif defined test_shift_imm_range_32
จำนวนเต็ม หลัก(void)
{
    /* LSL by 32 is out of range for 32-bit operand */
    __asm__("lsl w0, w1, #32");
    คืน 0;
}

#elif defined test_shift_imm_range_64
จำนวนเต็ม หลัก(void)
{
    /* LSL by 64 is out of range for 64-bit operand */
    __asm__("lsl x0, x1, #64");
    คืน 0;
}

#elif defined test_invalid_sysreg
จำนวนเต็ม หลัก(void)
{
    /* Bogus system register name */
    __asm__("mrs x0, bogusreg");
    คืน 0;
}

#elif defined test_invalid_barrier_option
จำนวนเต็ม หลัก(void)
{
    /* Invalid barrier scope name */
    __asm__("dmb xyz");
    คืน 0;
}

#elif defined test_missing_third_operand
จำนวนเต็ม หลัก(void)
{
    __asm__("add x0, x1");
    คืน 0;
}

#elif defined test_movz_imm_range
จำนวนเต็ม หลัก(void)
{
    __asm__("movz x0, #0x10000");
    คืน 0;
}

#elif defined test_movz_shift_range
จำนวนเต็ม หลัก(void)
{
    __asm__("movz x0, #1, lsl #8");
    คืน 0;
}

#elif defined test_invalid_muls
จำนวนเต็ม หลัก(void)
{
    __asm__("muls x0, x1, x2");
    คืน 0;
}

#elif defined test_extended_inline_asm
จำนวนเต็ม หลัก(void)
{
    จำนวนเต็ม x = 1;
    /* Invalid operand reference in extended inline asm */
    __asm__("add %0, %1, #1" : "=r"(x) : "2"(x));
    คืน 0;
}

#elif defined test_extended_inline_clobber
จำนวนเต็ม หลัก(void)
{
    /* Invalid clobber register name */
    __asm__ ca_ncala ("nop" : : : "bogus");
    คืน 0;
}

#endif
