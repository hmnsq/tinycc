/* ARM64 inline assembly error tests.
   Verify that invalid assembly produces proper error messages.
   Run with -dt; skipped on non-arm64 architectures. */

#અન્તર્ભાવ <stdio.h>

#જો defined test_unknown_instruction
પૂર્ણાંક મુખ્ય(શૂન્ય)
{
    __asm__("fubar x0, x1, x2");
    પાછા 0;
}

#અથવાજો defined test_shift_imm_range_32
પૂર્ણાંક મુખ્ય(શૂન્ય)
{
    /* LSL by 32 is out of range for 32-bit operand */
    __asm__("lsl w0, w1, #32");
    પાછા 0;
}

#અથવાજો defined test_shift_imm_range_64
પૂર્ણાંક મુખ્ય(શૂન્ય)
{
    /* LSL by 64 is out of range for 64-bit operand */
    __asm__("lsl x0, x1, #64");
    પાછા 0;
}

#અથવાજો defined test_invalid_sysreg
પૂર્ણાંક મુખ્ય(શૂન્ય)
{
    /* Bogus system register name */
    __asm__("mrs x0, bogusreg");
    પાછા 0;
}

#અથવાજો defined test_invalid_barrier_option
પૂર્ણાંક મુખ્ય(શૂન્ય)
{
    /* Invalid barrier scope name */
    __asm__("dmb xyz");
    પાછા 0;
}

#અથવાજો defined test_missing_third_operand
પૂર્ણાંક મુખ્ય(શૂન્ય)
{
    __asm__("add x0, x1");
    પાછા 0;
}

#અથવાજો defined test_movz_imm_range
પૂર્ણાંક મુખ્ય(શૂન્ય)
{
    __asm__("movz x0, #0x10000");
    પાછા 0;
}

#અથવાજો defined test_movz_shift_range
પૂર્ણાંક મુખ્ય(શૂન્ય)
{
    __asm__("movz x0, #1, lsl #8");
    પાછા 0;
}

#અથવાજો defined test_invalid_muls
પૂર્ણાંક મુખ્ય(શૂન્ય)
{
    __asm__("muls x0, x1, x2");
    પાછા 0;
}

#અથવાજો defined test_extended_inline_asm
પૂર્ણાંક મુખ્ય(શૂન્ય)
{
    પૂર્ણાંક x = 1;
    /* Invalid operand reference in extended inline asm */
    __asm__("add %0, %1, #1" : "=r"(x) : "2"(x));
    પાછા 0;
}

#અથવાજો defined test_extended_inline_clobber
પૂર્ણાંક મુખ્ય(શૂન્ય)
{
    /* Invalid clobber register name */
    __asm__ અસ્થિર ("nop" : : : "bogus");
    પાછા 0;
}

#endif
