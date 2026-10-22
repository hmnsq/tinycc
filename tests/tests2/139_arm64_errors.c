/* ARM64 inline assembly error tests.
   Verify that invalid assembly produces proper error messages.
   Run with -dt; skipped on non-arm64 architectures. */

#अन्तर्भाव <stdio.h>

#यदि defined test_unknown_instruction
पूर्णाङ्क main(शून्य)
{
    __asm__("fubar x0, x1, x2");
    प्रत्यागम 0;
}

#नोचेद्यदि defined test_shift_imm_range_32
पूर्णाङ्क main(शून्य)
{
    /* LSL by 32 is out of range for 32-bit operand */
    __asm__("lsl w0, w1, #32");
    प्रत्यागम 0;
}

#नोचेद्यदि defined test_shift_imm_range_64
पूर्णाङ्क main(शून्य)
{
    /* LSL by 64 is out of range for 64-bit operand */
    __asm__("lsl x0, x1, #64");
    प्रत्यागम 0;
}

#नोचेद्यदि defined test_invalid_sysreg
पूर्णाङ्क main(शून्य)
{
    /* Bogus system register name */
    __asm__("mrs x0, bogusreg");
    प्रत्यागम 0;
}

#नोचेद्यदि defined test_invalid_barrier_option
पूर्णाङ्क main(शून्य)
{
    /* Invalid barrier scope name */
    __asm__("dmb xyz");
    प्रत्यागम 0;
}

#नोचेद्यदि defined test_missing_third_operand
पूर्णाङ्क main(शून्य)
{
    __asm__("add x0, x1");
    प्रत्यागम 0;
}

#नोचेद्यदि defined test_movz_imm_range
पूर्णाङ्क main(शून्य)
{
    __asm__("movz x0, #0x10000");
    प्रत्यागम 0;
}

#नोचेद्यदि defined test_movz_shift_range
पूर्णाङ्क main(शून्य)
{
    __asm__("movz x0, #1, lsl #8");
    प्रत्यागम 0;
}

#नोचेद्यदि defined test_invalid_muls
पूर्णाङ्क main(शून्य)
{
    __asm__("muls x0, x1, x2");
    प्रत्यागम 0;
}

#नोचेद्यदि defined test_extended_inline_asm
पूर्णाङ्क main(शून्य)
{
    पूर्णाङ्क x = 1;
    /* Invalid operand reference in extended inline asm */
    __asm__("add %0, %1, #1" : "=r"(x) : "2"(x));
    प्रत्यागम 0;
}

#नोचेद्यदि defined test_extended_inline_clobber
पूर्णाङ्क main(शून्य)
{
    /* Invalid clobber register name */
    __asm__ चञ्चल ("nop" : : : "bogus");
    प्रत्यागम 0;
}

#endif
