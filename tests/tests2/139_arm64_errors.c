/* ARM64 inline assembly error tests.
   Verify that invalid assembly produces proper error messages.
   Run with -dt; skipped on non-arm64 architectures. */

#شامل <stdio.h>

#اگر defined test_unknown_instruction
صحیح اصلی(تهی)
{
    __asm__("fubar x0, x1, x2");
    بازگشت 0;
}

#وگرنهاگر defined test_shift_imm_range_32
صحیح اصلی(تهی)
{
    /* LSL by 32 is out of range for 32-bit operand */
    __asm__("lsl w0, w1, #32");
    بازگشت 0;
}

#وگرنهاگر defined test_shift_imm_range_64
صحیح اصلی(تهی)
{
    /* LSL by 64 is out of range for 64-bit operand */
    __asm__("lsl x0, x1, #64");
    بازگشت 0;
}

#وگرنهاگر defined test_invalid_sysreg
صحیح اصلی(تهی)
{
    /* Bogus system register name */
    __asm__("mrs x0, bogusreg");
    بازگشت 0;
}

#وگرنهاگر defined test_invalid_barrier_option
صحیح اصلی(تهی)
{
    /* Invalid barrier scope name */
    __asm__("dmb xyz");
    بازگشت 0;
}

#وگرنهاگر defined test_missing_third_operand
صحیح اصلی(تهی)
{
    __asm__("add x0, x1");
    بازگشت 0;
}

#وگرنهاگر defined test_movz_imm_range
صحیح اصلی(تهی)
{
    __asm__("movz x0, #0x10000");
    بازگشت 0;
}

#وگرنهاگر defined test_movz_shift_range
صحیح اصلی(تهی)
{
    __asm__("movz x0, #1, lsl #8");
    بازگشت 0;
}

#وگرنهاگر defined test_invalid_muls
صحیح اصلی(تهی)
{
    __asm__("muls x0, x1, x2");
    بازگشت 0;
}

#وگرنهاگر defined test_extended_inline_asm
صحیح اصلی(تهی)
{
    صحیح x = 1;
    /* Invalid operand reference in extended inline asm */
    __asm__("add %0, %1, #1" : "=r"(x) : "2"(x));
    بازگشت 0;
}

#وگرنهاگر defined test_extended_inline_clobber
صحیح اصلی(تهی)
{
    /* Invalid clobber register name */
    __asm__ فرار ("nop" : : : "bogus");
    بازگشت 0;
}

#endif
