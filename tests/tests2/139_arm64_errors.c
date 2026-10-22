/* ARM64 inline assembly error tests.
   Verify that invalid assembly produces proper error messages.
   Run with -dt; skipped on non-arm64 architectures. */

#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>

#ਜੇ defined test_unknown_instruction
ਪੂਰਨ ਮੁੱਖ(ਖਾਲੀ)
{
    __asm__("fubar x0, x1, x2");
    ਵਾਪਸ 0;
}

#ਜਾਂਜੇ defined test_ਖਿਸਕਾਓ_imm_range_32
ਪੂਰਨ ਮੁੱਖ(ਖਾਲੀ)
{
    /* LSL by 32 is out of range for 32-bit operand */
    __asm__("lsl w0, w1, #32");
    ਵਾਪਸ 0;
}

#ਜਾਂਜੇ defined test_ਖਿਸਕਾਓ_imm_range_64
ਪੂਰਨ ਮੁੱਖ(ਖਾਲੀ)
{
    /* LSL by 64 is out of range for 64-bit operand */
    __asm__("lsl x0, x1, #64");
    ਵਾਪਸ 0;
}

#ਜਾਂਜੇ defined test_invalid_sysreg
ਪੂਰਨ ਮੁੱਖ(ਖਾਲੀ)
{
    /* Bogus system register name */
    __asm__("mrs x0, bogusreg");
    ਵਾਪਸ 0;
}

#ਜਾਂਜੇ defined test_invalid_barrier_option
ਪੂਰਨ ਮੁੱਖ(ਖਾਲੀ)
{
    /* Invalid barrier scope name */
    __asm__("dmb xyz");
    ਵਾਪਸ 0;
}

#ਜਾਂਜੇ defined test_missing_ਤੀਜਾ_ਸੰਕਾਰਜ
ਪੂਰਨ ਮੁੱਖ(ਖਾਲੀ)
{
    __asm__("add x0, x1");
    ਵਾਪਸ 0;
}

#ਜਾਂਜੇ defined test_movz_imm_range
ਪੂਰਨ ਮੁੱਖ(ਖਾਲੀ)
{
    __asm__("movz x0, #0x10000");
    ਵਾਪਸ 0;
}

#ਜਾਂਜੇ defined test_movz_ਖਿਸਕਾਓ_range
ਪੂਰਨ ਮੁੱਖ(ਖਾਲੀ)
{
    __asm__("movz x0, #1, lsl #8");
    ਵਾਪਸ 0;
}

#ਜਾਂਜੇ defined test_invalid_muls
ਪੂਰਨ ਮੁੱਖ(ਖਾਲੀ)
{
    __asm__("muls x0, x1, x2");
    ਵਾਪਸ 0;
}

#ਜਾਂਜੇ defined test_extended_inline_asm
ਪੂਰਨ ਮੁੱਖ(ਖਾਲੀ)
{
    ਪੂਰਨ x = 1;
    /* Invalid operand reference in extended inline asm */
    __asm__("add %0, %1, #1" : "=r"(x) : "2"(x));
    ਵਾਪਸ 0;
}

#ਜਾਂਜੇ defined test_extended_inline_clobber
ਪੂਰਨ ਮੁੱਖ(ਖਾਲੀ)
{
    /* Invalid clobber register name */
    __asm__ ਅਸਥਿਰ ("nop" : : : "bogus");
    ਵਾਪਸ 0;
}

#ਜੇ_ਅੰਤ
