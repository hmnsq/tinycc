/*
 * ARM64 Extended Inline Assembly Tests
 * Tests for GCC-style extended inline assembly with operands, constraints, and clobbers
 */

#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <stdint.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <assert.h>

ਬਣਤਰ pair64 {
    uint64_t a;
    uint64_t b;
};

ਸਥਿਰ ਪੂਰਨ arm64_ਚਿੰਨ੍ਹ_ਨਿਸ਼ਾਨਾ(ਖਾਲੀ)
{
    ਵਾਪਸ 7;
}

ਸਥਿਰ ਖਾਲੀ test_symbolic_ਪਤਾ_constraint_compile_only(ਖਾਲੀ)
{
    asm ਅਸਥਿਰ("" : : "S"(arm64_ਚਿੰਨ੍ਹ_ਨਿਸ਼ਾਨਾ));
}

/* Test 1: Basic output operand */
ਖਾਲੀ test_basic_output(ਖਾਲੀ)
{
    ਪੂਰਨ x;
    asm("mov %0, #42" : "=r"(x));
    ਪ੍ਰਤਿਜ੍ਞਾ(x == 42);
    ਲਿਖੋ("Test 1 (basic output): PASSED\n");
}

/* Test 2: Input operand */
ਖਾਲੀ test_ਨਿਵੇਸ਼_ਸੰਕਾਰਜ(ਖਾਲੀ)
{
    ਪੂਰਨ x = 10;
    ਪੂਰਨ y;
    asm("add %0, %1, #5" : "=r"(y) : "r"(x));
    ਪ੍ਰਤਿਜ੍ਞਾ(y == 15);
    ਲਿਖੋ("Test 2 (input operand): PASSED\n");
}

/* Test 3: Read-write operand */
ਖਾਲੀ test_read_write_ਸੰਕਾਰਜ(ਖਾਲੀ)
{
    ਪੂਰਨ x = 10;
    asm("add %0, %0, #1" : "+r"(x));
    ਪ੍ਰਤਿਜ੍ਞਾ(x == 11);
    ਲਿਖੋ("Test 3 (read-write operand): PASSED\n");
}

/* Test 4: Memory operand - load */
ਖਾਲੀ test_ਸਮ੍ਰਿਤੀ_ਲੱਦੋ(ਖਾਲੀ)
{
    ਪੂਰਨ x = 42;
    ਪੂਰਨ y;
    asm("ldr %w0, [%1]" : "=r"(y) : "r"(&x));
    ਪ੍ਰਤਿਜ੍ਞਾ(y == 42);
    ਲਿਖੋ("Test 4 (memory load): PASSED\n");
}

/* Test 5: Memory operand - store */
ਖਾਲੀ test_ਸਮ੍ਰਿਤੀ_store(ਖਾਲੀ)
{
    ਪੂਰਨ x;
    ਪੂਰਨ val = 123;
    asm("str %w1, [%0]" : : "r"(&x), "r"(val));
    ਪ੍ਰਤਿਜ੍ਞਾ(x == 123);
    ਲਿਖੋ("Test 5 (memory store): PASSED\n");
}

/* Test 5a: Stack memory operand with frame-relative offset */
ਖਾਲੀ test_ਢੇਰ_ਸਮ੍ਰਿਤੀ_ਸੰਕਾਰਜ(ਖਾਲੀ)
{
    ਲੰਮਾ x = 0;
    ਲੰਮਾ val = 321;

    asm ਅਸਥਿਰ("str %0, %1" : : "r"(val), "m"(x));
    ਪ੍ਰਤਿਜ੍ਞਾ(x == 321);
    ਲਿਖੋ("Test 5a (stack memory operand): PASSED\n");
}

/* Test 5b: Symbol memory operand */
ਸਥਿਰ ਲੰਮਾ arm64_ਚਿੰਨ੍ਹ_mem;

ਖਾਲੀ test_ਚਿੰਨ੍ਹ_ਸਮ੍ਰਿਤੀ_ਸੰਕਾਰਜ(ਖਾਲੀ)
{
    ਲੰਮਾ val = 654;

    arm64_ਚਿੰਨ੍ਹ_mem = 0;
    asm ਅਸਥਿਰ("str %0, %1" : : "r"(val), "m"(arm64_ਚਿੰਨ੍ਹ_mem));
    ਪ੍ਰਤਿਜ੍ਞਾ(arm64_ਚਿੰਨ੍ਹ_mem == 654);
    ਲਿਖੋ("Test 5b (symbol memory operand): PASSED\n");
}

/* Test 6: Clobber list */
ਖਾਲੀ test_clobber_list(ਖਾਲੀ)
{
    ਪੂਰਨ x = 10;
    ਪੂਰਨ y = 20;
    ਪੂਰਨ ਨਤੀਜਾ;
    asm("add %0, %1, %2" 
        : "=r"(ਨਤੀਜਾ)
        : "r"(x), "r"(y)
        : "cc");
    ਪ੍ਰਤਿਜ੍ਞਾ(ਨਤੀਜਾ == 30);
    ਲਿਖੋ("Test 6 (clobber list): PASSED\n");
}

/* Test 7: Multiple outputs */
ਖਾਲੀ test_ਗੁਣਜ_outputs(ਖਾਲੀ)
{
    ਪੂਰਨ a, b;
    asm("mov %0, #1; mov %1, #2" 
        : "=r"(a), "=r"(b));
    ਪ੍ਰਤਿਜ੍ਞਾ(a == 1 && b == 2);
    ਲਿਖੋ("Test 7 (multiple outputs): PASSED\n");
}

/* Test 8: Constraint reference */
ਖਾਲੀ test_constraint_reference(ਖਾਲੀ)
{
    ਪੂਰਨ x = 10;
    ਪੂਰਨ y;
    asm("add %0, %1, #5" : "=r"(y) : "0"(x));
    ਪ੍ਰਤਿਜ੍ਞਾ(y == 15);
    ਲਿਖੋ("Test 8 (constraint reference): PASSED\n");
}

/* Test 9: Early clobber */
ਖਾਲੀ test_early_clobber(ਖਾਲੀ)
{
    ਪੂਰਨ x = 10;
    ਪੂਰਨ y;
    asm("mov %0, #42" : "=&r"(y) : "r"(x));
    ਪ੍ਰਤਿਜ੍ਞਾ(y == 42);
    ਲਿਖੋ("Test 9 (early clobber): PASSED\n");
}

/* Test 10: 32-bit register modifier */
ਖਾਲੀ test_w_ਰਜਿਸਟਰ(ਖਾਲੀ)
{
    uint32_t x = 100;
    uint32_t y;
    asm("add %w0, %w1, #50" : "=r"(y) : "r"(x));
    ਪ੍ਰਤਿਜ੍ਞਾ(y == 150);
    ਲਿਖੋ("Test 10 (w register modifier): PASSED\n");
}

/* Test 11: Immediate constraint 'I' (12-bit immediate) */
ਖਾਲੀ test_ਤੁਰੰਤ_i_constraint(ਖਾਲੀ)
{
    ਪੂਰਨ x = 100;
    ਪੂਰਨ y;
    asm("add %0, %1, #200" : "=r"(y) : "r"(x), "I"(200));
    ਪ੍ਰਤਿਜ੍ਞਾ(y == 300);
    ਲਿਖੋ("Test 11 (immediate I constraint): PASSED\n");
}

/* Test 12: Register constraint */
ਖਾਲੀ test_general_ਸੰਕਾਰਜ_constraint(ਖਾਲੀ)
{
    ਪੂਰਨ x = 50;
    ਪੂਰਨ y;
    asm("add %0, %1, #10" : "=r"(y) : "r"(x));
    ਪ੍ਰਤਿਜ੍ਞਾ(y == 60);
    ਲਿਖੋ("Test 12 (general operand constraint): PASSED\n");
}

/* Test 13: Multiple inputs and outputs */
ਖਾਲੀ test_ਗੁਣਜ_io(ਖਾਲੀ)
{
    ਪੂਰਨ a = 10, b = 20;
    ਪੂਰਨ ਜੋੜ, diff;
    asm("add %0, %1, %2" : "=r"(ਜੋੜ) : "r"(a), "r"(b));
    asm("sub %0, %1, %2" : "=r"(diff) : "r"(a), "r"(b));
    ਪ੍ਰਤਿਜ੍ਞਾ(ਜੋੜ == 30 && diff == -10);
    ਲਿਖੋ("Test 13 (multiple IO): PASSED\n");
}

/* Test 14: Register variable preservation */
ਖਾਲੀ test_regvar_preservation(ਖਾਲੀ)
{
    ਰਜਿਸਟਰ uint64_t keep asm("x19") = 0x123456789abcdef0ULL;
    uint64_t ਬਾਹਰਲਾ;

    asm ਅਸਥਿਰ("mov x19, #7; add %0, x19, #1"
        : "=r"(ਬਾਹਰਲਾ)
        :
        : "x19");
    ਪ੍ਰਤਿਜ੍ਞਾ(keep == 0x123456789abcdef0ULL);
    ਪ੍ਰਤਿਜ੍ਞਾ(ਬਾਹਰਲਾ == 8);
    ਲਿਖੋ("Test 14 (regvar preservation): PASSED\n");
}

/* Test 15: Complex arithmetic */
ਖਾਲੀ test_complex_arithmetic(ਖਾਲੀ)
{
    ਪੂਰਨ a = 100, b = 50, c = 25;
    ਪੂਰਨ ਨਤੀਜਾ;
    asm("add %0, %1, %2; sub %0, %0, %3"
        : "=&r"(ਨਤੀਜਾ)
        : "r"(a), "r"(b), "r"(c));
    ਪ੍ਰਤਿਜ੍ਞਾ(ਨਤੀਜਾ == 125);
    ਲਿਖੋ("Test 15 (complex arithmetic): PASSED\n");
}

/* Test 16: Named operand (GCC extension) */
ਖਾਲੀ test_named_ਸੰਕਾਰਜ(ਖਾਲੀ)
{
    ਪੂਰਨ ਨਿਵੇਸ਼ = 10;
    ਪੂਰਨ output;
    asm("add %[out], %[in], #5"
        : [ਬਾਹਰਲਾ] "=r"(output)
        : [ਵਿੱਚ] "r"(ਨਿਵੇਸ਼));
    ਪ੍ਰਤਿਜ੍ਞਾ(output == 15);
    ਲਿਖੋ("Test 16 (named operand): PASSED\n");
}

/* Test 17: Memory clobber */
ਖਾਲੀ test_ਸਮ੍ਰਿਤੀ_clobber(ਖਾਲੀ)
{
    ਪੂਰਨ x = 10;
    asm ਅਸਥਿਰ("" : : : "memory");
    ਪ੍ਰਤਿਜ੍ਞਾ(x == 10);
    ਲਿਖੋ("Test 17 (memory clobber): PASSED\n");
}

/* Test 18: Condition flags clobber */
ਖਾਲੀ test_cc_clobber(ਖਾਲੀ)
{
    ਪੂਰਨ x = 100;
    ਪੂਰਨ y;
    asm("adds %0, %1, #0" : "=r"(y) : "r"(x) : "cc");
    ਪ੍ਰਤਿਜ੍ਞਾ(y == 100);
    ਲਿਖੋ("Test 18 (cc clobber): PASSED\n");
}

/* Test 19: Large immediate with movz/movk */
ਖਾਲੀ test_large_ਤੁਰੰਤ(ਖਾਲੀ)
{
    uint64_t val;
    asm("movz %0, #0x1234, lsl #16; movk %0, #0x5678" : "=r"(val));
    ਪ੍ਰਤਿਜ੍ਞਾ(val == 0x12345678ULL);
    ਲਿਖੋ("Test 19 (large immediate): PASSED\n");
}

/* Test 20: Bitwise operations */
ਖਾਲੀ test_bitwise_ops(ਖਾਲੀ)
{
    uint64_t a = 0xf0f0f0f00f0f0f0fULL;
    uint64_t b = 0x3333ffff0000ccccULL;
    uint64_t andv;
    uint64_t orv;
    uint64_t xorv;
    uint64_t imm_and;

    asm("and %0, %1, %2" : "=r"(andv) : "r"(a), "r"(b));
    asm("orr %0, %1, %2" : "=r"(orv) : "r"(a), "r"(b));
    asm("eor %0, %1, %2" : "=r"(xorv) : "r"(a), "r"(b));
    asm("and %0, %1, %2" : "=r"(imm_and)
        : "r"(~0ULL), "L"(0xff00ff00ff00ff00ULL));

    ਪ੍ਰਤਿਜ੍ਞਾ(andv == (a & b));
    ਪ੍ਰਤਿਜ੍ਞਾ(orv == (a | b));
    ਪ੍ਰਤਿਜ੍ਞਾ(xorv == (a ^ b));
    ਪ੍ਰਤਿਜ੍ਞਾ(imm_and == 0xff00ff00ff00ff00ULL);
    ਲਿਖੋ("Test 20 (bitwise ops): PASSED\n");
}

/* Test 21: Register shift operands */
ਖਾਲੀ test_ਰਜਿਸਟਰ_ਖਿਸਕਾਓ_operands(ਖਾਲੀ)
{
    uint64_t val = 3;
    uint64_t amount = 4;
    uint64_t shifted;
    uint64_t rotated;

    asm("lsl %0, %1, %2" : "=r"(shifted) : "r"(val), "r"(amount));
    asm("ror %0, %1, %2" : "=r"(rotated)
        : "r"(0x0123456789abcdefULL), "r"(8ULL));
    ਪ੍ਰਤਿਜ੍ਞਾ(shifted == 48);
    ਪ੍ਰਤਿਜ੍ਞਾ(rotated == 0xef0123456789abcdULL);
    ਲਿਖੋ("Test 21 (register shifts): PASSED\n");
}

/* Test 22: ROR immediate alias of EXTR */
ਖਾਲੀ test_ror_ਤੁਰੰਤ(ਖਾਲੀ)
{
    uint64_t rotated;

    asm("ror %0, %1, #8" : "=r"(rotated) : "r"(0x0123456789abcdefULL));
    ਪ੍ਰਤਿਜ੍ਞਾ(rotated == 0xef0123456789abcdULL);
    ਲਿਖੋ("Test 22 (ror immediate): PASSED\n");
}

/* Test 23: FP/SIMD register constraint and modifier */
ਖਾਲੀ test_fp_ਰਜਿਸਟਰ_ਸੰਕਾਰਜ(ਖਾਲੀ)
{
    ਦੁੱਗਣਾ x = 3.5;
    ਦੁੱਗਣਾ y;

    asm("ldr %d0, [%1]" : "=w"(y) : "r"(&x));
    ਪ੍ਰਤਿਜ੍ਞਾ(y == x);
    ਲਿਖੋ("Test 23 (fp register operand): PASSED\n");
}

/* Test 24: Zero constraint */
ਖਾਲੀ test_zero_constraint(ਖਾਲੀ)
{
    uint64_t x = 41;
    uint64_t y;

    asm("add %0, %1, %x2" : "=r"(y) : "r"(x), "Z"(0));
    ਪ੍ਰਤਿਜ੍ਞਾ(y == x);
    ਲਿਖੋ("Test 24 (Z constraint): PASSED\n");
}

/* Test 25: 32-bit logical immediate constraint */
ਖਾਲੀ test_logical_imm32_constraint(ਖਾਲੀ)
{
    uint32_t y;

    asm("orr %w0, wzr, %1" : "=r"(y) : "K"(0xff));
    ਪ੍ਰਤਿਜ੍ਞਾ(y == 0xff);
    ਲਿਖੋ("Test 25 (K constraint): PASSED\n");
}

/* Test 26: 64-bit logical immediate constraint */
ਖਾਲੀ test_logical_imm64_constraint(ਖਾਲੀ)
{
    uint64_t y;

    asm("orr %0, xzr, %1" : "=r"(y) : "L"(0xff00ff00ff00ff00ULL));
    ਪ੍ਰਤਿਜ੍ਞਾ(y == 0xff00ff00ff00ff00ULL);
    ਲਿਖੋ("Test 26 (L constraint): PASSED\n");
}

/* Test 27: 32-bit MOV pseudo immediate constraint */
ਖਾਲੀ test_mov_imm32_constraint(ਖਾਲੀ)
{
    uint32_t y;

    asm("mov %w0, %1" : "=r"(y) : "M"(0x1234));
    ਪ੍ਰਤਿਜ੍ਞਾ(y == 0x1234);
    ਲਿਖੋ("Test 27 (M constraint): PASSED\n");
}

/* Test 28: 64-bit MOV pseudo immediate constraint */
ਖਾਲੀ test_mov_imm64_constraint(ਖਾਲੀ)
{
    uint64_t y;

    asm("mov %0, %1" : "=r"(y) : "N"(0x12340000ULL));
    ਪ੍ਰਤਿਜ੍ਞਾ(y == 0x12340000ULL);
    ਲਿਖੋ("Test 28 (N constraint): PASSED\n");
}

/* Test 29: x FP/SIMD register constraint */
ਖਾਲੀ test_x_constraint_fp(ਖਾਲੀ)
{
    ਦੁੱਗਣਾ x = 6.25;
    ਦੁੱਗਣਾ y;

    asm("ldr %d0, [%1]" : "=x"(y) : "r"(&x));
    ਪ੍ਰਤਿਜ੍ਞਾ(y == x);
    ਲਿਖੋ("Test 29 (x constraint): PASSED\n");
}

/* Test 30: y FP/SIMD register constraint */
ਖਾਲੀ test_y_constraint_fp(ਖਾਲੀ)
{
    ਦੁੱਗਣਾ x = 7.25;
    ਦੁੱਗਣਾ y;

    asm("ldr %d0, [%1]" : "=y"(y) : "r"(&x));
    ਪ੍ਰਤਿਜ੍ਞਾ(y == x);
    ਲਿਖੋ("Test 30 (y constraint): PASSED\n");
}

/* Test 31: Q memory constraint */
ਸਥਿਰ ਪੂਰਨ arm64_q_ਲੱਦੋ(ਪੂਰਨ *ptr)
{
    ਪੂਰਨ y;

    asm("ldr %w0, %1" : "=r"(y) : "Q"(*ptr));
    ਵਾਪਸ y;
}

ਖਾਲੀ test_q_ਸਮ੍ਰਿਤੀ_constraint(ਖਾਲੀ)
{
    ਪੂਰਨ x = 91;
    ਪ੍ਰਤਿਜ੍ਞਾ(arm64_q_ਲੱਦੋ(&x) == 91);
    ਲਿਖੋ("Test 31 (Q constraint): PASSED\n");
}

/* Test 32: Ump pair-memory constraint */
ਖਾਲੀ test_ump_ਸਮ੍ਰਿਤੀ_constraint(ਖਾਲੀ)
{
    ਬਣਤਰ pair64 pair = { 0x1122334455667788ULL, 0x99aabbccddeeff00ULL };
    uint64_t a;
    uint64_t b;

    asm("ldp %0, %1, %2" : "=r"(a), "=r"(b) : "Ump"(pair));
    ਪ੍ਰਤਿਜ੍ਞਾ(a == pair.a);
    ਪ੍ਰਤਿਜ੍ਞਾ(b == pair.b);
    ਲਿਖੋ("Test 32 (Ump constraint): PASSED\n");
}

ਪੂਰਨ ਮੁੱਖ(ਖਾਲੀ)
{
    ਲਿਖੋ("ARM64 Extended Inline Assembly Tests\n");
    test_basic_output();
    test_ਨਿਵੇਸ਼_ਸੰਕਾਰਜ();
    test_read_write_ਸੰਕਾਰਜ();
    test_ਸਮ੍ਰਿਤੀ_ਲੱਦੋ();
    test_ਸਮ੍ਰਿਤੀ_store();
    test_ਢੇਰ_ਸਮ੍ਰਿਤੀ_ਸੰਕਾਰਜ();
    test_ਚਿੰਨ੍ਹ_ਸਮ੍ਰਿਤੀ_ਸੰਕਾਰਜ();
    test_clobber_list();
    test_ਗੁਣਜ_outputs();
    test_constraint_reference();
    test_early_clobber();
    test_w_ਰਜਿਸਟਰ();
    test_ਤੁਰੰਤ_i_constraint();
    test_general_ਸੰਕਾਰਜ_constraint();
    test_ਗੁਣਜ_io();
    test_regvar_preservation();
    test_complex_arithmetic();
    test_named_ਸੰਕਾਰਜ();
    test_ਸਮ੍ਰਿਤੀ_clobber();
    test_cc_clobber();
    test_large_ਤੁਰੰਤ();
    test_bitwise_ops();
    test_ਰਜਿਸਟਰ_ਖਿਸਕਾਓ_operands();
    test_ror_ਤੁਰੰਤ();
    test_fp_ਰਜਿਸਟਰ_ਸੰਕਾਰਜ();
    test_zero_constraint();
    test_logical_imm32_constraint();
    test_logical_imm64_constraint();
    test_mov_imm32_constraint();
    test_mov_imm64_constraint();
    test_x_constraint_fp();
    test_y_constraint_fp();
    test_q_ਸਮ੍ਰਿਤੀ_constraint();
    test_ump_ਸਮ੍ਰਿਤੀ_constraint();
    test_symbolic_ਪਤਾ_constraint_compile_only();
    ਲਿਖੋ("ARM64 Extended Inline Assembly Tests PASSED!\n");
    ਵਾਪਸ 0;
}
