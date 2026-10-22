/*
 * ARM64 Extended Inline Assembly Tests
 * Tests for GCC-style extended inline assembly with operands, constraints, and clobbers
 */

#ಅನ್ತರ್ಭಾವ <stdio.h>
#ಅನ್ತರ್ಭಾವ <stdint.h>
#ಅನ್ತರ್ಭಾವ <assert.h>

ರಚನೆ pair64 {
    uint64_t a;
    uint64_t b;
};

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ arm64_ಚಿಹ್ನೆ_ಗುರಿ(ಶೂನ್ಯ)
{
    ಹಿಂತಿರುಗಿ 7;
}

ಸ್ಥಿರ ಶೂನ್ಯ test_symbolic_ವಿಳಾಸ_constraint_compile_only(ಶೂನ್ಯ)
{
    asm ಅಸ್ಥಿರ("" : : "S"(arm64_ಚಿಹ್ನೆ_ಗುರಿ));
}

/* Test 1: Basic output operand */
ಶೂನ್ಯ test_basic_output(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ x;
    asm("mov %0, #42" : "=r"(x));
    ಪ್ರತಿಜ್ಞಾ(x == 42);
    ಬರೆ("Test 1 (basic output): PASSED\n");
}

/* Test 2: Input operand */
ಶೂನ್ಯ test_ಒಳಹರಿವು_ಕಾರ್ಯಾಂಶ(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ x = 10;
    ಪೂರ್ಣಾಂಕ y;
    asm("add %0, %1, #5" : "=r"(y) : "r"(x));
    ಪ್ರತಿಜ್ಞಾ(y == 15);
    ಬರೆ("Test 2 (input operand): PASSED\n");
}

/* Test 3: Read-write operand */
ಶೂನ್ಯ test_read_write_ಕಾರ್ಯಾಂಶ(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ x = 10;
    asm("add %0, %0, #1" : "+r"(x));
    ಪ್ರತಿಜ್ಞಾ(x == 11);
    ಬರೆ("Test 3 (read-write operand): PASSED\n");
}

/* Test 4: Memory operand - load */
ಶೂನ್ಯ test_ಸ್ಮರಣೆ_ತುಂಬು(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ x = 42;
    ಪೂರ್ಣಾಂಕ y;
    asm("ldr %w0, [%1]" : "=r"(y) : "r"(&x));
    ಪ್ರತಿಜ್ಞಾ(y == 42);
    ಬರೆ("Test 4 (memory load): PASSED\n");
}

/* Test 5: Memory operand - store */
ಶೂನ್ಯ test_ಸ್ಮರಣೆ_store(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ x;
    ಪೂರ್ಣಾಂಕ val = 123;
    asm("str %w1, [%0]" : : "r"(&x), "r"(val));
    ಪ್ರತಿಜ್ಞಾ(x == 123);
    ಬರೆ("Test 5 (memory store): PASSED\n");
}

/* Test 5a: Stack memory operand with frame-relative offset */
ಶೂನ್ಯ test_ರಾಶಿ_ಸ್ಮರಣೆ_ಕಾರ್ಯಾಂಶ(ಶೂನ್ಯ)
{
    ದೀರ್ಘ x = 0;
    ದೀರ್ಘ val = 321;

    asm ಅಸ್ಥಿರ("str %0, %1" : : "r"(val), "m"(x));
    ಪ್ರತಿಜ್ಞಾ(x == 321);
    ಬರೆ("Test 5a (stack memory operand): PASSED\n");
}

/* Test 5b: Symbol memory operand */
ಸ್ಥಿರ ದೀರ್ಘ arm64_ಚಿಹ್ನೆ_mem;

ಶೂನ್ಯ test_ಚಿಹ್ನೆ_ಸ್ಮರಣೆ_ಕಾರ್ಯಾಂಶ(ಶೂನ್ಯ)
{
    ದೀರ್ಘ val = 654;

    arm64_ಚಿಹ್ನೆ_mem = 0;
    asm ಅಸ್ಥಿರ("str %0, %1" : : "r"(val), "m"(arm64_ಚಿಹ್ನೆ_mem));
    ಪ್ರತಿಜ್ಞಾ(arm64_ಚಿಹ್ನೆ_mem == 654);
    ಬರೆ("Test 5b (symbol memory operand): PASSED\n");
}

/* Test 6: Clobber list */
ಶೂನ್ಯ test_clobber_list(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ x = 10;
    ಪೂರ್ಣಾಂಕ y = 20;
    ಪೂರ್ಣಾಂಕ ಫಲಿತಾಂಶ;
    asm("add %0, %1, %2" 
        : "=r"(ಫಲಿತಾಂಶ)
        : "r"(x), "r"(y)
        : "cc");
    ಪ್ರತಿಜ್ಞಾ(ಫಲಿತಾಂಶ == 30);
    ಬರೆ("Test 6 (clobber list): PASSED\n");
}

/* Test 7: Multiple outputs */
ಶೂನ್ಯ test_ಅಪವರ್ತ್ಯ_outputs(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ a, b;
    asm("mov %0, #1; mov %1, #2" 
        : "=r"(a), "=r"(b));
    ಪ್ರತಿಜ್ಞಾ(a == 1 && b == 2);
    ಬರೆ("Test 7 (multiple outputs): PASSED\n");
}

/* Test 8: Constraint reference */
ಶೂನ್ಯ test_constraint_reference(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ x = 10;
    ಪೂರ್ಣಾಂಕ y;
    asm("add %0, %1, #5" : "=r"(y) : "0"(x));
    ಪ್ರತಿಜ್ಞಾ(y == 15);
    ಬರೆ("Test 8 (constraint reference): PASSED\n");
}

/* Test 9: Early clobber */
ಶೂನ್ಯ test_early_clobber(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ x = 10;
    ಪೂರ್ಣಾಂಕ y;
    asm("mov %0, #42" : "=&r"(y) : "r"(x));
    ಪ್ರತಿಜ್ಞಾ(y == 42);
    ಬರೆ("Test 9 (early clobber): PASSED\n");
}

/* Test 10: 32-bit register modifier */
ಶೂನ್ಯ test_w_ರಿಜಿಸ್ಟರ್(ಶೂನ್ಯ)
{
    uint32_t x = 100;
    uint32_t y;
    asm("add %w0, %w1, #50" : "=r"(y) : "r"(x));
    ಪ್ರತಿಜ್ಞಾ(y == 150);
    ಬರೆ("Test 10 (w register modifier): PASSED\n");
}

/* Test 11: Immediate constraint 'I' (12-bit immediate) */
ಶೂನ್ಯ test_ತಕ್ಷಣ_i_constraint(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ x = 100;
    ಪೂರ್ಣಾಂಕ y;
    asm("add %0, %1, #200" : "=r"(y) : "r"(x), "I"(200));
    ಪ್ರತಿಜ್ಞಾ(y == 300);
    ಬರೆ("Test 11 (immediate I constraint): PASSED\n");
}

/* Test 12: Register constraint */
ಶೂನ್ಯ test_general_ಕಾರ್ಯಾಂಶ_constraint(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ x = 50;
    ಪೂರ್ಣಾಂಕ y;
    asm("add %0, %1, #10" : "=r"(y) : "r"(x));
    ಪ್ರತಿಜ್ಞಾ(y == 60);
    ಬರೆ("Test 12 (general operand constraint): PASSED\n");
}

/* Test 13: Multiple inputs and outputs */
ಶೂನ್ಯ test_ಅಪವರ್ತ್ಯ_io(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ a = 10, b = 20;
    ಪೂರ್ಣಾಂಕ ಮೊತ್ತ, diff;
    asm("add %0, %1, %2" : "=r"(ಮೊತ್ತ) : "r"(a), "r"(b));
    asm("sub %0, %1, %2" : "=r"(diff) : "r"(a), "r"(b));
    ಪ್ರತಿಜ್ಞಾ(ಮೊತ್ತ == 30 && diff == -10);
    ಬರೆ("Test 13 (multiple IO): PASSED\n");
}

/* Test 14: Register variable preservation */
ಶೂನ್ಯ test_regvar_preservation(ಶೂನ್ಯ)
{
    ನೋಂದಣಿ uint64_t keep asm("x19") = 0x123456789abcdef0ULL;
    uint64_t ಹೊರಹೋಗು;

    asm ಅಸ್ಥಿರ("mov x19, #7; add %0, x19, #1"
        : "=r"(ಹೊರಹೋಗು)
        :
        : "x19");
    ಪ್ರತಿಜ್ಞಾ(keep == 0x123456789abcdef0ULL);
    ಪ್ರತಿಜ್ಞಾ(ಹೊರಹೋಗು == 8);
    ಬರೆ("Test 14 (regvar preservation): PASSED\n");
}

/* Test 15: Complex arithmetic */
ಶೂನ್ಯ test_complex_arithmetic(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ a = 100, b = 50, c = 25;
    ಪೂರ್ಣಾಂಕ ಫಲಿತಾಂಶ;
    asm("add %0, %1, %2; sub %0, %0, %3"
        : "=&r"(ಫಲಿತಾಂಶ)
        : "r"(a), "r"(b), "r"(c));
    ಪ್ರತಿಜ್ಞಾ(ಫಲಿತಾಂಶ == 125);
    ಬರೆ("Test 15 (complex arithmetic): PASSED\n");
}

/* Test 16: Named operand (GCC extension) */
ಶೂನ್ಯ test_named_ಕಾರ್ಯಾಂಶ(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ ಒಳಹರಿವು = 10;
    ಪೂರ್ಣಾಂಕ output;
    asm("add %[out], %[in], #5"
        : [ಹೊರಹೋಗು] "=r"(output)
        : [ಒಳ] "r"(ಒಳಹರಿವು));
    ಪ್ರತಿಜ್ಞಾ(output == 15);
    ಬರೆ("Test 16 (named operand): PASSED\n");
}

/* Test 17: Memory clobber */
ಶೂನ್ಯ test_ಸ್ಮರಣೆ_clobber(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ x = 10;
    asm ಅಸ್ಥಿರ("" : : : "memory");
    ಪ್ರತಿಜ್ಞಾ(x == 10);
    ಬರೆ("Test 17 (memory clobber): PASSED\n");
}

/* Test 18: Condition flags clobber */
ಶೂನ್ಯ test_cc_clobber(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ x = 100;
    ಪೂರ್ಣಾಂಕ y;
    asm("adds %0, %1, #0" : "=r"(y) : "r"(x) : "cc");
    ಪ್ರತಿಜ್ಞಾ(y == 100);
    ಬರೆ("Test 18 (cc clobber): PASSED\n");
}

/* Test 19: Large immediate with movz/movk */
ಶೂನ್ಯ test_large_ತಕ್ಷಣ(ಶೂನ್ಯ)
{
    uint64_t val;
    asm("movz %0, #0x1234, lsl #16; movk %0, #0x5678" : "=r"(val));
    ಪ್ರತಿಜ್ಞಾ(val == 0x12345678ULL);
    ಬರೆ("Test 19 (large immediate): PASSED\n");
}

/* Test 20: Bitwise operations */
ಶೂನ್ಯ test_bitwise_ops(ಶೂನ್ಯ)
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

    ಪ್ರತಿಜ್ಞಾ(andv == (a & b));
    ಪ್ರತಿಜ್ಞಾ(orv == (a | b));
    ಪ್ರತಿಜ್ಞಾ(xorv == (a ^ b));
    ಪ್ರತಿಜ್ಞಾ(imm_and == 0xff00ff00ff00ff00ULL);
    ಬರೆ("Test 20 (bitwise ops): PASSED\n");
}

/* Test 21: Register shift operands */
ಶೂನ್ಯ test_ರಿಜಿಸ್ಟರ್_ಸರಿಸು_operands(ಶೂನ್ಯ)
{
    uint64_t val = 3;
    uint64_t amount = 4;
    uint64_t shifted;
    uint64_t rotated;

    asm("lsl %0, %1, %2" : "=r"(shifted) : "r"(val), "r"(amount));
    asm("ror %0, %1, %2" : "=r"(rotated)
        : "r"(0x0123456789abcdefULL), "r"(8ULL));
    ಪ್ರತಿಜ್ಞಾ(shifted == 48);
    ಪ್ರತಿಜ್ಞಾ(rotated == 0xef0123456789abcdULL);
    ಬರೆ("Test 21 (register shifts): PASSED\n");
}

/* Test 22: ROR immediate alias of EXTR */
ಶೂನ್ಯ test_ror_ತಕ್ಷಣ(ಶೂನ್ಯ)
{
    uint64_t rotated;

    asm("ror %0, %1, #8" : "=r"(rotated) : "r"(0x0123456789abcdefULL));
    ಪ್ರತಿಜ್ಞಾ(rotated == 0xef0123456789abcdULL);
    ಬರೆ("Test 22 (ror immediate): PASSED\n");
}

/* Test 23: FP/SIMD register constraint and modifier */
ಶೂನ್ಯ test_fp_ರಿಜಿಸ್ಟರ್_ಕಾರ್ಯಾಂಶ(ಶೂನ್ಯ)
{
    ದ್ವಿಗುಣ x = 3.5;
    ದ್ವಿಗುಣ y;

    asm("ldr %d0, [%1]" : "=w"(y) : "r"(&x));
    ಪ್ರತಿಜ್ಞಾ(y == x);
    ಬರೆ("Test 23 (fp register operand): PASSED\n");
}

/* Test 24: Zero constraint */
ಶೂನ್ಯ test_zero_constraint(ಶೂನ್ಯ)
{
    uint64_t x = 41;
    uint64_t y;

    asm("add %0, %1, %x2" : "=r"(y) : "r"(x), "Z"(0));
    ಪ್ರತಿಜ್ಞಾ(y == x);
    ಬರೆ("Test 24 (Z constraint): PASSED\n");
}

/* Test 25: 32-bit logical immediate constraint */
ಶೂನ್ಯ test_logical_imm32_constraint(ಶೂನ್ಯ)
{
    uint32_t y;

    asm("orr %w0, wzr, %1" : "=r"(y) : "K"(0xff));
    ಪ್ರತಿಜ್ಞಾ(y == 0xff);
    ಬರೆ("Test 25 (K constraint): PASSED\n");
}

/* Test 26: 64-bit logical immediate constraint */
ಶೂನ್ಯ test_logical_imm64_constraint(ಶೂನ್ಯ)
{
    uint64_t y;

    asm("orr %0, xzr, %1" : "=r"(y) : "L"(0xff00ff00ff00ff00ULL));
    ಪ್ರತಿಜ್ಞಾ(y == 0xff00ff00ff00ff00ULL);
    ಬರೆ("Test 26 (L constraint): PASSED\n");
}

/* Test 27: 32-bit MOV pseudo immediate constraint */
ಶೂನ್ಯ test_mov_imm32_constraint(ಶೂನ್ಯ)
{
    uint32_t y;

    asm("mov %w0, %1" : "=r"(y) : "M"(0x1234));
    ಪ್ರತಿಜ್ಞಾ(y == 0x1234);
    ಬರೆ("Test 27 (M constraint): PASSED\n");
}

/* Test 28: 64-bit MOV pseudo immediate constraint */
ಶೂನ್ಯ test_mov_imm64_constraint(ಶೂನ್ಯ)
{
    uint64_t y;

    asm("mov %0, %1" : "=r"(y) : "N"(0x12340000ULL));
    ಪ್ರತಿಜ್ಞಾ(y == 0x12340000ULL);
    ಬರೆ("Test 28 (N constraint): PASSED\n");
}

/* Test 29: x FP/SIMD register constraint */
ಶೂನ್ಯ test_x_constraint_fp(ಶೂನ್ಯ)
{
    ದ್ವಿಗುಣ x = 6.25;
    ದ್ವಿಗುಣ y;

    asm("ldr %d0, [%1]" : "=x"(y) : "r"(&x));
    ಪ್ರತಿಜ್ಞಾ(y == x);
    ಬರೆ("Test 29 (x constraint): PASSED\n");
}

/* Test 30: y FP/SIMD register constraint */
ಶೂನ್ಯ test_y_constraint_fp(ಶೂನ್ಯ)
{
    ದ್ವಿಗುಣ x = 7.25;
    ದ್ವಿಗುಣ y;

    asm("ldr %d0, [%1]" : "=y"(y) : "r"(&x));
    ಪ್ರತಿಜ್ಞಾ(y == x);
    ಬರೆ("Test 30 (y constraint): PASSED\n");
}

/* Test 31: Q memory constraint */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ arm64_q_ತುಂಬು(ಪೂರ್ಣಾಂಕ *ptr)
{
    ಪೂರ್ಣಾಂಕ y;

    asm("ldr %w0, %1" : "=r"(y) : "Q"(*ptr));
    ಹಿಂತಿರುಗಿ y;
}

ಶೂನ್ಯ test_q_ಸ್ಮರಣೆ_constraint(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ x = 91;
    ಪ್ರತಿಜ್ಞಾ(arm64_q_ತುಂಬು(&x) == 91);
    ಬರೆ("Test 31 (Q constraint): PASSED\n");
}

/* Test 32: Ump pair-memory constraint */
ಶೂನ್ಯ test_ump_ಸ್ಮರಣೆ_constraint(ಶೂನ್ಯ)
{
    ರಚನೆ pair64 pair = { 0x1122334455667788ULL, 0x99aabbccddeeff00ULL };
    uint64_t a;
    uint64_t b;

    asm("ldp %0, %1, %2" : "=r"(a), "=r"(b) : "Ump"(pair));
    ಪ್ರತಿಜ್ಞಾ(a == pair.a);
    ಪ್ರತಿಜ್ಞಾ(b == pair.b);
    ಬರೆ("Test 32 (Ump constraint): PASSED\n");
}

ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ(ಶೂನ್ಯ)
{
    ಬರೆ("ARM64 Extended Inline Assembly Tests\n");
    test_basic_output();
    test_ಒಳಹರಿವು_ಕಾರ್ಯಾಂಶ();
    test_read_write_ಕಾರ್ಯಾಂಶ();
    test_ಸ್ಮರಣೆ_ತುಂಬು();
    test_ಸ್ಮರಣೆ_store();
    test_ರಾಶಿ_ಸ್ಮರಣೆ_ಕಾರ್ಯಾಂಶ();
    test_ಚಿಹ್ನೆ_ಸ್ಮರಣೆ_ಕಾರ್ಯಾಂಶ();
    test_clobber_list();
    test_ಅಪವರ್ತ್ಯ_outputs();
    test_constraint_reference();
    test_early_clobber();
    test_w_ರಿಜಿಸ್ಟರ್();
    test_ತಕ್ಷಣ_i_constraint();
    test_general_ಕಾರ್ಯಾಂಶ_constraint();
    test_ಅಪವರ್ತ್ಯ_io();
    test_regvar_preservation();
    test_complex_arithmetic();
    test_named_ಕಾರ್ಯಾಂಶ();
    test_ಸ್ಮರಣೆ_clobber();
    test_cc_clobber();
    test_large_ತಕ್ಷಣ();
    test_bitwise_ops();
    test_ರಿಜಿಸ್ಟರ್_ಸರಿಸು_operands();
    test_ror_ತಕ್ಷಣ();
    test_fp_ರಿಜಿಸ್ಟರ್_ಕಾರ್ಯಾಂಶ();
    test_zero_constraint();
    test_logical_imm32_constraint();
    test_logical_imm64_constraint();
    test_mov_imm32_constraint();
    test_mov_imm64_constraint();
    test_x_constraint_fp();
    test_y_constraint_fp();
    test_q_ಸ್ಮರಣೆ_constraint();
    test_ump_ಸ್ಮರಣೆ_constraint();
    test_symbolic_ವಿಳಾಸ_constraint_compile_only();
    ಬರೆ("ARM64 Extended Inline Assembly Tests PASSED!\n");
    ಹಿಂತಿರುಗಿ 0;
}
