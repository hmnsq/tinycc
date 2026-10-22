/* ARM64 inline assembly error tests.
   Verify that invalid assembly produces proper error messages.
   Run with -dt; skipped on non-arm64 architectures. */

#অন্তর্ভাব <stdio.h>

#যদি defined test_unknown_instruction
পূর্ণাঙ্ক main(শূন্য)
{
    __asm__("fubar x0, x1, x2");
    প্রত্যাগম 0;
}

#নোচেদ্যদি defined test_shift_imm_range_32
পূর্ণাঙ্ক main(শূন্য)
{
    /* LSL by 32 is out of range for 32-bit operand */
    __asm__("lsl w0, w1, #32");
    প্রত্যাগম 0;
}

#নোচেদ্যদি defined test_shift_imm_range_64
পূর্ণাঙ্ক main(শূন্য)
{
    /* LSL by 64 is out of range for 64-bit operand */
    __asm__("lsl x0, x1, #64");
    প্রত্যাগম 0;
}

#নোচেদ্যদি defined test_invalid_sysreg
পূর্ণাঙ্ক main(শূন্য)
{
    /* Bogus system register name */
    __asm__("mrs x0, bogusreg");
    প্রত্যাগম 0;
}

#নোচেদ্যদি defined test_invalid_barrier_option
পূর্ণাঙ্ক main(শূন্য)
{
    /* Invalid barrier scope name */
    __asm__("dmb xyz");
    প্রত্যাগম 0;
}

#নোচেদ্যদি defined test_missing_third_operand
পূর্ণাঙ্ক main(শূন্য)
{
    __asm__("add x0, x1");
    প্রত্যাগম 0;
}

#নোচেদ্যদি defined test_movz_imm_range
পূর্ণাঙ্ক main(শূন্য)
{
    __asm__("movz x0, #0x10000");
    প্রত্যাগম 0;
}

#নোচেদ্যদি defined test_movz_shift_range
পূর্ণাঙ্ক main(শূন্য)
{
    __asm__("movz x0, #1, lsl #8");
    প্রত্যাগম 0;
}

#নোচেদ্যদি defined test_invalid_muls
পূর্ণাঙ্ক main(শূন্য)
{
    __asm__("muls x0, x1, x2");
    প্রত্যাগম 0;
}

#নোচেদ্যদি defined test_extended_inline_asm
পূর্ণাঙ্ক main(শূন্য)
{
    পূর্ণাঙ্ক x = 1;
    /* Invalid operand reference in extended inline asm */
    __asm__("add %0, %1, #1" : "=r"(x) : "2"(x));
    প্রত্যাগম 0;
}

#নোচেদ্যদি defined test_extended_inline_clobber
পূর্ণাঙ্ক main(শূন্য)
{
    /* Invalid clobber register name */
    __asm__ চঞ্চল ("nop" : : : "bogus");
    প্রত্যাগম 0;
}

#endif
