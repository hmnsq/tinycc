/* ARM64 instruction encoding verification test.
   Exercises shift-by-immediate, load/store addressing modes,
   conditional branches, and system register access. */

#অন্তর্ভাৱ <stdio.h>
#অন্তর্ভাৱ <stdint.h>

/* ---- shift-by-immediate helpers ---- */

স্থির uint32_t lsl32(uint32_t x, পূর্ণাঙ্ক n) { ঘূৰাই x << n; }
স্থির uint32_t lsr32(uint32_t x, পূর্ণাঙ্ক n) { ঘূৰাই x >> n; }
স্থির int32_t  asr32(int32_t  x, পূর্ণাঙ্ক n) { ঘূৰাই x >> n; }
স্থির uint64_t lsl64(uint64_t x, পূর্ণাঙ্ক n) { ঘূৰাই x << n; }
স্থির uint64_t lsr64(uint64_t x, পূর্ণাঙ্ক n) { ঘূৰাই x >> n; }
স্থির int64_t  asr64(int64_t  x, পূর্ণাঙ্ক n) { ঘূৰাই x >> n; }

স্থির শূন্য test_shifts(শূন্য)
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

স্থির শূন্য test_ldr_str(শূন্য)
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

স্থির শূন্য test_ldp_stp(শূন্য)
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

স্থির ধ্রুৱ ৱর্ণ *cbz_test(পূর্ণাঙ্ক x)
{
    যদি (x == 0)
        ঘূৰাই "zero";
    ঘূৰাই "nonzero";
}

স্থির ধ্রুৱ ৱর্ণ *cbnz_test(পূর্ণাঙ্ক x)
{
    যদি (x != 0)
        ঘূৰাই "nonzero";
    ঘূৰাই "zero";
}

স্থির শূন্য test_cond_branches(শূন্য)
{
    printf("cbz-cbnz:\n");
    printf("%s\n", cbz_test(0));
    printf("%s\n", cbz_test(42));
    printf("%s\n", cbnz_test(0));
    printf("%s\n", cbnz_test(42));
}

/* ---- conditional compare patterns (CCMP/CCMN) ---- */

স্থির পূর্ণাঙ্ক cond_select(পূর্ণাঙ্ক a, পূর্ণাঙ্ক b)
{
    /* TCC should generate csel or equivalent */
    ঘূৰাই a > b ? a : b;
}

স্থির শূন্য test_cond_select(শূন্য)
{
    printf("csel:\n");
    printf("%d\n", cond_select(5, 10));
    printf("%d\n", cond_select(10, 5));
    printf("%d\n", cond_select(0, 0));
    printf("%d\n", cond_select(-1, 1));
}

/* ---- MRS/MSR system registers (FPCR/FPSR) ---- */

স্থির শূন্য test_sysregs(শূন্য)
{
    unsigned পূর্ণাঙ্ক fpcr, fpsr;

    printf("sysregs:\n");

    /* Read FPCR */
    __asm__ চঞ্চল ("mrs %0, fpcr" : "=r"(fpcr));
    printf("%u\n", fpcr & 0x0F);

    /* Read FPSR */
    __asm__ চঞ্চল ("mrs %0, fpsr" : "=r"(fpsr));
    printf("%u\n", fpsr);

    /* Write/restore FPCR (should be same value) */
    __asm__ চঞ্চল ("msr fpcr, %0" : : "r"(fpcr));

    /* Read back and verify */
    {
        unsigned পূর্ণাঙ্ক check;
        __asm__ চঞ্চল ("mrs %0, fpcr" : "=r"(check));
        printf("%s\n", check == fpcr ? "ok" : "fail");
    }
}

/* ---- NOP encoding (should not crash) ---- */

স্থির শূন্য test_nop(শূন্য)
{
    printf("nop:\n");
    __asm__ চঞ্চল ("nop");
    __asm__ চঞ্চল ("nop");
    __asm__ চঞ্চল ("nop");
    printf("ok\n");
}

/* ---- barrier instructions ---- */

স্থির শূন্য test_barriers(শূন্য)
{
    printf("barriers:\n");
    __asm__ চঞ্চল ("dmb sy");
    __asm__ চঞ্চল ("dsb sy");
    __asm__ চঞ্চল ("isb");
    printf("ok\n");
}

/* ---- MOV (register) patterns ---- */

স্থির int64_t mov_x0_x1(int64_t x)
{
    পঞ্জিকা int64_t r __asm__("x0") = x;
    __asm__ চঞ্চল ("" : "=r"(r) : "0"(r));
    ঘূৰাই r;
}

স্থির শূন্য test_mov_reg(শূন্য)
{
    printf("mov-reg:\n");
    printf("%lld\n", (long long)mov_x0_x1(42));
    printf("%lld\n", (long long)mov_x0_x1(-1));
}

/* ---- large struct passing (reference semantics) ---- */

সংরচনা large { int64_t a, b, c, d; };

স্থির int64_t sum_large(সংরচনা large s)
{
    ঘূৰাই s.a + s.b + s.c + s.d;
}

স্থির সংরচনা large make_large(int64_t a, int64_t b, int64_t c, int64_t d)
{
    সংরচনা large s = { a, b, c, d };
    ঘূৰাই s;
}

স্থির শূন্য test_large_structs(শূন্য)
{
    সংরচনা large s = { 1, 2, 3, 4 };
    সংরচনা large t;

    printf("large-struct:\n");
    printf("%lld\n", (long long)sum_large(s));

    t = make_large(10, 20, 30, 40);
    printf("%lld %lld %lld %lld\n",
           (long long)t.a, (long long)t.b,
           (long long)t.c, (long long)t.d);
}

/* ---- boundary-sized structs ---- */

সংরচনা s18 { ৱর্ণ x[18]; };
সংরচনা s24 { ৱর্ণ x[24]; };
সংরচনা s32 { ৱর্ণ x[32]; };

স্থির শূন্য print_s18(সংরচনা s18 s) { printf("%.18s\n", s.x); }
স্থির শূন্য print_s24(সংরচনা s24 s) { printf("%.24s\n", s.x); }
স্থির শূন্য print_s32(সংরচনা s32 s) { printf("%.32s\n", s.x); }

স্থির সংরচনা s18 ret_s18(শূন্য)
{
    সংরচনা s18 s = { "123456789012345678" };
    ঘূৰাই s;
}

স্থির সংরচনা s24 ret_s24(শূন্য)
{
    সংরচনা s24 s = { "123456789012345678901234" };
    ঘূৰাই s;
}

স্থির সংরচনা s32 ret_s32(শূন্য)
{
    সংরচনা s32 s = { "12345678901234567890123456789012" };
    ঘূৰাই s;
}

স্থির শূন্য test_boundary_structs(শূন্য)
{
    সংরচনা s18 a;
    সংরচনা s24 b;
    সংরচনা s32 c;

    printf("boundary-structs:\n");
    a = ret_s18();
    printf("%.18s\n", a.x);
    b = ret_s24();
    printf("%.24s\n", b.x);
    c = ret_s32();
    printf("%.32s\n", c.x);
}

পূর্ণাঙ্ক main(শূন্য)
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
    ঘূৰাই 0;
}
