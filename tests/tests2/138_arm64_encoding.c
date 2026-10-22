/* ARM64 instruction encoding verification test.
   Exercises shift-by-immediate, load/store addressing modes,
   conditional branches, and system register access. */

#ضمن <stdio.h>
#ضمن <stdint.h>

/* ---- shift-by-immediate helpers ---- */

ساكن uint32_t lsl32(uint32_t x, صحيح n) { إرجاع x << n; }
ساكن uint32_t lsr32(uint32_t x, صحيح n) { إرجاع x >> n; }
ساكن int32_t  asr32(int32_t  x, صحيح n) { إرجاع x >> n; }
ساكن uint64_t lsl64(uint64_t x, صحيح n) { إرجاع x << n; }
ساكن uint64_t lsr64(uint64_t x, صحيح n) { إرجاع x >> n; }
ساكن int64_t  asr64(int64_t  x, صحيح n) { إرجاع x >> n; }

ساكن فراغ test_shifts(فراغ)
{
    printf("shift-imm:\n");
    printf("%x\n", lsl32(1, 0));
    printf("%x\n", lsl32(1, 15));
    printf("%x\n", lsl32(1, 31));
    printf("%x\n", lsr32(0x80000000U, 31));
    printf("%x\n", lsr32(0x80000000U, 16));
    printf("%x\n", asr32(-1, 1));
    printf("%x\n", asr32(-256, 4));
    printf("%llx\n", (unsigned long long)lsl64(1ULL, 0));
    printf("%llx\n", (unsigned long long)lsl64(1ULL, 32));
    printf("%llx\n", (unsigned long long)lsl64(1ULL, 63));
    printf("%llx\n", (unsigned long long)lsr64(0x8000000000000000ULL, 63));
    printf("%llx\n", (unsigned long long)asr64(-1LL, 1));
    printf("%llx\n", (unsigned long long)asr64(-256LL, 4));
}

/* ---- load/store with various addressing modes ---- */

ساكن فراغ test_ldr_str(فراغ)
{
    int64_t buf[4] = { 0x1122334455667788LL, 0x99AABBCCDDEEFF00LL,
                       0x0F1E2D3C4B5A6978LL, 0x0000000000000001LL };
    int64_t val;
    int32_t wval;
    int64_t *p;

    printf("ldr-str:\n");

    /* LDR X, [Xn, #offset] */
    val = buf[0];
    printf("%llx\n", (unsigned long long)val);
    val = buf[1];
    printf("%llx\n", (unsigned long long)val);

    /* LDR W, [Xn, #offset] (32-bit load) */
    wval = *(int32_t*)&buf[0];
    printf("%x\n", (unsigned)wval);

    /* Pre-indexed: store pointer, modify */
    p = &buf[0];
    val = *(p + 2);
    printf("%llx\n", (unsigned long long)val);

    /* Post-indexed simulation via pointer arithmetic */
    p = &buf[0];
    val = *p;
    p++;
    printf("%llx %llx\n", (unsigned long long)val,
           (unsigned long long)*p);
}

/* ---- STP/LDP (store/load pair) ---- */

ساكن فراغ test_ldp_stp(فراغ)
{
    int64_t src[2] = { 0xAAAABBBBCCCCDDDDLL, 0x1111222233334444LL };
    int64_t dst[2];

    /* The compiler should use stp/ldp for this */
    dst[0] = src[0];
    dst[1] = src[1];

    printf("ldp-stp:\n");
    printf("%llx %llx\n",
           (unsigned long long)dst[0],
           (unsigned long long)dst[1]);
}

/* ---- CBZ / CBNZ via C patterns ---- */

ساكن ثابت حرف *cbz_test(صحيح x)
{
    إذا (x == 0)
        إرجاع "zero";
    إرجاع "nonzero";
}

ساكن ثابت حرف *cbnz_test(صحيح x)
{
    إذا (x != 0)
        إرجاع "nonzero";
    إرجاع "zero";
}

ساكن فراغ test_cond_branches(فراغ)
{
    printf("cbz-cbnz:\n");
    printf("%s\n", cbz_test(0));
    printf("%s\n", cbz_test(42));
    printf("%s\n", cbnz_test(0));
    printf("%s\n", cbnz_test(42));
}

/* ---- conditional compare patterns (CCMP/CCMN) ---- */

ساكن صحيح cond_select(صحيح a, صحيح b)
{
    /* TCC should generate csel or equivalent */
    إرجاع a > b ? a : b;
}

ساكن فراغ test_cond_select(فراغ)
{
    printf("csel:\n");
    printf("%d\n", cond_select(5, 10));
    printf("%d\n", cond_select(10, 5));
    printf("%d\n", cond_select(0, 0));
    printf("%d\n", cond_select(-1, 1));
}

/* ---- MRS/MSR system registers (FPCR/FPSR) ---- */

ساكن فراغ test_sysregs(فراغ)
{
    unsigned صحيح fpcr, fpsr;

    printf("sysregs:\n");

    /* Read FPCR */
    __asm__ متطاير ("mrs %0, fpcr" : "=r"(fpcr));
    printf("%u\n", fpcr & 0x0F);

    /* Read FPSR */
    __asm__ متطاير ("mrs %0, fpsr" : "=r"(fpsr));
    printf("%u\n", fpsr);

    /* Write/restore FPCR (should be same value) */
    __asm__ متطاير ("msr fpcr, %0" : : "r"(fpcr));

    /* Read back and verify */
    {
        unsigned صحيح check;
        __asm__ متطاير ("mrs %0, fpcr" : "=r"(check));
        printf("%s\n", check == fpcr ? "ok" : "fail");
    }
}

/* ---- NOP encoding (should not crash) ---- */

ساكن فراغ test_nop(فراغ)
{
    printf("nop:\n");
    __asm__ متطاير ("nop");
    __asm__ متطاير ("nop");
    __asm__ متطاير ("nop");
    printf("ok\n");
}

/* ---- barrier instructions ---- */

ساكن فراغ test_barriers(فراغ)
{
    printf("barriers:\n");
    __asm__ متطاير ("dmb sy");
    __asm__ متطاير ("dsb sy");
    __asm__ متطاير ("isb");
    printf("ok\n");
}

/* ---- MOV (register) patterns ---- */

ساكن int64_t mov_x0_x1(int64_t x)
{
    سجل int64_t r __asm__("x0") = x;
    __asm__ متطاير ("" : "=r"(r) : "0"(r));
    إرجاع r;
}

ساكن فراغ test_mov_reg(فراغ)
{
    printf("mov-reg:\n");
    printf("%lld\n", (long long)mov_x0_x1(42));
    printf("%lld\n", (long long)mov_x0_x1(-1));
}

/* ---- large struct passing (reference semantics) ---- */

بنية large { int64_t a, b, c, d; };

ساكن int64_t sum_large(بنية large s)
{
    إرجاع s.a + s.b + s.c + s.d;
}

ساكن بنية large make_large(int64_t a, int64_t b, int64_t c, int64_t d)
{
    بنية large s = { a, b, c, d };
    إرجاع s;
}

ساكن فراغ test_large_structs(فراغ)
{
    بنية large s = { 1, 2, 3, 4 };
    بنية large t;

    printf("large-struct:\n");
    printf("%lld\n", (long long)sum_large(s));

    t = make_large(10, 20, 30, 40);
    printf("%lld %lld %lld %lld\n",
           (long long)t.a, (long long)t.b,
           (long long)t.c, (long long)t.d);
}

/* ---- boundary-sized structs ---- */

بنية s18 { حرف x[18]; };
بنية s24 { حرف x[24]; };
بنية s32 { حرف x[32]; };

ساكن فراغ print_s18(بنية s18 s) { printf("%.18s\n", s.x); }
ساكن فراغ print_s24(بنية s24 s) { printf("%.24s\n", s.x); }
ساكن فراغ print_s32(بنية s32 s) { printf("%.32s\n", s.x); }

ساكن بنية s18 ret_s18(فراغ)
{
    بنية s18 s = { "123456789012345678" };
    إرجاع s;
}

ساكن بنية s24 ret_s24(فراغ)
{
    بنية s24 s = { "123456789012345678901234" };
    إرجاع s;
}

ساكن بنية s32 ret_s32(فراغ)
{
    بنية s32 s = { "12345678901234567890123456789012" };
    إرجاع s;
}

ساكن فراغ test_boundary_structs(فراغ)
{
    بنية s18 a;
    بنية s24 b;
    بنية s32 c;

    printf("boundary-structs:\n");
    a = ret_s18();
    printf("%.18s\n", a.x);
    b = ret_s24();
    printf("%.24s\n", b.x);
    c = ret_s32();
    printf("%.32s\n", c.x);
}

صحيح الرئيسية(فراغ)
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
    إرجاع 0;
}
