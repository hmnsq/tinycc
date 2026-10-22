/*
 * ARM64 Extended Inline Assembly Tests
 * Tests for GCC-style extended inline assembly with operands, constraints, and clobbers
 */

#अन्तर्भाव <stdio.h>
#अन्तर्भाव <stdint.h>
#अन्तर्भाव <assert.h>

संरचना pair64 {
    uint64_t a;
    uint64_t b;
};

स्थिर पूर्णाङ्क arm64_चिह्नम्_target(शून्य)
{
    प्रत्यागम 7;
}

स्थिर शून्य test_symbolic_स्थानाङ्कः_constraint_compile_only(शून्य)
{
    asm चञ्चल("" : : "S"(arm64_चिह्नम्_target));
}

/* Test 1: Basic output operand */
शून्य test_basic_output(शून्य)
{
    पूर्णाङ्क x;
    asm("mov %0, #42" : "=r"(x));
    प्रतिज्ञा(x == 42);
    प्रारूप_लिख("Test 1 (basic output): PASSED\n");
}

/* Test 2: Input operand */
शून्य test_निवेशः_सङ्कार्यम्(शून्य)
{
    पूर्णाङ्क x = 10;
    पूर्णाङ्क y;
    asm("add %0, %1, #5" : "=r"(y) : "r"(x));
    प्रतिज्ञा(y == 15);
    प्रारूप_लिख("Test 2 (input operand): PASSED\n");
}

/* Test 3: Read-write operand */
शून्य test_read_write_सङ्कार्यम्(शून्य)
{
    पूर्णाङ्क x = 10;
    asm("add %0, %0, #1" : "+r"(x));
    प्रतिज्ञा(x == 11);
    प्रारूप_लिख("Test 3 (read-write operand): PASSED\n");
}

/* Test 4: Memory operand - load */
शून्य test_स्मृतिः_आरोपय(शून्य)
{
    पूर्णाङ्क x = 42;
    पूर्णाङ्क y;
    asm("ldr %w0, [%1]" : "=r"(y) : "r"(&x));
    प्रतिज्ञा(y == 42);
    प्रारूप_लिख("Test 4 (memory load): PASSED\n");
}

/* Test 5: Memory operand - store */
शून्य test_स्मृतिः_store(शून्य)
{
    पूर्णाङ्क x;
    पूर्णाङ्क val = 123;
    asm("str %w1, [%0]" : : "r"(&x), "r"(val));
    प्रतिज्ञा(x == 123);
    प्रारूप_लिख("Test 5 (memory store): PASSED\n");
}

/* Test 5a: Stack memory operand with frame-relative offset */
शून्य test_राशिः_स्मृतिः_सङ्कार्यम्(शून्य)
{
    दीर्घ x = 0;
    दीर्घ val = 321;

    asm चञ्चल("str %0, %1" : : "r"(val), "m"(x));
    प्रतिज्ञा(x == 321);
    प्रारूप_लिख("Test 5a (stack memory operand): PASSED\n");
}

/* Test 5b: Symbol memory operand */
स्थिर दीर्घ arm64_चिह्नम्_mem;

शून्य test_चिह्नम्_स्मृतिः_सङ्कार्यम्(शून्य)
{
    दीर्घ val = 654;

    arm64_चिह्नम्_mem = 0;
    asm चञ्चल("str %0, %1" : : "r"(val), "m"(arm64_चिह्नम्_mem));
    प्रतिज्ञा(arm64_चिह्नम्_mem == 654);
    प्रारूप_लिख("Test 5b (symbol memory operand): PASSED\n");
}

/* Test 6: Clobber list */
शून्य test_clobber_list(शून्य)
{
    पूर्णाङ्क x = 10;
    पूर्णाङ्क y = 20;
    पूर्णाङ्क परिणाम;
    asm("add %0, %1, %2" 
        : "=r"(परिणाम)
        : "r"(x), "r"(y)
        : "cc");
    प्रतिज्ञा(परिणाम == 30);
    प्रारूप_लिख("Test 6 (clobber list): PASSED\n");
}

/* Test 7: Multiple outputs */
शून्य test_गुणजः_outputs(शून्य)
{
    पूर्णाङ्क a, b;
    asm("mov %0, #1; mov %1, #2" 
        : "=r"(a), "=r"(b));
    प्रतिज्ञा(a == 1 && b == 2);
    प्रारूप_लिख("Test 7 (multiple outputs): PASSED\n");
}

/* Test 8: Constraint reference */
शून्य test_constraint_reference(शून्य)
{
    पूर्णाङ्क x = 10;
    पूर्णाङ्क y;
    asm("add %0, %1, #5" : "=r"(y) : "0"(x));
    प्रतिज्ञा(y == 15);
    प्रारूप_लिख("Test 8 (constraint reference): PASSED\n");
}

/* Test 9: Early clobber */
शून्य test_early_clobber(शून्य)
{
    पूर्णाङ्क x = 10;
    पूर्णाङ्क y;
    asm("mov %0, #42" : "=&r"(y) : "r"(x));
    प्रतिज्ञा(y == 42);
    प्रारूप_लिख("Test 9 (early clobber): PASSED\n");
}

/* Test 10: 32-bit register modifier */
शून्य test_w_पञ्जिकाकोशः(शून्य)
{
    uint32_t x = 100;
    uint32_t y;
    asm("add %w0, %w1, #50" : "=r"(y) : "r"(x));
    प्रतिज्ञा(y == 150);
    प्रारूप_लिख("Test 10 (w register modifier): PASSED\n");
}

/* Test 11: Immediate constraint 'I' (12-bit immediate) */
शून्य test_तात्कालिकम्_i_constraint(शून्य)
{
    पूर्णाङ्क x = 100;
    पूर्णाङ्क y;
    asm("add %0, %1, #200" : "=r"(y) : "r"(x), "I"(200));
    प्रतिज्ञा(y == 300);
    प्रारूप_लिख("Test 11 (immediate I constraint): PASSED\n");
}

/* Test 12: Register constraint */
शून्य test_general_सङ्कार्यम्_constraint(शून्य)
{
    पूर्णाङ्क x = 50;
    पूर्णाङ्क y;
    asm("add %0, %1, #10" : "=r"(y) : "r"(x));
    प्रतिज्ञा(y == 60);
    प्रारूप_लिख("Test 12 (general operand constraint): PASSED\n");
}

/* Test 13: Multiple inputs and outputs */
शून्य test_गुणजः_io(शून्य)
{
    पूर्णाङ्क a = 10, b = 20;
    पूर्णाङ्क योग, diff;
    asm("add %0, %1, %2" : "=r"(योग) : "r"(a), "r"(b));
    asm("sub %0, %1, %2" : "=r"(diff) : "r"(a), "r"(b));
    प्रतिज्ञा(योग == 30 && diff == -10);
    प्रारूप_लिख("Test 13 (multiple IO): PASSED\n");
}

/* Test 14: Register variable preservation */
शून्य test_regvar_preservation(शून्य)
{
    पञ्जिका uint64_t keep asm("x19") = 0x123456789abcdef0ULL;
    uint64_t बहिर्गमनम्;

    asm चञ्चल("mov x19, #7; add %0, x19, #1"
        : "=r"(बहिर्गमनम्)
        :
        : "x19");
    प्रतिज्ञा(keep == 0x123456789abcdef0ULL);
    प्रतिज्ञा(बहिर्गमनम् == 8);
    प्रारूप_लिख("Test 14 (regvar preservation): PASSED\n");
}

/* Test 15: Complex arithmetic */
शून्य test_complex_arithmetic(शून्य)
{
    पूर्णाङ्क a = 100, b = 50, c = 25;
    पूर्णाङ्क परिणाम;
    asm("add %0, %1, %2; sub %0, %0, %3"
        : "=&r"(परिणाम)
        : "r"(a), "r"(b), "r"(c));
    प्रतिज्ञा(परिणाम == 125);
    प्रारूप_लिख("Test 15 (complex arithmetic): PASSED\n");
}

/* Test 16: Named operand (GCC extension) */
शून्य test_named_सङ्कार्यम्(शून्य)
{
    पूर्णाङ्क निवेशः = 10;
    पूर्णाङ्क output;
    asm("add %[out], %[in], #5"
        : [बहिर्गमनम्] "=r"(output)
        : [अन्तर्] "r"(निवेशः));
    प्रतिज्ञा(output == 15);
    प्रारूप_लिख("Test 16 (named operand): PASSED\n");
}

/* Test 17: Memory clobber */
शून्य test_स्मृतिः_clobber(शून्य)
{
    पूर्णाङ्क x = 10;
    asm चञ्चल("" : : : "memory");
    प्रतिज्ञा(x == 10);
    प्रारूप_लिख("Test 17 (memory clobber): PASSED\n");
}

/* Test 18: Condition flags clobber */
शून्य test_cc_clobber(शून्य)
{
    पूर्णाङ्क x = 100;
    पूर्णाङ्क y;
    asm("adds %0, %1, #0" : "=r"(y) : "r"(x) : "cc");
    प्रतिज्ञा(y == 100);
    प्रारूप_लिख("Test 18 (cc clobber): PASSED\n");
}

/* Test 19: Large immediate with movz/movk */
शून्य test_large_तात्कालिकम्(शून्य)
{
    uint64_t val;
    asm("movz %0, #0x1234, lsl #16; movk %0, #0x5678" : "=r"(val));
    प्रतिज्ञा(val == 0x12345678ULL);
    प्रारूप_लिख("Test 19 (large immediate): PASSED\n");
}

/* Test 20: Bitwise operations */
शून्य test_bitwise_ops(शून्य)
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

    प्रतिज्ञा(andv == (a & b));
    प्रतिज्ञा(orv == (a | b));
    प्रतिज्ञा(xorv == (a ^ b));
    प्रतिज्ञा(imm_and == 0xff00ff00ff00ff00ULL);
    प्रारूप_लिख("Test 20 (bitwise ops): PASSED\n");
}

/* Test 21: Register shift operands */
शून्य test_पञ्जिकाकोशः_सरणम्_operands(शून्य)
{
    uint64_t val = 3;
    uint64_t amount = 4;
    uint64_t shifted;
    uint64_t rotated;

    asm("lsl %0, %1, %2" : "=r"(shifted) : "r"(val), "r"(amount));
    asm("ror %0, %1, %2" : "=r"(rotated)
        : "r"(0x0123456789abcdefULL), "r"(8ULL));
    प्रतिज्ञा(shifted == 48);
    प्रतिज्ञा(rotated == 0xef0123456789abcdULL);
    प्रारूप_लिख("Test 21 (register shifts): PASSED\n");
}

/* Test 22: ROR immediate alias of EXTR */
शून्य test_ror_तात्कालिकम्(शून्य)
{
    uint64_t rotated;

    asm("ror %0, %1, #8" : "=r"(rotated) : "r"(0x0123456789abcdefULL));
    प्रतिज्ञा(rotated == 0xef0123456789abcdULL);
    प्रारूप_लिख("Test 22 (ror immediate): PASSED\n");
}

/* Test 23: FP/SIMD register constraint and modifier */
शून्य test_fp_पञ्जिकाकोशः_सङ्कार्यम्(शून्य)
{
    द्विगुण x = 3.5;
    द्विगुण y;

    asm("ldr %d0, [%1]" : "=w"(y) : "r"(&x));
    प्रतिज्ञा(y == x);
    प्रारूप_लिख("Test 23 (fp register operand): PASSED\n");
}

/* Test 24: Zero constraint */
शून्य test_zero_constraint(शून्य)
{
    uint64_t x = 41;
    uint64_t y;

    asm("add %0, %1, %x2" : "=r"(y) : "r"(x), "Z"(0));
    प्रतिज्ञा(y == x);
    प्रारूप_लिख("Test 24 (Z constraint): PASSED\n");
}

/* Test 25: 32-bit logical immediate constraint */
शून्य test_logical_imm32_constraint(शून्य)
{
    uint32_t y;

    asm("orr %w0, wzr, %1" : "=r"(y) : "K"(0xff));
    प्रतिज्ञा(y == 0xff);
    प्रारूप_लिख("Test 25 (K constraint): PASSED\n");
}

/* Test 26: 64-bit logical immediate constraint */
शून्य test_logical_imm64_constraint(शून्य)
{
    uint64_t y;

    asm("orr %0, xzr, %1" : "=r"(y) : "L"(0xff00ff00ff00ff00ULL));
    प्रतिज्ञा(y == 0xff00ff00ff00ff00ULL);
    प्रारूप_लिख("Test 26 (L constraint): PASSED\n");
}

/* Test 27: 32-bit MOV pseudo immediate constraint */
शून्य test_mov_imm32_constraint(शून्य)
{
    uint32_t y;

    asm("mov %w0, %1" : "=r"(y) : "M"(0x1234));
    प्रतिज्ञा(y == 0x1234);
    प्रारूप_लिख("Test 27 (M constraint): PASSED\n");
}

/* Test 28: 64-bit MOV pseudo immediate constraint */
शून्य test_mov_imm64_constraint(शून्य)
{
    uint64_t y;

    asm("mov %0, %1" : "=r"(y) : "N"(0x12340000ULL));
    प्रतिज्ञा(y == 0x12340000ULL);
    प्रारूप_लिख("Test 28 (N constraint): PASSED\n");
}

/* Test 29: x FP/SIMD register constraint */
शून्य test_x_constraint_fp(शून्य)
{
    द्विगुण x = 6.25;
    द्विगुण y;

    asm("ldr %d0, [%1]" : "=x"(y) : "r"(&x));
    प्रतिज्ञा(y == x);
    प्रारूप_लिख("Test 29 (x constraint): PASSED\n");
}

/* Test 30: y FP/SIMD register constraint */
शून्य test_y_constraint_fp(शून्य)
{
    द्विगुण x = 7.25;
    द्विगुण y;

    asm("ldr %d0, [%1]" : "=y"(y) : "r"(&x));
    प्रतिज्ञा(y == x);
    प्रारूप_लिख("Test 30 (y constraint): PASSED\n");
}

/* Test 31: Q memory constraint */
स्थिर पूर्णाङ्क arm64_q_आरोपय(पूर्णाङ्क *ptr)
{
    पूर्णाङ्क y;

    asm("ldr %w0, %1" : "=r"(y) : "Q"(*ptr));
    प्रत्यागम y;
}

शून्य test_q_स्मृतिः_constraint(शून्य)
{
    पूर्णाङ्क x = 91;
    प्रतिज्ञा(arm64_q_आरोपय(&x) == 91);
    प्रारूप_लिख("Test 31 (Q constraint): PASSED\n");
}

/* Test 32: Ump pair-memory constraint */
शून्य test_ump_स्मृतिः_constraint(शून्य)
{
    संरचना pair64 pair = { 0x1122334455667788ULL, 0x99aabbccddeeff00ULL };
    uint64_t a;
    uint64_t b;

    asm("ldp %0, %1, %2" : "=r"(a), "=r"(b) : "Ump"(pair));
    प्रतिज्ञा(a == pair.a);
    प्रतिज्ञा(b == pair.b);
    प्रारूप_लिख("Test 32 (Ump constraint): PASSED\n");
}

पूर्णाङ्क मुख्यम्(शून्य)
{
    प्रारूप_लिख("ARM64 Extended Inline Assembly Tests\n");
    test_basic_output();
    test_निवेशः_सङ्कार्यम्();
    test_read_write_सङ्कार्यम्();
    test_स्मृतिः_आरोपय();
    test_स्मृतिः_store();
    test_राशिः_स्मृतिः_सङ्कार्यम्();
    test_चिह्नम्_स्मृतिः_सङ्कार्यम्();
    test_clobber_list();
    test_गुणजः_outputs();
    test_constraint_reference();
    test_early_clobber();
    test_w_पञ्जिकाकोशः();
    test_तात्कालिकम्_i_constraint();
    test_general_सङ्कार्यम्_constraint();
    test_गुणजः_io();
    test_regvar_preservation();
    test_complex_arithmetic();
    test_named_सङ्कार्यम्();
    test_स्मृतिः_clobber();
    test_cc_clobber();
    test_large_तात्कालिकम्();
    test_bitwise_ops();
    test_पञ्जिकाकोशः_सरणम्_operands();
    test_ror_तात्कालिकम्();
    test_fp_पञ्जिकाकोशः_सङ्कार्यम्();
    test_zero_constraint();
    test_logical_imm32_constraint();
    test_logical_imm64_constraint();
    test_mov_imm32_constraint();
    test_mov_imm64_constraint();
    test_x_constraint_fp();
    test_y_constraint_fp();
    test_q_स्मृतिः_constraint();
    test_ump_स्मृतिः_constraint();
    test_symbolic_स्थानाङ्कः_constraint_compile_only();
    प्रारूप_लिख("ARM64 Extended Inline Assembly Tests PASSED!\n");
    प्रत्यागम 0;
}
