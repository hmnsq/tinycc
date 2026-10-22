/* ARM64 inline assembly error tests.
   Verify that invalid assembly produces proper error messages.
   Run with -dt; skipped on non-arm64 architectures. */

#అన్తర్భావ <stdio.h>

#ఒకవేళ defined test_unknown_instruction
పూర్ణాంకం ప్రధాన(శూన్య)
{
    __asm__("fubar x0, x1, x2");
    తిరిగి 0;
}

#లేదావేళ defined test_జరుపు_imm_range_32
పూర్ణాంకం ప్రధాన(శూన్య)
{
    /* LSL by 32 is out of range for 32-bit operand */
    __asm__("lsl w0, w1, #32");
    తిరిగి 0;
}

#లేదావేళ defined test_జరుపు_imm_range_64
పూర్ణాంకం ప్రధాన(శూన్య)
{
    /* LSL by 64 is out of range for 64-bit operand */
    __asm__("lsl x0, x1, #64");
    తిరిగి 0;
}

#లేదావేళ defined test_invalid_sysreg
పూర్ణాంకం ప్రధాన(శూన్య)
{
    /* Bogus system register name */
    __asm__("mrs x0, bogusreg");
    తిరిగి 0;
}

#లేదావేళ defined test_invalid_barrier_option
పూర్ణాంకం ప్రధాన(శూన్య)
{
    /* Invalid barrier scope name */
    __asm__("dmb xyz");
    తిరిగి 0;
}

#లేదావేళ defined test_missing_మూడవ_నిర్వాహ్యం
పూర్ణాంకం ప్రధాన(శూన్య)
{
    __asm__("add x0, x1");
    తిరిగి 0;
}

#లేదావేళ defined test_movz_imm_range
పూర్ణాంకం ప్రధాన(శూన్య)
{
    __asm__("movz x0, #0x10000");
    తిరిగి 0;
}

#లేదావేళ defined test_movz_జరుపు_range
పూర్ణాంకం ప్రధాన(శూన్య)
{
    __asm__("movz x0, #1, lsl #8");
    తిరిగి 0;
}

#లేదావేళ defined test_invalid_muls
పూర్ణాంకం ప్రధాన(శూన్య)
{
    __asm__("muls x0, x1, x2");
    తిరిగి 0;
}

#లేదావేళ defined test_extended_inline_asm
పూర్ణాంకం ప్రధాన(శూన్య)
{
    పూర్ణాంకం x = 1;
    /* Invalid operand reference in extended inline asm */
    __asm__("add %0, %1, #1" : "=r"(x) : "2"(x));
    తిరిగి 0;
}

#లేదావేళ defined test_extended_inline_clobber
పూర్ణాంకం ప్రధాన(శూన్య)
{
    /* Invalid clobber register name */
    __asm__ అస్థిర ("nop" : : : "bogus");
    తిరిగి 0;
}

#అయితే_ముగింపు
