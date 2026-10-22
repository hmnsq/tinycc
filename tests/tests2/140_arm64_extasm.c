/*
 * ARM64 Extended Inline Assembly Tests
 * Tests for GCC-style extended inline assembly with operands, constraints, and clobbers
 */

#شامل <stdio.h>
#شامل <stdint.h>
#شامل <assert.h>

ساخت pair64 {
    uint64_t a;
    uint64_t b;
};

ساکن صحیح arm64_علامت_ہدف(خالی)
{
    واپس 7;
}

ساکن خالی test_symbolic_پتہ_constraint_compile_only(خالی)
{
    asm متلون("" : : "S"(arm64_علامت_ہدف));
}

/* Test 1: Basic output operand */
خالی test_basic_output(خالی)
{
    صحیح x;
    asm("mov %0, #42" : "=r"(x));
    أكد(x == 42);
    لکھو("Test 1 (basic output): PASSED\n");
}

/* Test 2: Input operand */
خالی test_داخلہ_عملیہ(خالی)
{
    صحیح x = 10;
    صحیح y;
    asm("add %0, %1, #5" : "=r"(y) : "r"(x));
    أكد(y == 15);
    لکھو("Test 2 (input operand): PASSED\n");
}

/* Test 3: Read-write operand */
خالی test_read_write_عملیہ(خالی)
{
    صحیح x = 10;
    asm("add %0, %0, #1" : "+r"(x));
    أكد(x == 11);
    لکھو("Test 3 (read-write operand): PASSED\n");
}

/* Test 4: Memory operand - load */
خالی test_حافظہ_بھرو(خالی)
{
    صحیح x = 42;
    صحیح y;
    asm("ldr %w0, [%1]" : "=r"(y) : "r"(&x));
    أكد(y == 42);
    لکھو("Test 4 (memory load): PASSED\n");
}

/* Test 5: Memory operand - store */
خالی test_حافظہ_store(خالی)
{
    صحیح x;
    صحیح val = 123;
    asm("str %w1, [%0]" : : "r"(&x), "r"(val));
    أكد(x == 123);
    لکھو("Test 5 (memory store): PASSED\n");
}

/* Test 5a: Stack memory operand with frame-relative offset */
خالی test_ڈھیر_حافظہ_عملیہ(خالی)
{
    طویل x = 0;
    طویل val = 321;

    asm متلون("str %0, %1" : : "r"(val), "m"(x));
    أكد(x == 321);
    لکھو("Test 5a (stack memory operand): PASSED\n");
}

/* Test 5b: Symbol memory operand */
ساکن طویل arm64_علامت_mem;

خالی test_علامت_حافظہ_عملیہ(خالی)
{
    طویل val = 654;

    arm64_علامت_mem = 0;
    asm متلون("str %0, %1" : : "r"(val), "m"(arm64_علامت_mem));
    أكد(arm64_علامت_mem == 654);
    لکھو("Test 5b (symbol memory operand): PASSED\n");
}

/* Test 6: Clobber list */
خالی test_clobber_list(خالی)
{
    صحیح x = 10;
    صحیح y = 20;
    صحیح نتیجہ;
    asm("add %0, %1, %2" 
        : "=r"(نتیجہ)
        : "r"(x), "r"(y)
        : "cc");
    أكد(نتیجہ == 30);
    لکھو("Test 6 (clobber list): PASSED\n");
}

/* Test 7: Multiple outputs */
خالی test_مضرب_outputs(خالی)
{
    صحیح a, b;
    asm("mov %0, #1; mov %1, #2" 
        : "=r"(a), "=r"(b));
    أكد(a == 1 && b == 2);
    لکھو("Test 7 (multiple outputs): PASSED\n");
}

/* Test 8: Constraint reference */
خالی test_constraint_reference(خالی)
{
    صحیح x = 10;
    صحیح y;
    asm("add %0, %1, #5" : "=r"(y) : "0"(x));
    أكد(y == 15);
    لکھو("Test 8 (constraint reference): PASSED\n");
}

/* Test 9: Early clobber */
خالی test_early_clobber(خالی)
{
    صحیح x = 10;
    صحیح y;
    asm("mov %0, #42" : "=&r"(y) : "r"(x));
    أكد(y == 42);
    لکھو("Test 9 (early clobber): PASSED\n");
}

/* Test 10: 32-bit register modifier */
خالی test_w_رجسٹر(خالی)
{
    uint32_t x = 100;
    uint32_t y;
    asm("add %w0, %w1, #50" : "=r"(y) : "r"(x));
    أكد(y == 150);
    لکھو("Test 10 (w register modifier): PASSED\n");
}

/* Test 11: Immediate constraint 'I' (12-bit immediate) */
خالی test_فوری_i_constraint(خالی)
{
    صحیح x = 100;
    صحیح y;
    asm("add %0, %1, #200" : "=r"(y) : "r"(x), "I"(200));
    أكد(y == 300);
    لکھو("Test 11 (immediate I constraint): PASSED\n");
}

/* Test 12: Register constraint */
خالی test_general_عملیہ_constraint(خالی)
{
    صحیح x = 50;
    صحیح y;
    asm("add %0, %1, #10" : "=r"(y) : "r"(x));
    أكد(y == 60);
    لکھو("Test 12 (general operand constraint): PASSED\n");
}

/* Test 13: Multiple inputs and outputs */
خالی test_مضرب_io(خالی)
{
    صحیح a = 10, b = 20;
    صحیح مجموع, diff;
    asm("add %0, %1, %2" : "=r"(مجموع) : "r"(a), "r"(b));
    asm("sub %0, %1, %2" : "=r"(diff) : "r"(a), "r"(b));
    أكد(مجموع == 30 && diff == -10);
    لکھو("Test 13 (multiple IO): PASSED\n");
}

/* Test 14: Register variable preservation */
خالی test_regvar_preservation(خالی)
{
    اندراج uint64_t keep asm("x19") = 0x123456789abcdef0ULL;
    uint64_t برآمد;

    asm متلون("mov x19, #7; add %0, x19, #1"
        : "=r"(برآمد)
        :
        : "x19");
    أكد(keep == 0x123456789abcdef0ULL);
    أكد(برآمد == 8);
    لکھو("Test 14 (regvar preservation): PASSED\n");
}

/* Test 15: Complex arithmetic */
خالی test_complex_arithmetic(خالی)
{
    صحیح a = 100, b = 50, c = 25;
    صحیح نتیجہ;
    asm("add %0, %1, %2; sub %0, %0, %3"
        : "=&r"(نتیجہ)
        : "r"(a), "r"(b), "r"(c));
    أكد(نتیجہ == 125);
    لکھو("Test 15 (complex arithmetic): PASSED\n");
}

/* Test 16: Named operand (GCC extension) */
خالی test_named_عملیہ(خالی)
{
    صحیح داخلہ = 10;
    صحیح output;
    asm("add %[out], %[in], #5"
        : [برآمد] "=r"(output)
        : [اندر] "r"(داخلہ));
    أكد(output == 15);
    لکھو("Test 16 (named operand): PASSED\n");
}

/* Test 17: Memory clobber */
خالی test_حافظہ_clobber(خالی)
{
    صحیح x = 10;
    asm متلون("" : : : "memory");
    أكد(x == 10);
    لکھو("Test 17 (memory clobber): PASSED\n");
}

/* Test 18: Condition flags clobber */
خالی test_cc_clobber(خالی)
{
    صحیح x = 100;
    صحیح y;
    asm("adds %0, %1, #0" : "=r"(y) : "r"(x) : "cc");
    أكد(y == 100);
    لکھو("Test 18 (cc clobber): PASSED\n");
}

/* Test 19: Large immediate with movz/movk */
خالی test_large_فوری(خالی)
{
    uint64_t val;
    asm("movz %0, #0x1234, lsl #16; movk %0, #0x5678" : "=r"(val));
    أكد(val == 0x12345678ULL);
    لکھو("Test 19 (large immediate): PASSED\n");
}

/* Test 20: Bitwise operations */
خالی test_bitwise_ops(خالی)
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

    أكد(andv == (a & b));
    أكد(orv == (a | b));
    أكد(xorv == (a ^ b));
    أكد(imm_and == 0xff00ff00ff00ff00ULL);
    لکھو("Test 20 (bitwise ops): PASSED\n");
}

/* Test 21: Register shift operands */
خالی test_رجسٹر_سرکاؤ_operands(خالی)
{
    uint64_t val = 3;
    uint64_t amount = 4;
    uint64_t shifted;
    uint64_t rotated;

    asm("lsl %0, %1, %2" : "=r"(shifted) : "r"(val), "r"(amount));
    asm("ror %0, %1, %2" : "=r"(rotated)
        : "r"(0x0123456789abcdefULL), "r"(8ULL));
    أكد(shifted == 48);
    أكد(rotated == 0xef0123456789abcdULL);
    لکھو("Test 21 (register shifts): PASSED\n");
}

/* Test 22: ROR immediate alias of EXTR */
خالی test_ror_فوری(خالی)
{
    uint64_t rotated;

    asm("ror %0, %1, #8" : "=r"(rotated) : "r"(0x0123456789abcdefULL));
    أكد(rotated == 0xef0123456789abcdULL);
    لکھو("Test 22 (ror immediate): PASSED\n");
}

/* Test 23: FP/SIMD register constraint and modifier */
خالی test_fp_رجسٹر_عملیہ(خالی)
{
    دوہرا x = 3.5;
    دوہرا y;

    asm("ldr %d0, [%1]" : "=w"(y) : "r"(&x));
    أكد(y == x);
    لکھو("Test 23 (fp register operand): PASSED\n");
}

/* Test 24: Zero constraint */
خالی test_zero_constraint(خالی)
{
    uint64_t x = 41;
    uint64_t y;

    asm("add %0, %1, %x2" : "=r"(y) : "r"(x), "Z"(0));
    أكد(y == x);
    لکھو("Test 24 (Z constraint): PASSED\n");
}

/* Test 25: 32-bit logical immediate constraint */
خالی test_logical_imm32_constraint(خالی)
{
    uint32_t y;

    asm("orr %w0, wzr, %1" : "=r"(y) : "K"(0xff));
    أكد(y == 0xff);
    لکھو("Test 25 (K constraint): PASSED\n");
}

/* Test 26: 64-bit logical immediate constraint */
خالی test_logical_imm64_constraint(خالی)
{
    uint64_t y;

    asm("orr %0, xzr, %1" : "=r"(y) : "L"(0xff00ff00ff00ff00ULL));
    أكد(y == 0xff00ff00ff00ff00ULL);
    لکھو("Test 26 (L constraint): PASSED\n");
}

/* Test 27: 32-bit MOV pseudo immediate constraint */
خالی test_mov_imm32_constraint(خالی)
{
    uint32_t y;

    asm("mov %w0, %1" : "=r"(y) : "M"(0x1234));
    أكد(y == 0x1234);
    لکھو("Test 27 (M constraint): PASSED\n");
}

/* Test 28: 64-bit MOV pseudo immediate constraint */
خالی test_mov_imm64_constraint(خالی)
{
    uint64_t y;

    asm("mov %0, %1" : "=r"(y) : "N"(0x12340000ULL));
    أكد(y == 0x12340000ULL);
    لکھو("Test 28 (N constraint): PASSED\n");
}

/* Test 29: x FP/SIMD register constraint */
خالی test_x_constraint_fp(خالی)
{
    دوہرا x = 6.25;
    دوہرا y;

    asm("ldr %d0, [%1]" : "=x"(y) : "r"(&x));
    أكد(y == x);
    لکھو("Test 29 (x constraint): PASSED\n");
}

/* Test 30: y FP/SIMD register constraint */
خالی test_y_constraint_fp(خالی)
{
    دوہرا x = 7.25;
    دوہرا y;

    asm("ldr %d0, [%1]" : "=y"(y) : "r"(&x));
    أكد(y == x);
    لکھو("Test 30 (y constraint): PASSED\n");
}

/* Test 31: Q memory constraint */
ساکن صحیح arm64_q_بھرو(صحیح *ptr)
{
    صحیح y;

    asm("ldr %w0, %1" : "=r"(y) : "Q"(*ptr));
    واپس y;
}

خالی test_q_حافظہ_constraint(خالی)
{
    صحیح x = 91;
    أكد(arm64_q_بھرو(&x) == 91);
    لکھو("Test 31 (Q constraint): PASSED\n");
}

/* Test 32: Ump pair-memory constraint */
خالی test_ump_حافظہ_constraint(خالی)
{
    ساخت pair64 pair = { 0x1122334455667788ULL, 0x99aabbccddeeff00ULL };
    uint64_t a;
    uint64_t b;

    asm("ldp %0, %1, %2" : "=r"(a), "=r"(b) : "Ump"(pair));
    أكد(a == pair.a);
    أكد(b == pair.b);
    لکھو("Test 32 (Ump constraint): PASSED\n");
}

صحیح مین(خالی)
{
    لکھو("ARM64 Extended Inline Assembly Tests\n");
    test_basic_output();
    test_داخلہ_عملیہ();
    test_read_write_عملیہ();
    test_حافظہ_بھرو();
    test_حافظہ_store();
    test_ڈھیر_حافظہ_عملیہ();
    test_علامت_حافظہ_عملیہ();
    test_clobber_list();
    test_مضرب_outputs();
    test_constraint_reference();
    test_early_clobber();
    test_w_رجسٹر();
    test_فوری_i_constraint();
    test_general_عملیہ_constraint();
    test_مضرب_io();
    test_regvar_preservation();
    test_complex_arithmetic();
    test_named_عملیہ();
    test_حافظہ_clobber();
    test_cc_clobber();
    test_large_فوری();
    test_bitwise_ops();
    test_رجسٹر_سرکاؤ_operands();
    test_ror_فوری();
    test_fp_رجسٹر_عملیہ();
    test_zero_constraint();
    test_logical_imm32_constraint();
    test_logical_imm64_constraint();
    test_mov_imm32_constraint();
    test_mov_imm64_constraint();
    test_x_constraint_fp();
    test_y_constraint_fp();
    test_q_حافظہ_constraint();
    test_ump_حافظہ_constraint();
    test_symbolic_پتہ_constraint_compile_only();
    لکھو("ARM64 Extended Inline Assembly Tests PASSED!\n");
    واپس 0;
}
