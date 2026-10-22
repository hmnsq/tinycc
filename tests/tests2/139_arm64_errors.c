/* ARM64 inline assembly error tests.
   Verify that invalid assembly produces proper error messages.
   Run with -dt; skipped on non-arm64 architectures. */

#അന്തര്ഭാവ <stdio.h>

#എങ്കിൽ defined test_unknown_instruction
പൂർണ്ണസംഖ്യ പ്രധാന(ശൂന്യം)
{
    __asm__("fubar x0, x1, x2");
    തിരികെ 0;
}

#അല്ലെങ്കിലെങ്കിൽ defined test_shift_imm_range_32
പൂർണ്ണസംഖ്യ പ്രധാന(ശൂന്യം)
{
    /* LSL by 32 is out of range for 32-bit operand */
    __asm__("lsl w0, w1, #32");
    തിരികെ 0;
}

#അല്ലെങ്കിലെങ്കിൽ defined test_shift_imm_range_64
പൂർണ്ണസംഖ്യ പ്രധാന(ശൂന്യം)
{
    /* LSL by 64 is out of range for 64-bit operand */
    __asm__("lsl x0, x1, #64");
    തിരികെ 0;
}

#അല്ലെങ്കിലെങ്കിൽ defined test_invalid_sysreg
പൂർണ്ണസംഖ്യ പ്രധാന(ശൂന്യം)
{
    /* Bogus system register name */
    __asm__("mrs x0, bogusreg");
    തിരികെ 0;
}

#അല്ലെങ്കിലെങ്കിൽ defined test_invalid_barrier_option
പൂർണ്ണസംഖ്യ പ്രധാന(ശൂന്യം)
{
    /* Invalid barrier scope name */
    __asm__("dmb xyz");
    തിരികെ 0;
}

#അല്ലെങ്കിലെങ്കിൽ defined test_missing_third_operand
പൂർണ്ണസംഖ്യ പ്രധാന(ശൂന്യം)
{
    __asm__("add x0, x1");
    തിരികെ 0;
}

#അല്ലെങ്കിലെങ്കിൽ defined test_movz_imm_range
പൂർണ്ണസംഖ്യ പ്രധാന(ശൂന്യം)
{
    __asm__("movz x0, #0x10000");
    തിരികെ 0;
}

#അല്ലെങ്കിലെങ്കിൽ defined test_movz_shift_range
പൂർണ്ണസംഖ്യ പ്രധാന(ശൂന്യം)
{
    __asm__("movz x0, #1, lsl #8");
    തിരികെ 0;
}

#അല്ലെങ്കിലെങ്കിൽ defined test_invalid_muls
പൂർണ്ണസംഖ്യ പ്രധാന(ശൂന്യം)
{
    __asm__("muls x0, x1, x2");
    തിരികെ 0;
}

#അല്ലെങ്കിലെങ്കിൽ defined test_extended_inline_asm
പൂർണ്ണസംഖ്യ പ്രധാന(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ x = 1;
    /* Invalid operand reference in extended inline asm */
    __asm__("add %0, %1, #1" : "=r"(x) : "2"(x));
    തിരികെ 0;
}

#അല്ലെങ്കിലെങ്കിൽ defined test_extended_inline_clobber
പൂർണ്ണസംഖ്യ പ്രധാന(ശൂന്യം)
{
    /* Invalid clobber register name */
    __asm__ അസ്ഥിര ("nop" : : : "bogus");
    തിരികെ 0;
}

#endif
