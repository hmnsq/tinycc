/* ARM64 inline assembly error tests.
   Verify that invalid assembly produces proper error messages.
   Run with -dt; skipped on non-arm64 architectures. */

#شامل <stdio.h>

#اگر defined test_unknown_instruction
صحیح مین(خالی)
{
    __asm__("fubar x0, x1, x2");
    واپس 0;
}

#وگرنہ_اگر defined test_سرکاؤ_imm_range_32
صحیح مین(خالی)
{
    /* LSL by 32 is out of range for 32-bit operand */
    __asm__("lsl w0, w1, #32");
    واپس 0;
}

#وگرنہ_اگر defined test_سرکاؤ_imm_range_64
صحیح مین(خالی)
{
    /* LSL by 64 is out of range for 64-bit operand */
    __asm__("lsl x0, x1, #64");
    واپس 0;
}

#وگرنہ_اگر defined test_invalid_sysreg
صحیح مین(خالی)
{
    /* Bogus system register name */
    __asm__("mrs x0, bogusreg");
    واپس 0;
}

#وگرنہ_اگر defined test_invalid_barrier_option
صحیح مین(خالی)
{
    /* Invalid barrier scope name */
    __asm__("dmb xyz");
    واپس 0;
}

#وگرنہ_اگر defined test_missing_تیسرا_عملیہ
صحیح مین(خالی)
{
    __asm__("add x0, x1");
    واپس 0;
}

#وگرنہ_اگر defined test_movz_imm_range
صحیح مین(خالی)
{
    __asm__("movz x0, #0x10000");
    واپس 0;
}

#وگرنہ_اگر defined test_movz_سرکاؤ_range
صحیح مین(خالی)
{
    __asm__("movz x0, #1, lsl #8");
    واپس 0;
}

#وگرنہ_اگر defined test_invalid_muls
صحیح مین(خالی)
{
    __asm__("muls x0, x1, x2");
    واپس 0;
}

#وگرنہ_اگر defined test_extended_inline_asm
صحیح مین(خالی)
{
    صحیح x = 1;
    /* Invalid operand reference in extended inline asm */
    __asm__("add %0, %1, #1" : "=r"(x) : "2"(x));
    واپس 0;
}

#وگرنہ_اگر defined test_extended_inline_clobber
صحیح مین(خالی)
{
    /* Invalid clobber register name */
    __asm__ متلون ("nop" : : : "bogus");
    واپس 0;
}

#اگر_ختم
