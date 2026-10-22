#અન્તર્ભાવ <stdio.h>

#ifdef __riscv

/* P0.4 + P1.4: riscv64 asm pseudo-instructions test.
   Exercises neg/negw, sext.w, fmv.s/d, fneg.s/d.  */

પૂર્ણાંક test_neg(પૂર્ણાંક x)
{
    પૂર્ણાંક r;
    asm("neg %0, %1" : "=r"(r) : "r"(x));
    પાછા r;
}

long long test_negw(long long x)
{
    પૂર્ણાંક r;
    asm("negw %0, %1" : "=r"(r) : "r"((પૂર્ણાંક)x));
    પાછા (long long)r;
}

long long test_sextw(પૂર્ણાંક x)
{
    long long r;
    asm("sext.w %0, %1" : "=r"(r) : "r"(x));
    પાછા r;
}

દશાંશ test_fmv_s(દશાંશ a)
{
    દશાંશ r;
    asm("fmv.s %0, %1" : "=f"(r) : "f"(a));
    પાછા r;
}

દશાંશ test_fneg_s(દશાંશ a)
{
    દશાંશ r;
    asm("fneg.s %0, %1" : "=f"(r) : "f"(a));
    પાછા r;
}

દ્વિગુણ test_fmv_d(દ્વિગુણ a)
{
    દ્વિગુણ r;
    asm("fmv.d %0, %1" : "=f"(r) : "f"(a));
    પાછા r;
}

દ્વિગુણ test_fneg_d(દ્વિગુણ a)
{
    દ્વિગુણ r;
    asm("fneg.d %0, %1" : "=f"(r) : "f"(a));
    પાછા r;
}

પૂર્ણાંક test_pseudo(શૂન્ય)
{
    પૂર્ણાંક ok = 1;

    જો (test_neg(42) != -42) {
        printf("FAIL: neg\n");
        ok = 0;
    }
    જો (test_negw(100) != -100) {
        printf("FAIL: negw\n");
        ok = 0;
    }
    જો (test_sextw(0x80000000) != 0xffffffff80000000LL) {
        printf("FAIL: sext.w\n");
        ok = 0;
    }
    જો (test_fmv_s(3.14f) != 3.14f) {
        printf("FAIL: fmv.s\n");
        ok = 0;
    }
    જો (test_fneg_s(3.14f) != -3.14f) {
        printf("FAIL: fneg.s\n");
        ok = 0;
    }
    જો (test_fmv_d(2.718281828) != 2.718281828) {
        printf("FAIL: fmv.d\n");
        ok = 0;
    }
    જો (test_fneg_d(2.718281828) != -2.718281828) {
        printf("FAIL: fneg.d\n");
        ok = 0;
    }
    પાછા ok;
}

/* P1.1: riscv64 inline asm with 64-bit immediate (li).
   Tests that long long immediates assemble correctly,
   including the lui+addi sequence for large constants.  */

long long test_li_small(શૂન્ય)
{
    long long r;
    asm("li %0, 42" : "=r"(r));
    પાછા r;
}

long long test_li_large(શૂન્ય)
{
    long long r;
    asm("li %0, 0x123456789ABCDEF0" : "=r"(r));
    પાછા r;
}

long long test_li_negative(શૂન્ય)
{
    long long r;
    asm("li %0, -1" : "=r"(r));
    પાછા r;
}

પૂર્ણાંક test_ll(શૂન્ય)
{
    પૂર્ણાંક ok = 1;

    જો (test_li_small() != 42) {
        printf("FAIL: li small\n");
        ok = 0;
    }
    જો (test_li_large() != 0x123456789ABCDEF0LL) {
        printf("FAIL: li large\n");
        ok = 0;
    }
    જો (test_li_negative() != -1) {
        printf("FAIL: li negative\n");
        ok = 0;
    }
    પાછા ok;
}

/* P1.3: riscv64 F/D extension arithmetic instructions.
   Tests fadd/fsub/fmul/fdiv for both single and double precision.  */

દશાંશ test_fadd_s(દશાંશ a, દશાંશ b)
{
    દશાંશ r;
    asm("fadd.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    પાછા r;
}

દશાંશ test_fsub_s(દશાંશ a, દશાંશ b)
{
    દશાંશ r;
    asm("fsub.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    પાછા r;
}

દશાંશ test_fmul_s(દશાંશ a, દશાંશ b)
{
    દશાંશ r;
    asm("fmul.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    પાછા r;
}

દશાંશ test_fdiv_s(દશાંશ a, દશાંશ b)
{
    દશાંશ r;
    asm("fdiv.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    પાછા r;
}

દ્વિગુણ test_fadd_d(દ્વિગુણ a, દ્વિગુણ b)
{
    દ્વિગુણ r;
    asm("fadd.d %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    પાછા r;
}

દ્વિગુણ test_fsub_d(દ્વિગુણ a, દ્વિગુણ b)
{
    દ્વિગુણ r;
    asm("fsub.d %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    પાછા r;
}

દ્વિગુણ test_fmul_d(દ્વિગુણ a, દ્વિગુણ b)
{
    દ્વિગુણ r;
    asm("fmul.d %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    પાછા r;
}

દ્વિગુણ test_fdiv_d(દ્વિગુણ a, દ્વિગુણ b)
{
    દ્વિગુણ r;
    asm("fdiv.d %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    પાછા r;
}

પૂર્ણાંક test_farith(શૂન્ય)
{
    પૂર્ણાંક ok = 1;

    જો (test_fadd_s(1.5f, 2.5f) != 4.0f) {
        printf("FAIL: fadd.s\n");
        ok = 0;
    }
    જો (test_fsub_s(5.0f, 2.0f) != 3.0f) {
        printf("FAIL: fsub.s\n");
        ok = 0;
    }
    જો (test_fmul_s(3.0f, 4.0f) != 12.0f) {
        printf("FAIL: fmul.s\n");
        ok = 0;
    }
    જો (test_fdiv_s(12.0f, 4.0f) != 3.0f) {
        printf("FAIL: fdiv.s\n");
        ok = 0;
    }

    જો (test_fadd_d(1.5, 2.5) != 4.0) {
        printf("FAIL: fadd.d\n");
        ok = 0;
    }
    જો (test_fsub_d(5.0, 2.0) != 3.0) {
        printf("FAIL: fsub.d\n");
        ok = 0;
    }
    જો (test_fmul_d(3.0, 4.0) != 12.0) {
        printf("FAIL: fmul.d\n");
        ok = 0;
    }
    જો (test_fdiv_d(12.0, 4.0) != 3.0) {
        printf("FAIL: fdiv.d\n");
        ok = 0;
    }
    પાછા ok;
}

પૂર્ણાંક csr_pseudo_main(શૂન્ય)
{
    પૂર્ણાંક ok = 1;
    પૂર્ણાંક old, tmp;

    asm અસ્થિર("csrr %0, 0x003" : "=r"(old));

    asm અસ્થિર("csrr %0, 0x003" : "=r"(tmp));
    printf("csrr fcsr=%x\n", (unsigned)tmp);

    asm અસ્થિર("csrw 0x003, %0" : : "r"(0xE0));
    asm અસ્થિર("csrr %0, 0x003" : "=r"(tmp));
    printf("csrw: wrote e0 got %x\n", (unsigned)tmp);
    જો (tmp != 0xE0) { printf("FAIL: csrw\n"); ok = 0; }
    asm અસ્થિર("csrw 0x003, %0" : : "r"(old));

    asm અસ્થિર("csrwi 0x003, 0x10");
    asm અસ્થિર("csrr %0, 0x003" : "=r"(tmp));
    printf("csrwi: wrote 0x10 got %x\n", (unsigned)tmp);
    જો (tmp != 0x10) { printf("FAIL: csrwi\n"); ok = 0; }
    asm અસ્થિર("csrw 0x003, %0" : : "r"(old));

    asm અસ્થિર("csrsi 0x003, 0x03");
    asm અસ્થિર("csrr %0, 0x003" : "=r"(tmp));
    printf("csrsi: old|3=%x\n", (unsigned)tmp);
    જો ((old | 0x03) != tmp) { printf("FAIL: csrsi\n"); ok = 0; }
    asm અસ્થિર("csrw 0x003, %0" : : "r"(old));

    asm અસ્થિર("csrci 0x003, 0x03");
    asm અસ્થિર("csrr %0, 0x003" : "=r"(tmp));
    printf("csrci: old&~3=%x\n", (unsigned)tmp);
    જો ((old & ~0x03) != tmp) { printf("FAIL: csrci\n"); ok = 0; }
    asm અસ્થિર("csrw 0x003, %0" : : "r"(old));

    પાછા ok;
}

પૂર્ણાંક fp_cmp_cvt_main(શૂન્ય)
{
    /* F/D comparison (use raw regs to avoid inline asm float→int bug) */
    asm અસ્થિર("feq.s a0, fa0, fa1");
    asm અસ્થિર("feq.d a0, fa0, fa1");
    asm અસ્થિર("flt.s a0, fa0, fa1");
    asm અસ્થિર("flt.d a0, fa0, fa1");
    asm અસ્થિર("fle.s a0, fa0, fa1");
    asm અસ્થિર("fle.d a0, fa0, fa1");

    /* fcvt conversions */
    asm અસ્થિર("fcvt.w.s a0, fa0");
    asm અસ્થિર("fcvt.wu.s a0, fa0");
    asm અસ્થિર("fcvt.s.w fa0, a0");
    asm અસ્થિર("fcvt.w.d a0, fa0");
    asm અસ્થિર("fcvt.d.w fa0, a0");
    asm અસ્થિર("fcvt.d.s fa0, fa0");
    asm અસ્થિર("fcvt.s.d fa0, fa0");

    /* fclass */
    asm અસ્થિર("fclass.s a0, fa0");
    asm અસ્થિર("fclass.d a0, fa0");

    પાછા 1;
}

પૂર્ણાંક amo_main(શૂન્ય)
{
    પૂર્ણાંક x = 0, r;
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
    પાછા 1;
}

પૂર્ણાંક fcvt_round_main(શૂન્ય)
{
    asm અસ્થિર("fcvt.w.s a0, fa0, rne");
    asm અસ્થિર("fcvt.w.s a0, fa0, rtz");
    asm અસ્થિર("fcvt.w.s a0, fa0, rup");
    asm અસ્થિર("fcvt.w.d a0, fa0, rne");
    asm અસ્થિર("fcvt.w.d a0, fa0, rtz");
    પાછા 1;
}

પૂર્ણાંક મુખ્ય()
{
    પૂર્ણાંક ok = 1;
    ok &= test_pseudo();
    ok &= test_ll();
    ok &= test_farith();
    ok &= csr_pseudo_main();
    ok &= fp_cmp_cvt_main();
    ok &= amo_main();
    ok &= fcvt_round_main();
    printf("%s\n", ok ? "PASS" : "FAIL");
    પાછા !ok;
}

#નહીંતર
પૂર્ણાંક મુખ્ય()
{
    printf("SKIP\n");
}
#endif
