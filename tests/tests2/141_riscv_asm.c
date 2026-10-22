#అన్తర్భావ <stdio.h>

#నిర్వచితమైతే __riscv

/* P0.4 + P1.4: riscv64 asm pseudo-instructions test.
   Exercises neg/negw, sext.w, fmv.s/d, fneg.s/d.  */

పూర్ణాంకం test_neg(పూర్ణాంకం x)
{
    పూర్ణాంకం r;
    asm("neg %0, %1" : "=r"(r) : "r"(x));
    తిరిగి r;
}

దీర్ఘ దీర్ఘ test_negw(దీర్ఘ దీర్ఘ x)
{
    పూర్ణాంకం r;
    asm("negw %0, %1" : "=r"(r) : "r"((పూర్ణాంకం)x));
    తిరిగి (దీర్ఘ దీర్ఘ)r;
}

దీర్ఘ దీర్ఘ test_sextw(పూర్ణాంకం x)
{
    దీర్ఘ దీర్ఘ r;
    asm("sext.w %0, %1" : "=r"(r) : "r"(x));
    తిరిగి r;
}

దశాంశం test_fmv_s(దశాంశం a)
{
    దశాంశం r;
    asm("fmv.s %0, %1" : "=f"(r) : "f"(a));
    తిరిగి r;
}

దశాంశం test_fneg_s(దశాంశం a)
{
    దశాంశం r;
    asm("fneg.s %0, %1" : "=f"(r) : "f"(a));
    తిరిగి r;
}

ద్విగుణ test_fmv_d(ద్విగుణ a)
{
    ద్విగుణ r;
    asm("fmv.d %0, %1" : "=f"(r) : "f"(a));
    తిరిగి r;
}

ద్విగుణ test_fneg_d(ద్విగుణ a)
{
    ద్విగుణ r;
    asm("fneg.d %0, %1" : "=f"(r) : "f"(a));
    తిరిగి r;
}

పూర్ణాంకం test_pseudo(శూన్య)
{
    పూర్ణాంకం ok = 1;

    ఒకవేళ (test_neg(42) != -42) {
        రాయి("FAIL: neg\n");
        ok = 0;
    }
    ఒకవేళ (test_negw(100) != -100) {
        రాయి("FAIL: negw\n");
        ok = 0;
    }
    ఒకవేళ (test_sextw(0x80000000) != 0xffffffff80000000LL) {
        రాయి("FAIL: sext.w\n");
        ok = 0;
    }
    ఒకవేళ (test_fmv_s(3.14f) != 3.14f) {
        రాయి("FAIL: fmv.s\n");
        ok = 0;
    }
    ఒకవేళ (test_fneg_s(3.14f) != -3.14f) {
        రాయి("FAIL: fneg.s\n");
        ok = 0;
    }
    ఒకవేళ (test_fmv_d(2.718281828) != 2.718281828) {
        రాయి("FAIL: fmv.d\n");
        ok = 0;
    }
    ఒకవేళ (test_fneg_d(2.718281828) != -2.718281828) {
        రాయి("FAIL: fneg.d\n");
        ok = 0;
    }
    తిరిగి ok;
}

/* P1.1: riscv64 inline asm with 64-bit immediate (li).
   Tests that long long immediates assemble correctly,
   including the lui+addi sequence for large constants.  */

దీర్ఘ దీర్ఘ test_li_small(శూన్య)
{
    దీర్ఘ దీర్ఘ r;
    asm("li %0, 42" : "=r"(r));
    తిరిగి r;
}

దీర్ఘ దీర్ఘ test_li_large(శూన్య)
{
    దీర్ఘ దీర్ఘ r;
    asm("li %0, 0x123456789ABCDEF0" : "=r"(r));
    తిరిగి r;
}

దీర్ఘ దీర్ఘ test_li_negative(శూన్య)
{
    దీర్ఘ దీర్ఘ r;
    asm("li %0, -1" : "=r"(r));
    తిరిగి r;
}

పూర్ణాంకం test_ll(శూన్య)
{
    పూర్ణాంకం ok = 1;

    ఒకవేళ (test_li_small() != 42) {
        రాయి("FAIL: li small\n");
        ok = 0;
    }
    ఒకవేళ (test_li_large() != 0x123456789ABCDEF0LL) {
        రాయి("FAIL: li large\n");
        ok = 0;
    }
    ఒకవేళ (test_li_negative() != -1) {
        రాయి("FAIL: li negative\n");
        ok = 0;
    }
    తిరిగి ok;
}

/* P1.3: riscv64 F/D extension arithmetic instructions.
   Tests fadd/fsub/fmul/fdiv for both single and double precision.  */

దశాంశం test_fadd_s(దశాంశం a, దశాంశం b)
{
    దశాంశం r;
    asm("fadd.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    తిరిగి r;
}

దశాంశం test_fsub_s(దశాంశం a, దశాంశం b)
{
    దశాంశం r;
    asm("fsub.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    తిరిగి r;
}

దశాంశం test_fmul_s(దశాంశం a, దశాంశం b)
{
    దశాంశం r;
    asm("fmul.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    తిరిగి r;
}

దశాంశం test_fdiv_s(దశాంశం a, దశాంశం b)
{
    దశాంశం r;
    asm("fdiv.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    తిరిగి r;
}

ద్విగుణ test_fadd_d(ద్విగుణ a, ద్విగుణ b)
{
    ద్విగుణ r;
    asm("fadd.d %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    తిరిగి r;
}

ద్విగుణ test_fsub_d(ద్విగుణ a, ద్విగుణ b)
{
    ద్విగుణ r;
    asm("fsub.d %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    తిరిగి r;
}

ద్విగుణ test_fmul_d(ద్విగుణ a, ద్విగుణ b)
{
    ద్విగుణ r;
    asm("fmul.d %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    తిరిగి r;
}

ద్విగుణ test_fdiv_d(ద్విగుణ a, ద్విగుణ b)
{
    ద్విగుణ r;
    asm("fdiv.d %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    తిరిగి r;
}

పూర్ణాంకం test_farith(శూన్య)
{
    పూర్ణాంకం ok = 1;

    ఒకవేళ (test_fadd_s(1.5f, 2.5f) != 4.0f) {
        రాయి("FAIL: fadd.s\n");
        ok = 0;
    }
    ఒకవేళ (test_fsub_s(5.0f, 2.0f) != 3.0f) {
        రాయి("FAIL: fsub.s\n");
        ok = 0;
    }
    ఒకవేళ (test_fmul_s(3.0f, 4.0f) != 12.0f) {
        రాయి("FAIL: fmul.s\n");
        ok = 0;
    }
    ఒకవేళ (test_fdiv_s(12.0f, 4.0f) != 3.0f) {
        రాయి("FAIL: fdiv.s\n");
        ok = 0;
    }

    ఒకవేళ (test_fadd_d(1.5, 2.5) != 4.0) {
        రాయి("FAIL: fadd.d\n");
        ok = 0;
    }
    ఒకవేళ (test_fsub_d(5.0, 2.0) != 3.0) {
        రాయి("FAIL: fsub.d\n");
        ok = 0;
    }
    ఒకవేళ (test_fmul_d(3.0, 4.0) != 12.0) {
        రాయి("FAIL: fmul.d\n");
        ok = 0;
    }
    ఒకవేళ (test_fdiv_d(12.0, 4.0) != 3.0) {
        రాయి("FAIL: fdiv.d\n");
        ok = 0;
    }
    తిరిగి ok;
}

పూర్ణాంకం csr_pseudo_main(శూన్య)
{
    పూర్ణాంకం ok = 1;
    పూర్ణాంకం old, tmp;

    asm అస్థిర("csrr %0, 0x003" : "=r"(old));

    asm అస్థిర("csrr %0, 0x003" : "=r"(tmp));
    రాయి("csrr fcsr=%x\n", (గుర్తులేని)tmp);

    asm అస్థిర("csrw 0x003, %0" : : "r"(0xE0));
    asm అస్థిర("csrr %0, 0x003" : "=r"(tmp));
    రాయి("csrw: wrote e0 got %x\n", (గుర్తులేని)tmp);
    ఒకవేళ (tmp != 0xE0) { రాయి("FAIL: csrw\n"); ok = 0; }
    asm అస్థిర("csrw 0x003, %0" : : "r"(old));

    asm అస్థిర("csrwi 0x003, 0x10");
    asm అస్థిర("csrr %0, 0x003" : "=r"(tmp));
    రాయి("csrwi: wrote 0x10 got %x\n", (గుర్తులేని)tmp);
    ఒకవేళ (tmp != 0x10) { రాయి("FAIL: csrwi\n"); ok = 0; }
    asm అస్థిర("csrw 0x003, %0" : : "r"(old));

    asm అస్థిర("csrsi 0x003, 0x03");
    asm అస్థిర("csrr %0, 0x003" : "=r"(tmp));
    రాయి("csrsi: old|3=%x\n", (గుర్తులేని)tmp);
    ఒకవేళ ((old | 0x03) != tmp) { రాయి("FAIL: csrsi\n"); ok = 0; }
    asm అస్థిర("csrw 0x003, %0" : : "r"(old));

    asm అస్థిర("csrci 0x003, 0x03");
    asm అస్థిర("csrr %0, 0x003" : "=r"(tmp));
    రాయి("csrci: old&~3=%x\n", (గుర్తులేని)tmp);
    ఒకవేళ ((old & ~0x03) != tmp) { రాయి("FAIL: csrci\n"); ok = 0; }
    asm అస్థిర("csrw 0x003, %0" : : "r"(old));

    తిరిగి ok;
}

పూర్ణాంకం fp_cmp_cvt_main(శూన్య)
{
    /* F/D comparison (use raw regs to avoid inline asm float→int bug) */
    asm అస్థిర("feq.s a0, fa0, fa1");
    asm అస్థిర("feq.d a0, fa0, fa1");
    asm అస్థిర("flt.s a0, fa0, fa1");
    asm అస్థిర("flt.d a0, fa0, fa1");
    asm అస్థిర("fle.s a0, fa0, fa1");
    asm అస్థిర("fle.d a0, fa0, fa1");

    /* fcvt conversions */
    asm అస్థిర("fcvt.w.s a0, fa0");
    asm అస్థిర("fcvt.wu.s a0, fa0");
    asm అస్థిర("fcvt.s.w fa0, a0");
    asm అస్థిర("fcvt.w.d a0, fa0");
    asm అస్థిర("fcvt.d.w fa0, a0");
    asm అస్థిర("fcvt.d.s fa0, fa0");
    asm అస్థిర("fcvt.s.d fa0, fa0");

    /* fclass */
    asm అస్థిర("fclass.s a0, fa0");
    asm అస్థిర("fclass.d a0, fa0");

    తిరిగి 1;
}

పూర్ణాంకం amo_main(శూన్య)
{
    పూర్ణాంకం x = 0, r;
    దీర్ఘ దీర్ఘ xd = 0xCAFEBABECAFEBABELL, rd, val = 0xDEADBEEFDEADBEEFLL;
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
    తిరిగి 1;
}

పూర్ణాంకం fcvt_విడత_main(శూన్య)
{
    asm అస్థిర("fcvt.w.s a0, fa0, rne");
    asm అస్థిర("fcvt.w.s a0, fa0, rtz");
    asm అస్థిర("fcvt.w.s a0, fa0, rup");
    asm అస్థిర("fcvt.w.d a0, fa0, rne");
    asm అస్థిర("fcvt.w.d a0, fa0, rtz");
    తిరిగి 1;
}

పూర్ణాంకం ప్రధాన()
{
    పూర్ణాంకం ok = 1;
    ok &= test_pseudo();
    ok &= test_ll();
    ok &= test_farith();
    ok &= csr_pseudo_main();
    ok &= fp_cmp_cvt_main();
    ok &= amo_main();
    ok &= fcvt_విడత_main();
    రాయి("%s\n", ok ? "PASS" : "FAIL");
    తిరిగి !ok;
}

#లేకపోతే
పూర్ణాంకం ప్రధాన()
{
    రాయి("SKIP\n");
}
#అయితే_ముగింపు
