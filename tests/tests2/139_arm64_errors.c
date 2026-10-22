/* ARM64 inline assembly error tests.
   Verify that invalid assembly produces proper error messages.
   Run with -dt; skipped on non-arm64 architectures. */

#অন্তর্ভাব <stdio.h>

#যদি defined test_unknown_instruction
পূর্ণসংখ্যা প্রধান(শূন্য)
{
    __asm__("fubar x0, x1, x2");
    ফেরত 0;
}

#নতুবা_যদি defined test_shift_imm_range_32
পূর্ণসংখ্যা প্রধান(শূন্য)
{
    /* LSL by 32 is out of range for 32-bit operand */
    __asm__("lsl w0, w1, #32");
    ফেরত 0;
}

#নতুবা_যদি defined test_shift_imm_range_64
পূর্ণসংখ্যা প্রধান(শূন্য)
{
    /* LSL by 64 is out of range for 64-bit operand */
    __asm__("lsl x0, x1, #64");
    ফেরত 0;
}

#নতুবা_যদি defined test_invalid_sysreg
পূর্ণসংখ্যা প্রধান(শূন্য)
{
    /* Bogus system register name */
    __asm__("mrs x0, bogusreg");
    ফেরত 0;
}

#নতুবা_যদি defined test_invalid_barrier_option
পূর্ণসংখ্যা প্রধান(শূন্য)
{
    /* Invalid barrier scope name */
    __asm__("dmb xyz");
    ফেরত 0;
}

#নতুবা_যদি defined test_missing_third_operand
পূর্ণসংখ্যা প্রধান(শূন্য)
{
    __asm__("add x0, x1");
    ফেরত 0;
}

#নতুবা_যদি defined test_movz_imm_range
পূর্ণসংখ্যা প্রধান(শূন্য)
{
    __asm__("movz x0, #0x10000");
    ফেরত 0;
}

#নতুবা_যদি defined test_movz_shift_range
পূর্ণসংখ্যা প্রধান(শূন্য)
{
    __asm__("movz x0, #1, lsl #8");
    ফেরত 0;
}

#নতুবা_যদি defined test_invalid_muls
পূর্ণসংখ্যা প্রধান(শূন্য)
{
    __asm__("muls x0, x1, x2");
    ফেরত 0;
}

#নতুবা_যদি defined test_extended_inline_asm
পূর্ণসংখ্যা প্রধান(শূন্য)
{
    পূর্ণসংখ্যা x = 1;
    /* Invalid operand reference in extended inline asm */
    __asm__("add %0, %1, #1" : "=r"(x) : "2"(x));
    ফেরত 0;
}

#নতুবা_যদি defined test_extended_inline_clobber
পূর্ণসংখ্যা প্রধান(শূন্য)
{
    /* Invalid clobber register name */
    __asm__ অস্থির ("nop" : : : "bogus");
    ফেরত 0;
}

#endif
