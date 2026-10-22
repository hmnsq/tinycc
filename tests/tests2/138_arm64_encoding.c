/* ARM64 instruction encoding verification test.
   Exercises shift-by-immediate, load/store addressing modes,
   conditional branches, and system register access. */

#અન્તર્ભાવ <stdio.h>
#અન્તર્ભાવ <stdint.h>

/* ---- shift-by-immediate helpers ---- */

સ્થિર uint32_t lsl32(uint32_t x, પૂર્ણાંક n) { પાછા x << n; }
સ્થિર uint32_t lsr32(uint32_t x, પૂર્ણાંક n) { પાછા x >> n; }
સ્થિર int32_t  asr32(int32_t  x, પૂર્ણાંક n) { પાછા x >> n; }
સ્થિર uint64_t lsl64(uint64_t x, પૂર્ણાંક n) { પાછા x << n; }
સ્થિર uint64_t lsr64(uint64_t x, પૂર્ણાંક n) { પાછા x >> n; }
સ્થિર int64_t  asr64(int64_t  x, પૂર્ણાંક n) { પાછા x >> n; }

સ્થિર શૂન્ય test_shifts(શૂન્ય)
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

સ્થિર શૂન્ય test_ldr_str(શૂન્ય)
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

સ્થિર શૂન્ય test_ldp_stp(શૂન્ય)
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

સ્થિર અચલ અક્ષર *cbz_test(પૂર્ણાંક x)
{
    જો (x == 0)
        પાછા "zero";
    પાછા "nonzero";
}

સ્થિર અચલ અક્ષર *cbnz_test(પૂર્ણાંક x)
{
    જો (x != 0)
        પાછા "nonzero";
    પાછા "zero";
}

સ્થિર શૂન્ય test_cond_branches(શૂન્ય)
{
    printf("cbz-cbnz:\n");
    printf("%s\n", cbz_test(0));
    printf("%s\n", cbz_test(42));
    printf("%s\n", cbnz_test(0));
    printf("%s\n", cbnz_test(42));
}

/* ---- conditional compare patterns (CCMP/CCMN) ---- */

સ્થિર પૂર્ણાંક cond_select(પૂર્ણાંક a, પૂર્ણાંક b)
{
    /* TCC should generate csel or equivalent */
    પાછા a > b ? a : b;
}

સ્થિર શૂન્ય test_cond_select(શૂન્ય)
{
    printf("csel:\n");
    printf("%d\n", cond_select(5, 10));
    printf("%d\n", cond_select(10, 5));
    printf("%d\n", cond_select(0, 0));
    printf("%d\n", cond_select(-1, 1));
}

/* ---- MRS/MSR system registers (FPCR/FPSR) ---- */

સ્થિર શૂન્ય test_sysregs(શૂન્ય)
{
    unsigned પૂર્ણાંક fpcr, fpsr;

    printf("sysregs:\n");

    /* Read FPCR */
    __asm__ અસ્થિર ("mrs %0, fpcr" : "=r"(fpcr));
    printf("%u\n", fpcr & 0x0F);

    /* Read FPSR */
    __asm__ અસ્થિર ("mrs %0, fpsr" : "=r"(fpsr));
    printf("%u\n", fpsr);

    /* Write/restore FPCR (should be same value) */
    __asm__ અસ્થિર ("msr fpcr, %0" : : "r"(fpcr));

    /* Read back and verify */
    {
        unsigned પૂર્ણાંક check;
        __asm__ અસ્થિર ("mrs %0, fpcr" : "=r"(check));
        printf("%s\n", check == fpcr ? "ok" : "fail");
    }
}

/* ---- NOP encoding (should not crash) ---- */

સ્થિર શૂન્ય test_nop(શૂન્ય)
{
    printf("nop:\n");
    __asm__ અસ્થિર ("nop");
    __asm__ અસ્થિર ("nop");
    __asm__ અસ્થિર ("nop");
    printf("ok\n");
}

/* ---- barrier instructions ---- */

સ્થિર શૂન્ય test_barriers(શૂન્ય)
{
    printf("barriers:\n");
    __asm__ અસ્થિર ("dmb sy");
    __asm__ અસ્થિર ("dsb sy");
    __asm__ અસ્થિર ("isb");
    printf("ok\n");
}

/* ---- MOV (register) patterns ---- */

સ્થિર int64_t mov_x0_x1(int64_t x)
{
    નોંધણી int64_t r __asm__("x0") = x;
    __asm__ અસ્થિર ("" : "=r"(r) : "0"(r));
    પાછા r;
}

સ્થિર શૂન્ય test_mov_reg(શૂન્ય)
{
    printf("mov-reg:\n");
    printf("%lld\n", (long long)mov_x0_x1(42));
    printf("%lld\n", (long long)mov_x0_x1(-1));
}

/* ---- large struct passing (reference semantics) ---- */

સંરચના large { int64_t a, b, c, d; };

સ્થિર int64_t sum_large(સંરચના large s)
{
    પાછા s.a + s.b + s.c + s.d;
}

સ્થિર સંરચના large make_large(int64_t a, int64_t b, int64_t c, int64_t d)
{
    સંરચના large s = { a, b, c, d };
    પાછા s;
}

સ્થિર શૂન્ય test_large_structs(શૂન્ય)
{
    સંરચના large s = { 1, 2, 3, 4 };
    સંરચના large t;

    printf("large-struct:\n");
    printf("%lld\n", (long long)sum_large(s));

    t = make_large(10, 20, 30, 40);
    printf("%lld %lld %lld %lld\n",
           (long long)t.a, (long long)t.b,
           (long long)t.c, (long long)t.d);
}

/* ---- boundary-sized structs ---- */

સંરચના s18 { અક્ષર x[18]; };
સંરચના s24 { અક્ષર x[24]; };
સંરચના s32 { અક્ષર x[32]; };

સ્થિર શૂન્ય print_s18(સંરચના s18 s) { printf("%.18s\n", s.x); }
સ્થિર શૂન્ય print_s24(સંરચના s24 s) { printf("%.24s\n", s.x); }
સ્થિર શૂન્ય print_s32(સંરચના s32 s) { printf("%.32s\n", s.x); }

સ્થિર સંરચના s18 ret_s18(શૂન્ય)
{
    સંરચના s18 s = { "123456789012345678" };
    પાછા s;
}

સ્થિર સંરચના s24 ret_s24(શૂન્ય)
{
    સંરચના s24 s = { "123456789012345678901234" };
    પાછા s;
}

સ્થિર સંરચના s32 ret_s32(શૂન્ય)
{
    સંરચના s32 s = { "12345678901234567890123456789012" };
    પાછા s;
}

સ્થિર શૂન્ય test_boundary_structs(શૂન્ય)
{
    સંરચના s18 a;
    સંરચના s24 b;
    સંરચના s32 c;

    printf("boundary-structs:\n");
    a = ret_s18();
    printf("%.18s\n", a.x);
    b = ret_s24();
    printf("%.24s\n", b.x);
    c = ret_s32();
    printf("%.32s\n", c.x);
}

પૂર્ણાંક મુખ્ય(શૂન્ય)
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
    પાછા 0;
}
