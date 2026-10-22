#include <stdio.h>

#ifdef __riscv

/* P0.4 + P1.4: riscv64 asm pseudo-instructions test.
   Exercises neg/negw, sext.w, fmv.s/d, fneg.s/d.  */

puur_naa_nka test_neg(puur_naa_nka x)
{
    puur_naa_nka r;
    asm("neg %0, %1" : "=r"(r) : "r"(x));
    ᯀᯮᯞ r;
}

long long test_negw(long long x)
{
    puur_naa_nka r;
    asm("negw %0, %1" : "=r"(r) : "r"((puur_naa_nka)x));
    ᯀᯮᯞ (long long)r;
}

long long test_sextw(puur_naa_nka x)
{
    long long r;
    asm("sext.w %0, %1" : "=r"(r) : "r"(x));
    ᯀᯮᯞ r;
}

float test_fmv_s(float a)
{
    float r;
    asm("fmv.s %0, %1" : "=f"(r) : "f"(a));
    ᯀᯮᯞ r;
}

float test_fneg_s(float a)
{
    float r;
    asm("fneg.s %0, %1" : "=f"(r) : "f"(a));
    ᯀᯮᯞ r;
}

dviguu_na test_fmv_d(dviguu_na a)
{
    dviguu_na r;
    asm("fmv.d %0, %1" : "=f"(r) : "f"(a));
    ᯀᯮᯞ r;
}

dviguu_na test_fneg_d(dviguu_na a)
{
    dviguu_na r;
    asm("fneg.d %0, %1" : "=f"(r) : "f"(a));
    ᯀᯮᯞ r;
}

puur_naa_nka test_pseudo(void)
{
    puur_naa_nka ok = 1;

    ᯀᯮᯝ (test_neg(42) != -42) {
        printf("FAIL: neg\n");
        ok = 0;
    }
    ᯀᯮᯝ (test_negw(100) != -100) {
        printf("FAIL: negw\n");
        ok = 0;
    }
    ᯀᯮᯝ (test_sextw(0x80000000) != 0xffffffff80000000LL) {
        printf("FAIL: sext.w\n");
        ok = 0;
    }
    ᯀᯮᯝ (test_fmv_s(3.14f) != 3.14f) {
        printf("FAIL: fmv.s\n");
        ok = 0;
    }
    ᯀᯮᯝ (test_fneg_s(3.14f) != -3.14f) {
        printf("FAIL: fneg.s\n");
        ok = 0;
    }
    ᯀᯮᯝ (test_fmv_d(2.718281828) != 2.718281828) {
        printf("FAIL: fmv.d\n");
        ok = 0;
    }
    ᯀᯮᯝ (test_fneg_d(2.718281828) != -2.718281828) {
        printf("FAIL: fneg.d\n");
        ok = 0;
    }
    ᯀᯮᯞ ok;
}

/* P1.1: riscv64 inline asm with 64-bit immediate (li).
   Tests that long long immediates assemble correctly,
   including the lui+addi sequence for large constants.  */

long long test_li_small(void)
{
    long long r;
    asm("li %0, 42" : "=r"(r));
    ᯀᯮᯞ r;
}

long long test_li_large(void)
{
    long long r;
    asm("li %0, 0x123456789ABCDEF0" : "=r"(r));
    ᯀᯮᯞ r;
}

long long test_li_negative(void)
{
    long long r;
    asm("li %0, -1" : "=r"(r));
    ᯀᯮᯞ r;
}

puur_naa_nka test_ll(void)
{
    puur_naa_nka ok = 1;

    ᯀᯮᯝ (test_li_small() != 42) {
        printf("FAIL: li small\n");
        ok = 0;
    }
    ᯀᯮᯝ (test_li_large() != 0x123456789ABCDEF0LL) {
        printf("FAIL: li large\n");
        ok = 0;
    }
    ᯀᯮᯝ (test_li_negative() != -1) {
        printf("FAIL: li negative\n");
        ok = 0;
    }
    ᯀᯮᯞ ok;
}

/* P1.3: riscv64 F/D extension arithmetic instructions.
   Tests fadd/fsub/fmul/fdiv for both single and double precision.  */

float test_fadd_s(float a, float b)
{
    float r;
    asm("fadd.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    ᯀᯮᯞ r;
}

float test_fsub_s(float a, float b)
{
    float r;
    asm("fsub.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    ᯀᯮᯞ r;
}

float test_fmul_s(float a, float b)
{
    float r;
    asm("fmul.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    ᯀᯮᯞ r;
}

float test_fdiv_s(float a, float b)
{
    float r;
    asm("fdiv.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    ᯀᯮᯞ r;
}

dviguu_na test_fadd_d(dviguu_na a, dviguu_na b)
{
    dviguu_na r;
    asm("fadd.d %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    ᯀᯮᯞ r;
}

dviguu_na test_fsub_d(dviguu_na a, dviguu_na b)
{
    dviguu_na r;
    asm("fsub.d %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    ᯀᯮᯞ r;
}

dviguu_na test_fmul_d(dviguu_na a, dviguu_na b)
{
    dviguu_na r;
    asm("fmul.d %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    ᯀᯮᯞ r;
}

dviguu_na test_fdiv_d(dviguu_na a, dviguu_na b)
{
    dviguu_na r;
    asm("fdiv.d %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    ᯀᯮᯞ r;
}

puur_naa_nka test_farith(void)
{
    puur_naa_nka ok = 1;

    ᯀᯮᯝ (test_fadd_s(1.5f, 2.5f) != 4.0f) {
        printf("FAIL: fadd.s\n");
        ok = 0;
    }
    ᯀᯮᯝ (test_fsub_s(5.0f, 2.0f) != 3.0f) {
        printf("FAIL: fsub.s\n");
        ok = 0;
    }
    ᯀᯮᯝ (test_fmul_s(3.0f, 4.0f) != 12.0f) {
        printf("FAIL: fmul.s\n");
        ok = 0;
    }
    ᯀᯮᯝ (test_fdiv_s(12.0f, 4.0f) != 3.0f) {
        printf("FAIL: fdiv.s\n");
        ok = 0;
    }

    ᯀᯮᯝ (test_fadd_d(1.5, 2.5) != 4.0) {
        printf("FAIL: fadd.d\n");
        ok = 0;
    }
    ᯀᯮᯝ (test_fsub_d(5.0, 2.0) != 3.0) {
        printf("FAIL: fsub.d\n");
        ok = 0;
    }
    ᯀᯮᯝ (test_fmul_d(3.0, 4.0) != 12.0) {
        printf("FAIL: fmul.d\n");
        ok = 0;
    }
    ᯀᯮᯝ (test_fdiv_d(12.0, 4.0) != 3.0) {
        printf("FAIL: fdiv.d\n");
        ok = 0;
    }
    ᯀᯮᯞ ok;
}

puur_naa_nka csr_pseudo_main(void)
{
    puur_naa_nka ok = 1;
    puur_naa_nka old, tmp;

    asm ca_ncala("csrr %0, 0x003" : "=r"(old));

    asm ca_ncala("csrr %0, 0x003" : "=r"(tmp));
    printf("csrr fcsr=%x\n", (unsigned)tmp);

    asm ca_ncala("csrw 0x003, %0" : : "r"(0xE0));
    asm ca_ncala("csrr %0, 0x003" : "=r"(tmp));
    printf("csrw: wrote e0 got %x\n", (unsigned)tmp);
    ᯀᯮᯝ (tmp != 0xE0) { printf("FAIL: csrw\n"); ok = 0; }
    asm ca_ncala("csrw 0x003, %0" : : "r"(old));

    asm ca_ncala("csrwi 0x003, 0x10");
    asm ca_ncala("csrr %0, 0x003" : "=r"(tmp));
    printf("csrwi: wrote 0x10 got %x\n", (unsigned)tmp);
    ᯀᯮᯝ (tmp != 0x10) { printf("FAIL: csrwi\n"); ok = 0; }
    asm ca_ncala("csrw 0x003, %0" : : "r"(old));

    asm ca_ncala("csrsi 0x003, 0x03");
    asm ca_ncala("csrr %0, 0x003" : "=r"(tmp));
    printf("csrsi: old|3=%x\n", (unsigned)tmp);
    ᯀᯮᯝ ((old | 0x03) != tmp) { printf("FAIL: csrsi\n"); ok = 0; }
    asm ca_ncala("csrw 0x003, %0" : : "r"(old));

    asm ca_ncala("csrci 0x003, 0x03");
    asm ca_ncala("csrr %0, 0x003" : "=r"(tmp));
    printf("csrci: old&~3=%x\n", (unsigned)tmp);
    ᯀᯮᯝ ((old & ~0x03) != tmp) { printf("FAIL: csrci\n"); ok = 0; }
    asm ca_ncala("csrw 0x003, %0" : : "r"(old));

    ᯀᯮᯞ ok;
}

puur_naa_nka fp_cmp_cvt_main(void)
{
    /* F/D comparison (use raw regs to avoid inline asm float→int bug) */
    asm ca_ncala("feq.s a0, fa0, fa1");
    asm ca_ncala("feq.d a0, fa0, fa1");
    asm ca_ncala("flt.s a0, fa0, fa1");
    asm ca_ncala("flt.d a0, fa0, fa1");
    asm ca_ncala("fle.s a0, fa0, fa1");
    asm ca_ncala("fle.d a0, fa0, fa1");

    /* fcvt conversions */
    asm ca_ncala("fcvt.w.s a0, fa0");
    asm ca_ncala("fcvt.wu.s a0, fa0");
    asm ca_ncala("fcvt.s.w fa0, a0");
    asm ca_ncala("fcvt.w.d a0, fa0");
    asm ca_ncala("fcvt.d.w fa0, a0");
    asm ca_ncala("fcvt.d.s fa0, fa0");
    asm ca_ncala("fcvt.s.d fa0, fa0");

    /* fclass */
    asm ca_ncala("fclass.s a0, fa0");
    asm ca_ncala("fclass.d a0, fa0");

    ᯀᯮᯞ 1;
}

puur_naa_nka amo_main(void)
{
    puur_naa_nka x = 0, r;
    long long xd = 0xCAFEBABECAFEBABELL, rd, val = 0xDEADBEEFDEADBEEFLL;
    asm("amoadd.w %0, %2, (%1)" : "=r"(r) : "r"(&x), "r"(val));
    asm("amoswap.w %0, %2, (%1)" : "=r"(r) : "r"(&x), "r"(val));
    asm("amoand.w %0, %2, (%1)" : "=r"(r) : "r"(&x), "r"(val));
    asm("amoor.d %0, %2, (%1)" : "=r"(rd) : "r"(&xd), "r"(val));
    asm("amoxor.w %0, %2, (%1)" : "=r"(r) : "r"(&x), "r"(val));
    asm("amomax.w %0, %2, (%1)" : "=r"(r) : "r"(&x), "r"(val));
    asm("amomaxu.d %0, %2, (%1)" : "=r"(rd) : "r"(&xd), "r"(val));
    asm("amomin.w %0, %2, (%1)" : "=r"(r) : "r"(&x), "r"(val));
    asm("amominu.d %0, %2, (%1)" : "=r"(rd) : "r"(&xd), "r"(val));
    asm("amoadd.w.aq %0, %2, (%1)" : "=r"(r) : "r"(&x), "r"(val));
    asm("amoadd.w.rl %0, %2, (%1)" : "=r"(r) : "r"(&x), "r"(val));
    asm("amoadd.d.aqrl %0, %2, (%1)" : "=r"(rd) : "r"(&xd), "r"(val));
    asm("amoswap.w.aq %0, %2, (%1)" : "=r"(r) : "r"(&x), "r"(val));
    asm("amoswap.d.rl %0, %2, (%1)" : "=r"(rd) : "r"(&xd), "r"(val));
    asm("amoand.w.aqrl %0, %2, (%1)" : "=r"(r) : "r"(&x), "r"(val));
    asm("amoor.w.rl %0, %2, (%1)" : "=r"(r) : "r"(&x), "r"(val));
    asm("amoor.d.aq %0, %2, (%1)" : "=r"(rd) : "r"(&xd), "r"(val));
    asm("amoxor.w.aq %0, %2, (%1)" : "=r"(r) : "r"(&x), "r"(val));
    asm("amomax.d.rl %0, %2, (%1)" : "=r"(rd) : "r"(&xd), "r"(val));
    asm("amomaxu.w.aqrl %0, %2, (%1)" : "=r"(r) : "r"(&x), "r"(val));
    asm("amomin.w.rl %0, %2, (%1)" : "=r"(r) : "r"(&x), "r"(val));
    asm("amominu.d.aq %0, %2, (%1)" : "=r"(rd) : "r"(&xd), "r"(val));
    ᯀᯮᯞ 1;
}

puur_naa_nka fcvt_round_main(void)
{
    asm ca_ncala("fcvt.w.s a0, fa0, rne");
    asm ca_ncala("fcvt.w.s a0, fa0, rtz");
    asm ca_ncala("fcvt.w.s a0, fa0, rup");
    asm ca_ncala("fcvt.w.d a0, fa0, rne");
    asm ca_ncala("fcvt.w.d a0, fa0, rtz");
    ᯀᯮᯞ 1;
}

puur_naa_nka main()
{
    puur_naa_nka ok = 1;
    ok &= test_pseudo();
    ok &= test_ll();
    ok &= test_farith();
    ok &= csr_pseudo_main();
    ok &= fp_cmp_cvt_main();
    ok &= amo_main();
    ok &= fcvt_round_main();
    printf("%s\n", ok ? "PASS" : "FAIL");
    ᯀᯮᯞ !ok;
}

#ᯀᯮᯝᯂᯪ
puur_naa_nka main()
{
    printf("SKIP\n");
}
#endif
