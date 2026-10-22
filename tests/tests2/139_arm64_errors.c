/* ARM64 inline assembly error tests.
   Verify that invalid assembly produces proper error messages.
   Run with -dt; skipped on non-arm64 architectures. */

#அந்தர்பாவ <stdio.h>

#எனில் defined test_unknown_instruction
முழு முதன்மை(வெறுமை)
{
    __asm__("fubar x0, x1, x2");
    திரும்பு 0;
}

#அல்லதெனில் defined test_shift_imm_range_32
முழு முதன்மை(வெறுமை)
{
    /* LSL by 32 is out of range for 32-bit operand */
    __asm__("lsl w0, w1, #32");
    திரும்பு 0;
}

#அல்லதெனில் defined test_shift_imm_range_64
முழு முதன்மை(வெறுமை)
{
    /* LSL by 64 is out of range for 64-bit operand */
    __asm__("lsl x0, x1, #64");
    திரும்பு 0;
}

#அல்லதெனில் defined test_invalid_sysreg
முழு முதன்மை(வெறுமை)
{
    /* Bogus system register name */
    __asm__("mrs x0, bogusreg");
    திரும்பு 0;
}

#அல்லதெனில் defined test_invalid_barrier_option
முழு முதன்மை(வெறுமை)
{
    /* Invalid barrier scope name */
    __asm__("dmb xyz");
    திரும்பு 0;
}

#அல்லதெனில் defined test_missing_third_operand
முழு முதன்மை(வெறுமை)
{
    __asm__("add x0, x1");
    திரும்பு 0;
}

#அல்லதெனில் defined test_movz_imm_range
முழு முதன்மை(வெறுமை)
{
    __asm__("movz x0, #0x10000");
    திரும்பு 0;
}

#அல்லதெனில் defined test_movz_shift_range
முழு முதன்மை(வெறுமை)
{
    __asm__("movz x0, #1, lsl #8");
    திரும்பு 0;
}

#அல்லதெனில் defined test_invalid_muls
முழு முதன்மை(வெறுமை)
{
    __asm__("muls x0, x1, x2");
    திரும்பு 0;
}

#அல்லதெனில் defined test_extended_inline_asm
முழு முதன்மை(வெறுமை)
{
    முழு x = 1;
    /* Invalid operand reference in extended inline asm */
    __asm__("add %0, %1, #1" : "=r"(x) : "2"(x));
    திரும்பு 0;
}

#அல்லதெனில் defined test_extended_inline_clobber
முழு முதன்மை(வெறுமை)
{
    /* Invalid clobber register name */
    __asm__ நிலையற்ற ("nop" : : : "bogus");
    திரும்பு 0;
}

#endif
