/* ARM64 instruction encoding verification test.
   Exercises shift-by-immediate, load/store addressing modes,
   conditional branches, and system register access. */

#شامل <stdio.h>
#شامل <stdint.h>

/* ---- shift-by-immediate helpers ---- */

ساکن uint32_t lsl32(uint32_t x, صحیح n) { واپس x << n; }
ساکن uint32_t lsr32(uint32_t x, صحیح n) { واپس x >> n; }
ساکن int32_t  asr32(int32_t  x, صحیح n) { واپس x >> n; }
ساکن uint64_t lsl64(uint64_t x, صحیح n) { واپس x << n; }
ساکن uint64_t lsr64(uint64_t x, صحیح n) { واپس x >> n; }
ساکن int64_t  asr64(int64_t  x, صحیح n) { واپس x >> n; }

ساکن خالی test_shifts(خالی)
{
    لکھو("shift-imm:\n");
    لکھو("%x\n", lsl32(1, 0));
    لکھو("%x\n", lsl32(1, 15));
    لکھو("%x\n", lsl32(1, 31));
    لکھو("%x\n", lsr32(0x80000000U, 31));
    لکھو("%x\n", lsr32(0x80000000U, 16));
    لکھو("%x\n", asr32(-1, 1));
    لکھو("%x\n", asr32(-256, 4));
    لکھو("%llx\n", (غیرعلامتی طویل طویل)lsl64(1ULL, 0));
    لکھو("%llx\n", (غیرعلامتی طویل طویل)lsl64(1ULL, 32));
    لکھو("%llx\n", (غیرعلامتی طویل طویل)lsl64(1ULL, 63));
    لکھو("%llx\n", (غیرعلامتی طویل طویل)lsr64(0x8000000000000000ULL, 63));
    لکھو("%llx\n", (غیرعلامتی طویل طویل)asr64(-1LL, 1));
    لکھو("%llx\n", (غیرعلامتی طویل طویل)asr64(-256LL, 4));
}

/* ---- load/store with various addressing modes ---- */

ساکن خالی test_ldr_str(خالی)
{
    int64_t buf[4] = { 0x1122334455667788LL, 0x99AABBCCDDEEFF00LL,
                       0x0F1E2D3C4B5A6978LL, 0x0000000000000001LL };
    int64_t val;
    int32_t wval;
    int64_t *p;

    لکھو("ldr-str:\n");

    /* LDR X, [Xn, #offset] */
    val = buf[0];
    لکھو("%llx\n", (غیرعلامتی طویل طویل)val);
    val = buf[1];
    لکھو("%llx\n", (غیرعلامتی طویل طویل)val);

    /* LDR W, [Xn, #offset] (32-bit load) */
    wval = *(int32_t*)&buf[0];
    لکھو("%x\n", (غیرعلامتی)wval);

    /* Pre-indexed: store pointer, modify */
    p = &buf[0];
    val = *(p + 2);
    لکھو("%llx\n", (غیرعلامتی طویل طویل)val);

    /* Post-indexed simulation via pointer arithmetic */
    p = &buf[0];
    val = *p;
    p++;
    لکھو("%llx %llx\n", (غیرعلامتی طویل طویل)val,
           (غیرعلامتی طویل طویل)*p);
}

/* ---- STP/LDP (store/load pair) ---- */

ساکن خالی test_ldp_stp(خالی)
{
    int64_t src[2] = { 0xAAAABBBBCCCCDDDDLL, 0x1111222233334444LL };
    int64_t dst[2];

    /* The compiler should use stp/ldp for this */
    dst[0] = src[0];
    dst[1] = src[1];

    لکھو("ldp-stp:\n");
    لکھو("%llx %llx\n",
           (غیرعلامتی طویل طویل)dst[0],
           (غیرعلامتی طویل طویل)dst[1]);
}

/* ---- CBZ / CBNZ via C patterns ---- */

ساکن ثابت حرف *cbz_test(صحیح x)
{
    اگر (x == 0)
        واپس "zero";
    واپس "nonzero";
}

ساکن ثابت حرف *cbnz_test(صحیح x)
{
    اگر (x != 0)
        واپس "nonzero";
    واپس "zero";
}

ساکن خالی test_cond_branches(خالی)
{
    لکھو("cbz-cbnz:\n");
    لکھو("%s\n", cbz_test(0));
    لکھو("%s\n", cbz_test(42));
    لکھو("%s\n", cbnz_test(0));
    لکھو("%s\n", cbnz_test(42));
}

/* ---- conditional compare patterns (CCMP/CCMN) ---- */

ساکن صحیح cond_select(صحیح a, صحیح b)
{
    /* TCC should generate csel or equivalent */
    واپس a > b ? a : b;
}

ساکن خالی test_cond_select(خالی)
{
    لکھو("csel:\n");
    لکھو("%d\n", cond_select(5, 10));
    لکھو("%d\n", cond_select(10, 5));
    لکھو("%d\n", cond_select(0, 0));
    لکھو("%d\n", cond_select(-1, 1));
}

/* ---- MRS/MSR system registers (FPCR/FPSR) ---- */

ساکن خالی test_sysregs(خالی)
{
    غیرعلامتی صحیح fpcr, fpsr;

    لکھو("sysregs:\n");

    /* Read FPCR */
    __asm__ متلون ("mrs %0, fpcr" : "=r"(fpcr));
    لکھو("%u\n", fpcr & 0x0F);

    /* Read FPSR */
    __asm__ متلون ("mrs %0, fpsr" : "=r"(fpsr));
    لکھو("%u\n", fpsr);

    /* Write/restore FPCR (should be same value) */
    __asm__ متلون ("msr fpcr, %0" : : "r"(fpcr));

    /* Read back and verify */
    {
        غیرعلامتی صحیح check;
        __asm__ متلون ("mrs %0, fpcr" : "=r"(check));
        لکھو("%s\n", check == fpcr ? "ok" : "fail");
    }
}

/* ---- NOP encoding (should not crash) ---- */

ساکن خالی test_nop(خالی)
{
    لکھو("nop:\n");
    __asm__ متلون ("nop");
    __asm__ متلون ("nop");
    __asm__ متلون ("nop");
    لکھو("ok\n");
}

/* ---- barrier instructions ---- */

ساکن خالی test_barriers(خالی)
{
    لکھو("barriers:\n");
    __asm__ متلون ("dmb sy");
    __asm__ متلون ("dsb sy");
    __asm__ متلون ("isb");
    لکھو("ok\n");
}

/* ---- MOV (register) patterns ---- */

ساکن int64_t mov_x0_x1(int64_t x)
{
    اندراج int64_t r __asm__("x0") = x;
    __asm__ متلون ("" : "=r"(r) : "0"(r));
    واپس r;
}

ساکن خالی test_mov_reg(خالی)
{
    لکھو("mov-reg:\n");
    لکھو("%lld\n", (طویل طویل)mov_x0_x1(42));
    لکھو("%lld\n", (طویل طویل)mov_x0_x1(-1));
}

/* ---- large struct passing (reference semantics) ---- */

ساخت large { int64_t a, b, c, d; };

ساکن int64_t مجموع_large(ساخت large s)
{
    واپس s.a + s.b + s.c + s.d;
}

ساکن ساخت large make_large(int64_t a, int64_t b, int64_t c, int64_t d)
{
    ساخت large s = { a, b, c, d };
    واپس s;
}

ساکن خالی test_large_structs(خالی)
{
    ساخت large s = { 1, 2, 3, 4 };
    ساخت large t;

    لکھو("large-struct:\n");
    لکھو("%lld\n", (طویل طویل)مجموع_large(s));

    t = make_large(10, 20, 30, 40);
    لکھو("%lld %lld %lld %lld\n",
           (طویل طویل)t.a, (طویل طویل)t.b,
           (طویل طویل)t.c, (طویل طویل)t.d);
}

/* ---- boundary-sized structs ---- */

ساخت s18 { حرف x[18]; };
ساخت s24 { حرف x[24]; };
ساخت s32 { حرف x[32]; };

ساکن خالی print_s18(ساخت s18 s) { لکھو("%.18s\n", s.x); }
ساکن خالی print_s24(ساخت s24 s) { لکھو("%.24s\n", s.x); }
ساکن خالی print_s32(ساخت s32 s) { لکھو("%.32s\n", s.x); }

ساکن ساخت s18 ret_s18(خالی)
{
    ساخت s18 s = { "123456789012345678" };
    واپس s;
}

ساکن ساخت s24 ret_s24(خالی)
{
    ساخت s24 s = { "123456789012345678901234" };
    واپس s;
}

ساکن ساخت s32 ret_s32(خالی)
{
    ساخت s32 s = { "12345678901234567890123456789012" };
    واپس s;
}

ساکن خالی test_boundary_structs(خالی)
{
    ساخت s18 a;
    ساخت s24 b;
    ساخت s32 c;

    لکھو("boundary-structs:\n");
    a = ret_s18();
    لکھو("%.18s\n", a.x);
    b = ret_s24();
    لکھو("%.24s\n", b.x);
    c = ret_s32();
    لکھو("%.32s\n", c.x);
}

صحیح مین(خالی)
{
    test_shifts();
    test_ldr_str();
    test_ldp_stp();
    test_cond_branches();
    test_cond_select();
    test_sysregs();
    test_nop();
    test_barriers();
    test_mov_reg();
    test_large_structs();
    test_boundary_structs();
    واپس 0;
}
