/* ARM64 instruction encoding verification test.
   Exercises shift-by-immediate, load/store addressing modes,
   conditional branches, and system register access. */

#అన్తర్భావ <stdio.h>
#అన్తర్భావ <stdint.h>

/* ---- shift-by-immediate helpers ---- */

స్థిర uint32_t lsl32(uint32_t x, పూర్ణాంకం n) { తిరిగి x << n; }
స్థిర uint32_t lsr32(uint32_t x, పూర్ణాంకం n) { తిరిగి x >> n; }
స్థిర int32_t  asr32(int32_t  x, పూర్ణాంకం n) { తిరిగి x >> n; }
స్థిర uint64_t lsl64(uint64_t x, పూర్ణాంకం n) { తిరిగి x << n; }
స్థిర uint64_t lsr64(uint64_t x, పూర్ణాంకం n) { తిరిగి x >> n; }
స్థిర int64_t  asr64(int64_t  x, పూర్ణాంకం n) { తిరిగి x >> n; }

స్థిర శూన్య test_shifts(శూన్య)
{
    రాయి("shift-imm:\n");
    రాయి("%x\n", lsl32(1, 0));
    రాయి("%x\n", lsl32(1, 15));
    రాయి("%x\n", lsl32(1, 31));
    రాయి("%x\n", lsr32(0x80000000U, 31));
    రాయి("%x\n", lsr32(0x80000000U, 16));
    రాయి("%x\n", asr32(-1, 1));
    రాయి("%x\n", asr32(-256, 4));
    రాయి("%llx\n", (గుర్తులేని దీర్ఘ దీర్ఘ)lsl64(1ULL, 0));
    రాయి("%llx\n", (గుర్తులేని దీర్ఘ దీర్ఘ)lsl64(1ULL, 32));
    రాయి("%llx\n", (గుర్తులేని దీర్ఘ దీర్ఘ)lsl64(1ULL, 63));
    రాయి("%llx\n", (గుర్తులేని దీర్ఘ దీర్ఘ)lsr64(0x8000000000000000ULL, 63));
    రాయి("%llx\n", (గుర్తులేని దీర్ఘ దీర్ఘ)asr64(-1LL, 1));
    రాయి("%llx\n", (గుర్తులేని దీర్ఘ దీర్ఘ)asr64(-256LL, 4));
}

/* ---- load/store with various addressing modes ---- */

స్థిర శూన్య test_ldr_str(శూన్య)
{
    int64_t buf[4] = { 0x1122334455667788LL, 0x99AABBCCDDEEFF00LL,
                       0x0F1E2D3C4B5A6978LL, 0x0000000000000001LL };
    int64_t val;
    int32_t wval;
    int64_t *p;

    రాయి("ldr-str:\n");

    /* LDR X, [Xn, #offset] */
    val = buf[0];
    రాయి("%llx\n", (గుర్తులేని దీర్ఘ దీర్ఘ)val);
    val = buf[1];
    రాయి("%llx\n", (గుర్తులేని దీర్ఘ దీర్ఘ)val);

    /* LDR W, [Xn, #offset] (32-bit load) */
    wval = *(int32_t*)&buf[0];
    రాయి("%x\n", (గుర్తులేని)wval);

    /* Pre-indexed: store pointer, modify */
    p = &buf[0];
    val = *(p + 2);
    రాయి("%llx\n", (గుర్తులేని దీర్ఘ దీర్ఘ)val);

    /* Post-indexed simulation via pointer arithmetic */
    p = &buf[0];
    val = *p;
    p++;
    రాయి("%llx %llx\n", (గుర్తులేని దీర్ఘ దీర్ఘ)val,
           (గుర్తులేని దీర్ఘ దీర్ఘ)*p);
}

/* ---- STP/LDP (store/load pair) ---- */

స్థిర శూన్య test_ldp_stp(శూన్య)
{
    int64_t src[2] = { 0xAAAABBBBCCCCDDDDLL, 0x1111222233334444LL };
    int64_t dst[2];

    /* The compiler should use stp/ldp for this */
    dst[0] = src[0];
    dst[1] = src[1];

    రాయి("ldp-stp:\n");
    రాయి("%llx %llx\n",
           (గుర్తులేని దీర్ఘ దీర్ఘ)dst[0],
           (గుర్తులేని దీర్ఘ దీర్ఘ)dst[1]);
}

/* ---- CBZ / CBNZ via C patterns ---- */

స్థిర స్థిరరాశి అక్షరం *cbz_test(పూర్ణాంకం x)
{
    ఒకవేళ (x == 0)
        తిరిగి "zero";
    తిరిగి "nonzero";
}

స్థిర స్థిరరాశి అక్షరం *cbnz_test(పూర్ణాంకం x)
{
    ఒకవేళ (x != 0)
        తిరిగి "nonzero";
    తిరిగి "zero";
}

స్థిర శూన్య test_cond_branches(శూన్య)
{
    రాయి("cbz-cbnz:\n");
    రాయి("%s\n", cbz_test(0));
    రాయి("%s\n", cbz_test(42));
    రాయి("%s\n", cbnz_test(0));
    రాయి("%s\n", cbnz_test(42));
}

/* ---- conditional compare patterns (CCMP/CCMN) ---- */

స్థిర పూర్ణాంకం cond_select(పూర్ణాంకం a, పూర్ణాంకం b)
{
    /* TCC should generate csel or equivalent */
    తిరిగి a > b ? a : b;
}

స్థిర శూన్య test_cond_select(శూన్య)
{
    రాయి("csel:\n");
    రాయి("%d\n", cond_select(5, 10));
    రాయి("%d\n", cond_select(10, 5));
    రాయి("%d\n", cond_select(0, 0));
    రాయి("%d\n", cond_select(-1, 1));
}

/* ---- MRS/MSR system registers (FPCR/FPSR) ---- */

స్థిర శూన్య test_sysregs(శూన్య)
{
    గుర్తులేని పూర్ణాంకం fpcr, fpsr;

    రాయి("sysregs:\n");

    /* Read FPCR */
    __asm__ అస్థిర ("mrs %0, fpcr" : "=r"(fpcr));
    రాయి("%u\n", fpcr & 0x0F);

    /* Read FPSR */
    __asm__ అస్థిర ("mrs %0, fpsr" : "=r"(fpsr));
    రాయి("%u\n", fpsr);

    /* Write/restore FPCR (should be same value) */
    __asm__ అస్థిర ("msr fpcr, %0" : : "r"(fpcr));

    /* Read back and verify */
    {
        గుర్తులేని పూర్ణాంకం check;
        __asm__ అస్థిర ("mrs %0, fpcr" : "=r"(check));
        రాయి("%s\n", check == fpcr ? "ok" : "fail");
    }
}

/* ---- NOP encoding (should not crash) ---- */

స్థిర శూన్య test_nop(శూన్య)
{
    రాయి("nop:\n");
    __asm__ అస్థిర ("nop");
    __asm__ అస్థిర ("nop");
    __asm__ అస్థిర ("nop");
    రాయి("ok\n");
}

/* ---- barrier instructions ---- */

స్థిర శూన్య test_barriers(శూన్య)
{
    రాయి("barriers:\n");
    __asm__ అస్థిర ("dmb sy");
    __asm__ అస్థిర ("dsb sy");
    __asm__ అస్థిర ("isb");
    రాయి("ok\n");
}

/* ---- MOV (register) patterns ---- */

స్థిర int64_t mov_x0_x1(int64_t x)
{
    నమోదు int64_t r __asm__("x0") = x;
    __asm__ అస్థిర ("" : "=r"(r) : "0"(r));
    తిరిగి r;
}

స్థిర శూన్య test_mov_reg(శూన్య)
{
    రాయి("mov-reg:\n");
    రాయి("%lld\n", (దీర్ఘ దీర్ఘ)mov_x0_x1(42));
    రాయి("%lld\n", (దీర్ఘ దీర్ఘ)mov_x0_x1(-1));
}

/* ---- large struct passing (reference semantics) ---- */

నిర్మాణం large { int64_t a, b, c, d; };

స్థిర int64_t కూడిక_large(నిర్మాణం large s)
{
    తిరిగి s.a + s.b + s.c + s.d;
}

స్థిర నిర్మాణం large make_large(int64_t a, int64_t b, int64_t c, int64_t d)
{
    నిర్మాణం large s = { a, b, c, d };
    తిరిగి s;
}

స్థిర శూన్య test_large_structs(శూన్య)
{
    నిర్మాణం large s = { 1, 2, 3, 4 };
    నిర్మాణం large t;

    రాయి("large-struct:\n");
    రాయి("%lld\n", (దీర్ఘ దీర్ఘ)కూడిక_large(s));

    t = make_large(10, 20, 30, 40);
    రాయి("%lld %lld %lld %lld\n",
           (దీర్ఘ దీర్ఘ)t.a, (దీర్ఘ దీర్ఘ)t.b,
           (దీర్ఘ దీర్ఘ)t.c, (దీర్ఘ దీర్ఘ)t.d);
}

/* ---- boundary-sized structs ---- */

నిర్మాణం s18 { అక్షరం x[18]; };
నిర్మాణం s24 { అక్షరం x[24]; };
నిర్మాణం s32 { అక్షరం x[32]; };

స్థిర శూన్య print_s18(నిర్మాణం s18 s) { రాయి("%.18s\n", s.x); }
స్థిర శూన్య print_s24(నిర్మాణం s24 s) { రాయి("%.24s\n", s.x); }
స్థిర శూన్య print_s32(నిర్మాణం s32 s) { రాయి("%.32s\n", s.x); }

స్థిర నిర్మాణం s18 ret_s18(శూన్య)
{
    నిర్మాణం s18 s = { "123456789012345678" };
    తిరిగి s;
}

స్థిర నిర్మాణం s24 ret_s24(శూన్య)
{
    నిర్మాణం s24 s = { "123456789012345678901234" };
    తిరిగి s;
}

స్థిర నిర్మాణం s32 ret_s32(శూన్య)
{
    నిర్మాణం s32 s = { "12345678901234567890123456789012" };
    తిరిగి s;
}

స్థిర శూన్య test_boundary_structs(శూన్య)
{
    నిర్మాణం s18 a;
    నిర్మాణం s24 b;
    నిర్మాణం s32 c;

    రాయి("boundary-structs:\n");
    a = ret_s18();
    రాయి("%.18s\n", a.x);
    b = ret_s24();
    రాయి("%.24s\n", b.x);
    c = ret_s32();
    రాయి("%.32s\n", c.x);
}

పూర్ణాంకం ప్రధాన(శూన్య)
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
    తిరిగి 0;
}
