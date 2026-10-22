/* ARM64 inline assembly error tests.
   Verify that invalid assembly produces proper error messages.
   Run with -dt; skipped on non-arm64 architectures. */

#ଅନ୍ତର୍ଭାଵ <stdio.h>

#ଯଦି defined test_unknown_instruction
ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ(ଶୂନ୍ୟ)
{
    __asm__("fubar x0, x1, x2");
    ଫେରନ୍ତୁ 0;
}

#ନଚେତଯଦି defined test_shift_imm_range_32
ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ(ଶୂନ୍ୟ)
{
    /* LSL by 32 is out of range for 32-bit operand */
    __asm__("lsl w0, w1, #32");
    ଫେରନ୍ତୁ 0;
}

#ନଚେତଯଦି defined test_shift_imm_range_64
ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ(ଶୂନ୍ୟ)
{
    /* LSL by 64 is out of range for 64-bit operand */
    __asm__("lsl x0, x1, #64");
    ଫେରନ୍ତୁ 0;
}

#ନଚେତଯଦି defined test_invalid_sysreg
ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ(ଶୂନ୍ୟ)
{
    /* Bogus system register name */
    __asm__("mrs x0, bogusreg");
    ଫେରନ୍ତୁ 0;
}

#ନଚେତଯଦି defined test_invalid_barrier_option
ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ(ଶୂନ୍ୟ)
{
    /* Invalid barrier scope name */
    __asm__("dmb xyz");
    ଫେରନ୍ତୁ 0;
}

#ନଚେତଯଦି defined test_missing_third_operand
ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ(ଶୂନ୍ୟ)
{
    __asm__("add x0, x1");
    ଫେରନ୍ତୁ 0;
}

#ନଚେତଯଦି defined test_movz_imm_range
ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ(ଶୂନ୍ୟ)
{
    __asm__("movz x0, #0x10000");
    ଫେରନ୍ତୁ 0;
}

#ନଚେତଯଦି defined test_movz_shift_range
ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ(ଶୂନ୍ୟ)
{
    __asm__("movz x0, #1, lsl #8");
    ଫେରନ୍ତୁ 0;
}

#ନଚେତଯଦି defined test_invalid_muls
ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ(ଶୂନ୍ୟ)
{
    __asm__("muls x0, x1, x2");
    ଫେରନ୍ତୁ 0;
}

#ନଚେତଯଦି defined test_extended_inline_asm
ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା x = 1;
    /* Invalid operand reference in extended inline asm */
    __asm__("add %0, %1, #1" : "=r"(x) : "2"(x));
    ଫେରନ୍ତୁ 0;
}

#ନଚେତଯଦି defined test_extended_inline_clobber
ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ(ଶୂନ୍ୟ)
{
    /* Invalid clobber register name */
    __asm__ ଅସ୍ଥିର ("nop" : : : "bogus");
    ଫେରନ୍ତୁ 0;
}

#endif
