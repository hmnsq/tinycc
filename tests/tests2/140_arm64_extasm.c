/*
 * ARM64 Extended Inline Assembly Tests
 * Tests for GCC-style extended inline assembly with operands, constraints, and clobbers
 */

#అన్తర్భావ <stdio.h>
#అన్తర్భావ <stdint.h>
#అన్తర్భావ <assert.h>

నిర్మాణం pair64 {
    uint64_t a;
    uint64_t b;
};

స్థిర పూర్ణాంకం arm64_చిహ్నం_లక్ష్యం(శూన్య)
{
    తిరిగి 7;
}

స్థిర శూన్య test_symbolic_చిరునామా_constraint_compile_only(శూన్య)
{
    asm అస్థిర("" : : "S"(arm64_చిహ్నం_లక్ష్యం));
}

/* Test 1: Basic output operand */
శూన్య test_basic_output(శూన్య)
{
    పూర్ణాంకం x;
    asm("mov %0, #42" : "=r"(x));
    ప్రతిజ్ఞా(x == 42);
    రాయి("Test 1 (basic output): PASSED\n");
}

/* Test 2: Input operand */
శూన్య test_ఆదానం_నిర్వాహ్యం(శూన్య)
{
    పూర్ణాంకం x = 10;
    పూర్ణాంకం y;
    asm("add %0, %1, #5" : "=r"(y) : "r"(x));
    ప్రతిజ్ఞా(y == 15);
    రాయి("Test 2 (input operand): PASSED\n");
}

/* Test 3: Read-write operand */
శూన్య test_read_write_నిర్వాహ్యం(శూన్య)
{
    పూర్ణాంకం x = 10;
    asm("add %0, %0, #1" : "+r"(x));
    ప్రతిజ్ఞా(x == 11);
    రాయి("Test 3 (read-write operand): PASSED\n");
}

/* Test 4: Memory operand - load */
శూన్య test_జ్ఞాపకం_ఎక్కించు(శూన్య)
{
    పూర్ణాంకం x = 42;
    పూర్ణాంకం y;
    asm("ldr %w0, [%1]" : "=r"(y) : "r"(&x));
    ప్రతిజ్ఞా(y == 42);
    రాయి("Test 4 (memory load): PASSED\n");
}

/* Test 5: Memory operand - store */
శూన్య test_జ్ఞాపకం_store(శూన్య)
{
    పూర్ణాంకం x;
    పూర్ణాంకం val = 123;
    asm("str %w1, [%0]" : : "r"(&x), "r"(val));
    ప్రతిజ్ఞా(x == 123);
    రాయి("Test 5 (memory store): PASSED\n");
}

/* Test 5a: Stack memory operand with frame-relative offset */
శూన్య test_దొంతర_జ్ఞాపకం_నిర్వాహ్యం(శూన్య)
{
    దీర్ఘ x = 0;
    దీర్ఘ val = 321;

    asm అస్థిర("str %0, %1" : : "r"(val), "m"(x));
    ప్రతిజ్ఞా(x == 321);
    రాయి("Test 5a (stack memory operand): PASSED\n");
}

/* Test 5b: Symbol memory operand */
స్థిర దీర్ఘ arm64_చిహ్నం_mem;

శూన్య test_చిహ్నం_జ్ఞాపకం_నిర్వాహ్యం(శూన్య)
{
    దీర్ఘ val = 654;

    arm64_చిహ్నం_mem = 0;
    asm అస్థిర("str %0, %1" : : "r"(val), "m"(arm64_చిహ్నం_mem));
    ప్రతిజ్ఞా(arm64_చిహ్నం_mem == 654);
    రాయి("Test 5b (symbol memory operand): PASSED\n");
}

/* Test 6: Clobber list */
శూన్య test_clobber_list(శూన్య)
{
    పూర్ణాంకం x = 10;
    పూర్ణాంకం y = 20;
    పూర్ణాంకం ఫలితం;
    asm("add %0, %1, %2" 
        : "=r"(ఫలితం)
        : "r"(x), "r"(y)
        : "cc");
    ప్రతిజ్ఞా(ఫలితం == 30);
    రాయి("Test 6 (clobber list): PASSED\n");
}

/* Test 7: Multiple outputs */
శూన్య test_గుణిజం_outputs(శూన్య)
{
    పూర్ణాంకం a, b;
    asm("mov %0, #1; mov %1, #2" 
        : "=r"(a), "=r"(b));
    ప్రతిజ్ఞా(a == 1 && b == 2);
    రాయి("Test 7 (multiple outputs): PASSED\n");
}

/* Test 8: Constraint reference */
శూన్య test_constraint_reference(శూన్య)
{
    పూర్ణాంకం x = 10;
    పూర్ణాంకం y;
    asm("add %0, %1, #5" : "=r"(y) : "0"(x));
    ప్రతిజ్ఞా(y == 15);
    రాయి("Test 8 (constraint reference): PASSED\n");
}

/* Test 9: Early clobber */
శూన్య test_early_clobber(శూన్య)
{
    పూర్ణాంకం x = 10;
    పూర్ణాంకం y;
    asm("mov %0, #42" : "=&r"(y) : "r"(x));
    ప్రతిజ్ఞా(y == 42);
    రాయి("Test 9 (early clobber): PASSED\n");
}

/* Test 10: 32-bit register modifier */
శూన్య test_w_రిజిస్టరు(శూన్య)
{
    uint32_t x = 100;
    uint32_t y;
    asm("add %w0, %w1, #50" : "=r"(y) : "r"(x));
    ప్రతిజ్ఞా(y == 150);
    రాయి("Test 10 (w register modifier): PASSED\n");
}

/* Test 11: Immediate constraint 'I' (12-bit immediate) */
శూన్య test_తక్షణ_i_constraint(శూన్య)
{
    పూర్ణాంకం x = 100;
    పూర్ణాంకం y;
    asm("add %0, %1, #200" : "=r"(y) : "r"(x), "I"(200));
    ప్రతిజ్ఞా(y == 300);
    రాయి("Test 11 (immediate I constraint): PASSED\n");
}

/* Test 12: Register constraint */
శూన్య test_general_నిర్వాహ్యం_constraint(శూన్య)
{
    పూర్ణాంకం x = 50;
    పూర్ణాంకం y;
    asm("add %0, %1, #10" : "=r"(y) : "r"(x));
    ప్రతిజ్ఞా(y == 60);
    రాయి("Test 12 (general operand constraint): PASSED\n");
}

/* Test 13: Multiple inputs and outputs */
శూన్య test_గుణిజం_io(శూన్య)
{
    పూర్ణాంకం a = 10, b = 20;
    పూర్ణాంకం కూడిక, diff;
    asm("add %0, %1, %2" : "=r"(కూడిక) : "r"(a), "r"(b));
    asm("sub %0, %1, %2" : "=r"(diff) : "r"(a), "r"(b));
    ప్రతిజ్ఞా(కూడిక == 30 && diff == -10);
    రాయి("Test 13 (multiple IO): PASSED\n");
}

/* Test 14: Register variable preservation */
శూన్య test_regvar_preservation(శూన్య)
{
    నమోదు uint64_t keep asm("x19") = 0x123456789abcdef0ULL;
    uint64_t బహిర్గతం;

    asm అస్థిర("mov x19, #7; add %0, x19, #1"
        : "=r"(బహిర్గతం)
        :
        : "x19");
    ప్రతిజ్ఞా(keep == 0x123456789abcdef0ULL);
    ప్రతిజ్ఞా(బహిర్గతం == 8);
    రాయి("Test 14 (regvar preservation): PASSED\n");
}

/* Test 15: Complex arithmetic */
శూన్య test_complex_arithmetic(శూన్య)
{
    పూర్ణాంకం a = 100, b = 50, c = 25;
    పూర్ణాంకం ఫలితం;
    asm("add %0, %1, %2; sub %0, %0, %3"
        : "=&r"(ఫలితం)
        : "r"(a), "r"(b), "r"(c));
    ప్రతిజ్ఞా(ఫలితం == 125);
    రాయి("Test 15 (complex arithmetic): PASSED\n");
}

/* Test 16: Named operand (GCC extension) */
శూన్య test_named_నిర్వాహ్యం(శూన్య)
{
    పూర్ణాంకం ఆదానం = 10;
    పూర్ణాంకం output;
    asm("add %[out], %[in], #5"
        : [బహిర్గతం] "=r"(output)
        : [లోపల] "r"(ఆదానం));
    ప్రతిజ్ఞా(output == 15);
    రాయి("Test 16 (named operand): PASSED\n");
}

/* Test 17: Memory clobber */
శూన్య test_జ్ఞాపకం_clobber(శూన్య)
{
    పూర్ణాంకం x = 10;
    asm అస్థిర("" : : : "memory");
    ప్రతిజ్ఞా(x == 10);
    రాయి("Test 17 (memory clobber): PASSED\n");
}

/* Test 18: Condition flags clobber */
శూన్య test_cc_clobber(శూన్య)
{
    పూర్ణాంకం x = 100;
    పూర్ణాంకం y;
    asm("adds %0, %1, #0" : "=r"(y) : "r"(x) : "cc");
    ప్రతిజ్ఞా(y == 100);
    రాయి("Test 18 (cc clobber): PASSED\n");
}

/* Test 19: Large immediate with movz/movk */
శూన్య test_large_తక్షణ(శూన్య)
{
    uint64_t val;
    asm("movz %0, #0x1234, lsl #16; movk %0, #0x5678" : "=r"(val));
    ప్రతిజ్ఞా(val == 0x12345678ULL);
    రాయి("Test 19 (large immediate): PASSED\n");
}

/* Test 20: Bitwise operations */
శూన్య test_bitwise_ops(శూన్య)
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

    ప్రతిజ్ఞా(andv == (a & b));
    ప్రతిజ్ఞా(orv == (a | b));
    ప్రతిజ్ఞా(xorv == (a ^ b));
    ప్రతిజ్ఞా(imm_and == 0xff00ff00ff00ff00ULL);
    రాయి("Test 20 (bitwise ops): PASSED\n");
}

/* Test 21: Register shift operands */
శూన్య test_రిజిస్టరు_జరుపు_operands(శూన్య)
{
    uint64_t val = 3;
    uint64_t amount = 4;
    uint64_t shifted;
    uint64_t rotated;

    asm("lsl %0, %1, %2" : "=r"(shifted) : "r"(val), "r"(amount));
    asm("ror %0, %1, %2" : "=r"(rotated)
        : "r"(0x0123456789abcdefULL), "r"(8ULL));
    ప్రతిజ్ఞా(shifted == 48);
    ప్రతిజ్ఞా(rotated == 0xef0123456789abcdULL);
    రాయి("Test 21 (register shifts): PASSED\n");
}

/* Test 22: ROR immediate alias of EXTR */
శూన్య test_ror_తక్షణ(శూన్య)
{
    uint64_t rotated;

    asm("ror %0, %1, #8" : "=r"(rotated) : "r"(0x0123456789abcdefULL));
    ప్రతిజ్ఞా(rotated == 0xef0123456789abcdULL);
    రాయి("Test 22 (ror immediate): PASSED\n");
}

/* Test 23: FP/SIMD register constraint and modifier */
శూన్య test_fp_రిజిస్టరు_నిర్వాహ్యం(శూన్య)
{
    ద్విగుణ x = 3.5;
    ద్విగుణ y;

    asm("ldr %d0, [%1]" : "=w"(y) : "r"(&x));
    ప్రతిజ్ఞా(y == x);
    రాయి("Test 23 (fp register operand): PASSED\n");
}

/* Test 24: Zero constraint */
శూన్య test_zero_constraint(శూన్య)
{
    uint64_t x = 41;
    uint64_t y;

    asm("add %0, %1, %x2" : "=r"(y) : "r"(x), "Z"(0));
    ప్రతిజ్ఞా(y == x);
    రాయి("Test 24 (Z constraint): PASSED\n");
}

/* Test 25: 32-bit logical immediate constraint */
శూన్య test_logical_imm32_constraint(శూన్య)
{
    uint32_t y;

    asm("orr %w0, wzr, %1" : "=r"(y) : "K"(0xff));
    ప్రతిజ్ఞా(y == 0xff);
    రాయి("Test 25 (K constraint): PASSED\n");
}

/* Test 26: 64-bit logical immediate constraint */
శూన్య test_logical_imm64_constraint(శూన్య)
{
    uint64_t y;

    asm("orr %0, xzr, %1" : "=r"(y) : "L"(0xff00ff00ff00ff00ULL));
    ప్రతిజ్ఞా(y == 0xff00ff00ff00ff00ULL);
    రాయి("Test 26 (L constraint): PASSED\n");
}

/* Test 27: 32-bit MOV pseudo immediate constraint */
శూన్య test_mov_imm32_constraint(శూన్య)
{
    uint32_t y;

    asm("mov %w0, %1" : "=r"(y) : "M"(0x1234));
    ప్రతిజ్ఞా(y == 0x1234);
    రాయి("Test 27 (M constraint): PASSED\n");
}

/* Test 28: 64-bit MOV pseudo immediate constraint */
శూన్య test_mov_imm64_constraint(శూన్య)
{
    uint64_t y;

    asm("mov %0, %1" : "=r"(y) : "N"(0x12340000ULL));
    ప్రతిజ్ఞా(y == 0x12340000ULL);
    రాయి("Test 28 (N constraint): PASSED\n");
}

/* Test 29: x FP/SIMD register constraint */
శూన్య test_x_constraint_fp(శూన్య)
{
    ద్విగుణ x = 6.25;
    ద్విగుణ y;

    asm("ldr %d0, [%1]" : "=x"(y) : "r"(&x));
    ప్రతిజ్ఞా(y == x);
    రాయి("Test 29 (x constraint): PASSED\n");
}

/* Test 30: y FP/SIMD register constraint */
శూన్య test_y_constraint_fp(శూన్య)
{
    ద్విగుణ x = 7.25;
    ద్విగుణ y;

    asm("ldr %d0, [%1]" : "=y"(y) : "r"(&x));
    ప్రతిజ్ఞా(y == x);
    రాయి("Test 30 (y constraint): PASSED\n");
}

/* Test 31: Q memory constraint */
స్థిర పూర్ణాంకం arm64_q_ఎక్కించు(పూర్ణాంకం *ptr)
{
    పూర్ణాంకం y;

    asm("ldr %w0, %1" : "=r"(y) : "Q"(*ptr));
    తిరిగి y;
}

శూన్య test_q_జ్ఞాపకం_constraint(శూన్య)
{
    పూర్ణాంకం x = 91;
    ప్రతిజ్ఞా(arm64_q_ఎక్కించు(&x) == 91);
    రాయి("Test 31 (Q constraint): PASSED\n");
}

/* Test 32: Ump pair-memory constraint */
శూన్య test_ump_జ్ఞాపకం_constraint(శూన్య)
{
    నిర్మాణం pair64 pair = { 0x1122334455667788ULL, 0x99aabbccddeeff00ULL };
    uint64_t a;
    uint64_t b;

    asm("ldp %0, %1, %2" : "=r"(a), "=r"(b) : "Ump"(pair));
    ప్రతిజ్ఞా(a == pair.a);
    ప్రతిజ్ఞా(b == pair.b);
    రాయి("Test 32 (Ump constraint): PASSED\n");
}

పూర్ణాంకం ప్రధాన(శూన్య)
{
    రాయి("ARM64 Extended Inline Assembly Tests\n");
    test_basic_output();
    test_ఆదానం_నిర్వాహ్యం();
    test_read_write_నిర్వాహ్యం();
    test_జ్ఞాపకం_ఎక్కించు();
    test_జ్ఞాపకం_store();
    test_దొంతర_జ్ఞాపకం_నిర్వాహ్యం();
    test_చిహ్నం_జ్ఞాపకం_నిర్వాహ్యం();
    test_clobber_list();
    test_గుణిజం_outputs();
    test_constraint_reference();
    test_early_clobber();
    test_w_రిజిస్టరు();
    test_తక్షణ_i_constraint();
    test_general_నిర్వాహ్యం_constraint();
    test_గుణిజం_io();
    test_regvar_preservation();
    test_complex_arithmetic();
    test_named_నిర్వాహ్యం();
    test_జ్ఞాపకం_clobber();
    test_cc_clobber();
    test_large_తక్షణ();
    test_bitwise_ops();
    test_రిజిస్టరు_జరుపు_operands();
    test_ror_తక్షణ();
    test_fp_రిజిస్టరు_నిర్వాహ్యం();
    test_zero_constraint();
    test_logical_imm32_constraint();
    test_logical_imm64_constraint();
    test_mov_imm32_constraint();
    test_mov_imm64_constraint();
    test_x_constraint_fp();
    test_y_constraint_fp();
    test_q_జ్ఞాపకం_constraint();
    test_ump_జ్ఞాపకం_constraint();
    test_symbolic_చిరునామా_constraint_compile_only();
    రాయి("ARM64 Extended Inline Assembly Tests PASSED!\n");
    తిరిగి 0;
}
