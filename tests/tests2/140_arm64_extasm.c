/*
 * ARM64 Extended Inline Assembly Tests
 * Tests for GCC-style extended inline assembly with operands, constraints, and clobbers
 */

#समावेश <stdio.h>
#समावेश <stdint.h>
#समावेश <assert.h>

काष्ठा pair64 {
    uint64_t a;
    uint64_t b;
};

अटल पूर्णांक arm64_प्रतीक_target(व्योम)
{
    वापस 7;
}

अटल व्योम test_symbolic_address_constraint_compile_only(व्योम)
{
    यंत्र अस्थिर("" : : "S"(arm64_प्रतीक_target));
}

/* Test 1: Basic output operand */
व्योम test_basic_output(व्योम)
{
    पूर्णांक x;
    यंत्र("mov %0, #42" : "=r"(x));
    निश्चित(x == 42);
    म_लिखो("Test 1 (basic output): PASSED\n");
}

/* Test 2: Input operand */
व्योम test_निवेश_operand(व्योम)
{
    पूर्णांक x = 10;
    पूर्णांक y;
    यंत्र("add %0, %1, #5" : "=r"(y) : "r"(x));
    निश्चित(y == 15);
    म_लिखो("Test 2 (input operand): PASSED\n");
}

/* Test 3: Read-write operand */
व्योम test_read_write_operand(व्योम)
{
    पूर्णांक x = 10;
    यंत्र("add %0, %0, #1" : "+r"(x));
    निश्चित(x == 11);
    म_लिखो("Test 3 (read-write operand): PASSED\n");
}

/* Test 4: Memory operand - load */
व्योम test_memory_load(व्योम)
{
    पूर्णांक x = 42;
    पूर्णांक y;
    यंत्र("ldr %w0, [%1]" : "=r"(y) : "r"(&x));
    निश्चित(y == 42);
    म_लिखो("Test 4 (memory load): PASSED\n");
}

/* Test 5: Memory operand - store */
व्योम test_memory_store(व्योम)
{
    पूर्णांक x;
    पूर्णांक val = 123;
    यंत्र("str %w1, [%0]" : : "r"(&x), "r"(val));
    निश्चित(x == 123);
    म_लिखो("Test 5 (memory store): PASSED\n");
}

/* Test 5a: Stack memory operand with frame-relative offset */
व्योम test_ढेर_memory_operand(व्योम)
{
    दीर्घ x = 0;
    दीर्घ val = 321;

    यंत्र अस्थिर("str %0, %1" : : "r"(val), "m"(x));
    निश्चित(x == 321);
    म_लिखो("Test 5a (stack memory operand): PASSED\n");
}

/* Test 5b: Symbol memory operand */
अटल दीर्घ arm64_प्रतीक_mem;

व्योम test_प्रतीक_memory_operand(व्योम)
{
    दीर्घ val = 654;

    arm64_प्रतीक_mem = 0;
    यंत्र अस्थिर("str %0, %1" : : "r"(val), "m"(arm64_प्रतीक_mem));
    निश्चित(arm64_प्रतीक_mem == 654);
    म_लिखो("Test 5b (symbol memory operand): PASSED\n");
}

/* Test 6: Clobber list */
व्योम test_clobber_list(व्योम)
{
    पूर्णांक x = 10;
    पूर्णांक y = 20;
    पूर्णांक परिणाम;
    यंत्र("add %0, %1, %2" 
        : "=r"(परिणाम)
        : "r"(x), "r"(y)
        : "cc");
    निश्चित(परिणाम == 30);
    म_लिखो("Test 6 (clobber list): PASSED\n");
}

/* Test 7: Multiple outputs */
व्योम test_multiple_outputs(व्योम)
{
    पूर्णांक a, b;
    यंत्र("mov %0, #1; mov %1, #2" 
        : "=r"(a), "=r"(b));
    निश्चित(a == 1 && b == 2);
    म_लिखो("Test 7 (multiple outputs): PASSED\n");
}

/* Test 8: Constraint reference */
व्योम test_constraint_reference(व्योम)
{
    पूर्णांक x = 10;
    पूर्णांक y;
    यंत्र("add %0, %1, #5" : "=r"(y) : "0"(x));
    निश्चित(y == 15);
    म_लिखो("Test 8 (constraint reference): PASSED\n");
}

/* Test 9: Early clobber */
व्योम test_early_clobber(व्योम)
{
    पूर्णांक x = 10;
    पूर्णांक y;
    यंत्र("mov %0, #42" : "=&r"(y) : "r"(x));
    निश्चित(y == 42);
    म_लिखो("Test 9 (early clobber): PASSED\n");
}

/* Test 10: 32-bit register modifier */
व्योम test_w_register(व्योम)
{
    uint32_t x = 100;
    uint32_t y;
    यंत्र("add %w0, %w1, #50" : "=r"(y) : "r"(x));
    निश्चित(y == 150);
    म_लिखो("Test 10 (w register modifier): PASSED\n");
}

/* Test 11: Immediate constraint 'I' (12-bit immediate) */
व्योम test_immediate_i_constraint(व्योम)
{
    पूर्णांक x = 100;
    पूर्णांक y;
    यंत्र("add %0, %1, #200" : "=r"(y) : "r"(x), "I"(200));
    निश्चित(y == 300);
    म_लिखो("Test 11 (immediate I constraint): PASSED\n");
}

/* Test 12: Register constraint */
व्योम test_general_operand_constraint(व्योम)
{
    पूर्णांक x = 50;
    पूर्णांक y;
    यंत्र("add %0, %1, #10" : "=r"(y) : "r"(x));
    निश्चित(y == 60);
    म_लिखो("Test 12 (general operand constraint): PASSED\n");
}

/* Test 13: Multiple inputs and outputs */
व्योम test_multiple_io(व्योम)
{
    पूर्णांक a = 10, b = 20;
    पूर्णांक योग, diff;
    यंत्र("add %0, %1, %2" : "=r"(योग) : "r"(a), "r"(b));
    यंत्र("sub %0, %1, %2" : "=r"(diff) : "r"(a), "r"(b));
    निश्चित(योग == 30 && diff == -10);
    म_लिखो("Test 13 (multiple IO): PASSED\n");
}

/* Test 14: Register variable preservation */
व्योम test_regvar_preservation(व्योम)
{
    रेजिस्टर uint64_t keep यंत्र("x19") = 0x123456789abcdef0ULL;
    uint64_t out;

    यंत्र अस्थिर("mov x19, #7; add %0, x19, #1"
        : "=r"(out)
        :
        : "x19");
    निश्चित(keep == 0x123456789abcdef0ULL);
    निश्चित(out == 8);
    म_लिखो("Test 14 (regvar preservation): PASSED\n");
}

/* Test 15: Complex arithmetic */
व्योम test_complex_arithmetic(व्योम)
{
    पूर्णांक a = 100, b = 50, c = 25;
    पूर्णांक परिणाम;
    यंत्र("add %0, %1, %2; sub %0, %0, %3"
        : "=&r"(परिणाम)
        : "r"(a), "r"(b), "r"(c));
    निश्चित(परिणाम == 125);
    म_लिखो("Test 15 (complex arithmetic): PASSED\n");
}

/* Test 16: Named operand (GCC extension) */
व्योम test_named_operand(व्योम)
{
    पूर्णांक निवेश = 10;
    पूर्णांक output;
    यंत्र("add %[out], %[in], #5"
        : [out] "=r"(output)
        : [in] "r"(निवेश));
    निश्चित(output == 15);
    म_लिखो("Test 16 (named operand): PASSED\n");
}

/* Test 17: Memory clobber */
व्योम test_memory_clobber(व्योम)
{
    पूर्णांक x = 10;
    यंत्र अस्थिर("" : : : "memory");
    निश्चित(x == 10);
    म_लिखो("Test 17 (memory clobber): PASSED\n");
}

/* Test 18: Condition flags clobber */
व्योम test_cc_clobber(व्योम)
{
    पूर्णांक x = 100;
    पूर्णांक y;
    यंत्र("adds %0, %1, #0" : "=r"(y) : "r"(x) : "cc");
    निश्चित(y == 100);
    म_लिखो("Test 18 (cc clobber): PASSED\n");
}

/* Test 19: Large immediate with movz/movk */
व्योम test_large_immediate(व्योम)
{
    uint64_t val;
    यंत्र("movz %0, #0x1234, lsl #16; movk %0, #0x5678" : "=r"(val));
    निश्चित(val == 0x12345678ULL);
    म_लिखो("Test 19 (large immediate): PASSED\n");
}

/* Test 20: Bitwise operations */
व्योम test_bitwise_ops(व्योम)
{
    uint64_t a = 0xf0f0f0f00f0f0f0fULL;
    uint64_t b = 0x3333ffff0000ccccULL;
    uint64_t andv;
    uint64_t orv;
    uint64_t xorv;
    uint64_t imm_and;

    यंत्र("and %0, %1, %2" : "=r"(andv) : "r"(a), "r"(b));
    यंत्र("orr %0, %1, %2" : "=r"(orv) : "r"(a), "r"(b));
    यंत्र("eor %0, %1, %2" : "=r"(xorv) : "r"(a), "r"(b));
    यंत्र("and %0, %1, %2" : "=r"(imm_and)
        : "r"(~0ULL), "L"(0xff00ff00ff00ff00ULL));

    निश्चित(andv == (a & b));
    निश्चित(orv == (a | b));
    निश्चित(xorv == (a ^ b));
    निश्चित(imm_and == 0xff00ff00ff00ff00ULL);
    म_लिखो("Test 20 (bitwise ops): PASSED\n");
}

/* Test 21: Register shift operands */
व्योम test_register_shift_operands(व्योम)
{
    uint64_t val = 3;
    uint64_t amount = 4;
    uint64_t shifted;
    uint64_t rotated;

    यंत्र("lsl %0, %1, %2" : "=r"(shifted) : "r"(val), "r"(amount));
    यंत्र("ror %0, %1, %2" : "=r"(rotated)
        : "r"(0x0123456789abcdefULL), "r"(8ULL));
    निश्चित(shifted == 48);
    निश्चित(rotated == 0xef0123456789abcdULL);
    म_लिखो("Test 21 (register shifts): PASSED\n");
}

/* Test 22: ROR immediate alias of EXTR */
व्योम test_ror_immediate(व्योम)
{
    uint64_t rotated;

    यंत्र("ror %0, %1, #8" : "=r"(rotated) : "r"(0x0123456789abcdefULL));
    निश्चित(rotated == 0xef0123456789abcdULL);
    म_लिखो("Test 22 (ror immediate): PASSED\n");
}

/* Test 23: FP/SIMD register constraint and modifier */
व्योम test_fp_register_operand(व्योम)
{
    द्विगुन x = 3.5;
    द्विगुन y;

    यंत्र("ldr %d0, [%1]" : "=w"(y) : "r"(&x));
    निश्चित(y == x);
    म_लिखो("Test 23 (fp register operand): PASSED\n");
}

/* Test 24: Zero constraint */
व्योम test_zero_constraint(व्योम)
{
    uint64_t x = 41;
    uint64_t y;

    यंत्र("add %0, %1, %x2" : "=r"(y) : "r"(x), "Z"(0));
    निश्चित(y == x);
    म_लिखो("Test 24 (Z constraint): PASSED\n");
}

/* Test 25: 32-bit logical immediate constraint */
व्योम test_logical_imm32_constraint(व्योम)
{
    uint32_t y;

    यंत्र("orr %w0, wzr, %1" : "=r"(y) : "K"(0xff));
    निश्चित(y == 0xff);
    म_लिखो("Test 25 (K constraint): PASSED\n");
}

/* Test 26: 64-bit logical immediate constraint */
व्योम test_logical_imm64_constraint(व्योम)
{
    uint64_t y;

    यंत्र("orr %0, xzr, %1" : "=r"(y) : "L"(0xff00ff00ff00ff00ULL));
    निश्चित(y == 0xff00ff00ff00ff00ULL);
    म_लिखो("Test 26 (L constraint): PASSED\n");
}

/* Test 27: 32-bit MOV pseudo immediate constraint */
व्योम test_mov_imm32_constraint(व्योम)
{
    uint32_t y;

    यंत्र("mov %w0, %1" : "=r"(y) : "M"(0x1234));
    निश्चित(y == 0x1234);
    म_लिखो("Test 27 (M constraint): PASSED\n");
}

/* Test 28: 64-bit MOV pseudo immediate constraint */
व्योम test_mov_imm64_constraint(व्योम)
{
    uint64_t y;

    यंत्र("mov %0, %1" : "=r"(y) : "N"(0x12340000ULL));
    निश्चित(y == 0x12340000ULL);
    म_लिखो("Test 28 (N constraint): PASSED\n");
}

/* Test 29: x FP/SIMD register constraint */
व्योम test_x_constraint_fp(व्योम)
{
    द्विगुन x = 6.25;
    द्विगुन y;

    यंत्र("ldr %d0, [%1]" : "=x"(y) : "r"(&x));
    निश्चित(y == x);
    म_लिखो("Test 29 (x constraint): PASSED\n");
}

/* Test 30: y FP/SIMD register constraint */
व्योम test_y_constraint_fp(व्योम)
{
    द्विगुन x = 7.25;
    द्विगुन y;

    यंत्र("ldr %d0, [%1]" : "=y"(y) : "r"(&x));
    निश्चित(y == x);
    म_लिखो("Test 30 (y constraint): PASSED\n");
}

/* Test 31: Q memory constraint */
अटल पूर्णांक arm64_q_load(पूर्णांक *ptr)
{
    पूर्णांक y;

    यंत्र("ldr %w0, %1" : "=r"(y) : "Q"(*ptr));
    वापस y;
}

व्योम test_q_memory_constraint(व्योम)
{
    पूर्णांक x = 91;
    निश्चित(arm64_q_load(&x) == 91);
    म_लिखो("Test 31 (Q constraint): PASSED\n");
}

/* Test 32: Ump pair-memory constraint */
व्योम test_ump_memory_constraint(व्योम)
{
    काष्ठा pair64 pair = { 0x1122334455667788ULL, 0x99aabbccddeeff00ULL };
    uint64_t a;
    uint64_t b;

    यंत्र("ldp %0, %1, %2" : "=r"(a), "=r"(b) : "Ump"(pair));
    निश्चित(a == pair.a);
    निश्चित(b == pair.b);
    म_लिखो("Test 32 (Ump constraint): PASSED\n");
}

पूर्णांक मुख्य(व्योम)
{
    म_लिखो("ARM64 Extended Inline Assembly Tests\n");
    test_basic_output();
    test_निवेश_operand();
    test_read_write_operand();
    test_memory_load();
    test_memory_store();
    test_ढेर_memory_operand();
    test_प्रतीक_memory_operand();
    test_clobber_list();
    test_multiple_outputs();
    test_constraint_reference();
    test_early_clobber();
    test_w_register();
    test_immediate_i_constraint();
    test_general_operand_constraint();
    test_multiple_io();
    test_regvar_preservation();
    test_complex_arithmetic();
    test_named_operand();
    test_memory_clobber();
    test_cc_clobber();
    test_large_immediate();
    test_bitwise_ops();
    test_register_shift_operands();
    test_ror_immediate();
    test_fp_register_operand();
    test_zero_constraint();
    test_logical_imm32_constraint();
    test_logical_imm64_constraint();
    test_mov_imm32_constraint();
    test_mov_imm64_constraint();
    test_x_constraint_fp();
    test_y_constraint_fp();
    test_q_memory_constraint();
    test_ump_memory_constraint();
    test_symbolic_address_constraint_compile_only();
    म_लिखो("ARM64 Extended Inline Assembly Tests PASSED!\n");
    वापस 0;
}
