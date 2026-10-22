#ضمن <stdio.h>

#اگر_تعریف_شده __riscv

/* P0.4 + P1.4: riscv64 asm pseudo-instructions test.
   Exercises neg/negw, sext.w, fmv.s/d, fneg.s/d.  */

صحيح test_neg(صحيح x)
{
    صحيح r;
    asm("neg %0, %1" : "=r"(r) : "r"(x));
    أرجع r;
}

دراز دراز test_negw(دراز دراز x)
{
    صحيح r;
    asm("negw %0, %1" : "=r"(r) : "r"((صحيح)x));
    أرجع (دراز دراز)r;
}

دراز دراز test_sextw(صحيح x)
{
    دراز دراز r;
    asm("sext.w %0, %1" : "=r"(r) : "r"(x));
    أرجع r;
}

عائم test_fmv_s(عائم a)
{
    عائم r;
    asm("fmv.s %0, %1" : "=f"(r) : "f"(a));
    أرجع r;
}

عائم test_fneg_s(عائم a)
{
    عائم r;
    asm("fneg.s %0, %1" : "=f"(r) : "f"(a));
    أرجع r;
}

مزدوج test_fmv_d(مزدوج a)
{
    مزدوج r;
    asm("fmv.d %0, %1" : "=f"(r) : "f"(a));
    أرجع r;
}

مزدوج test_fneg_d(مزدوج a)
{
    مزدوج r;
    asm("fneg.d %0, %1" : "=f"(r) : "f"(a));
    أرجع r;
}

صحيح test_pseudo(فراغ)
{
    صحيح ok = 1;

    إذا (test_neg(42) != -42) {
        چاپ_کن("FAIL: neg\n");
        ok = 0;
    }
    إذا (test_negw(100) != -100) {
        چاپ_کن("FAIL: negw\n");
        ok = 0;
    }
    إذا (test_sextw(0x80000000) != 0xffffffff80000000LL) {
        چاپ_کن("FAIL: sext.w\n");
        ok = 0;
    }
    إذا (test_fmv_s(3.14f) != 3.14f) {
        چاپ_کن("FAIL: fmv.s\n");
        ok = 0;
    }
    إذا (test_fneg_s(3.14f) != -3.14f) {
        چاپ_کن("FAIL: fneg.s\n");
        ok = 0;
    }
    إذا (test_fmv_d(2.718281828) != 2.718281828) {
        چاپ_کن("FAIL: fmv.d\n");
        ok = 0;
    }
    إذا (test_fneg_d(2.718281828) != -2.718281828) {
        چاپ_کن("FAIL: fneg.d\n");
        ok = 0;
    }
    أرجع ok;
}

/* P1.1: riscv64 inline asm with 64-bit immediate (li).
   Tests that long long immediates assemble correctly,
   including the lui+addi sequence for large constants.  */

دراز دراز test_li_small(فراغ)
{
    دراز دراز r;
    asm("li %0, 42" : "=r"(r));
    أرجع r;
}

دراز دراز test_li_large(فراغ)
{
    دراز دراز r;
    asm("li %0, 0x123456789ABCDEF0" : "=r"(r));
    أرجع r;
}

دراز دراز test_li_negative(فراغ)
{
    دراز دراز r;
    asm("li %0, -1" : "=r"(r));
    أرجع r;
}

صحيح test_ll(فراغ)
{
    صحيح ok = 1;

    إذا (test_li_small() != 42) {
        چاپ_کن("FAIL: li small\n");
        ok = 0;
    }
    إذا (test_li_large() != 0x123456789ABCDEF0LL) {
        چاپ_کن("FAIL: li large\n");
        ok = 0;
    }
    إذا (test_li_negative() != -1) {
        چاپ_کن("FAIL: li negative\n");
        ok = 0;
    }
    أرجع ok;
}

/* P1.3: riscv64 F/D extension arithmetic instructions.
   Tests fadd/fsub/fmul/fdiv for both single and double precision.  */

عائم test_fadd_s(عائم a, عائم b)
{
    عائم r;
    asm("fadd.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    أرجع r;
}

عائم test_fsub_s(عائم a, عائم b)
{
    عائم r;
    asm("fsub.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    أرجع r;
}

عائم test_fmul_s(عائم a, عائم b)
{
    عائم r;
    asm("fmul.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    أرجع r;
}

عائم test_fdiv_s(عائم a, عائم b)
{
    عائم r;
    asm("fdiv.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    أرجع r;
}

مزدوج test_fadd_d(مزدوج a, مزدوج b)
{
    مزدوج r;
    asm("fadd.d %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    أرجع r;
}

مزدوج test_fsub_d(مزدوج a, مزدوج b)
{
    مزدوج r;
    asm("fsub.d %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    أرجع r;
}

مزدوج test_fmul_d(مزدوج a, مزدوج b)
{
    مزدوج r;
    asm("fmul.d %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    أرجع r;
}

مزدوج test_fdiv_d(مزدوج a, مزدوج b)
{
    مزدوج r;
    asm("fdiv.d %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    أرجع r;
}

صحيح test_farith(فراغ)
{
    صحيح ok = 1;

    إذا (test_fadd_s(1.5f, 2.5f) != 4.0f) {
        چاپ_کن("FAIL: fadd.s\n");
        ok = 0;
    }
    إذا (test_fsub_s(5.0f, 2.0f) != 3.0f) {
        چاپ_کن("FAIL: fsub.s\n");
        ok = 0;
    }
    إذا (test_fmul_s(3.0f, 4.0f) != 12.0f) {
        چاپ_کن("FAIL: fmul.s\n");
        ok = 0;
    }
    إذا (test_fdiv_s(12.0f, 4.0f) != 3.0f) {
        چاپ_کن("FAIL: fdiv.s\n");
        ok = 0;
    }

    إذا (test_fadd_d(1.5, 2.5) != 4.0) {
        چاپ_کن("FAIL: fadd.d\n");
        ok = 0;
    }
    إذا (test_fsub_d(5.0, 2.0) != 3.0) {
        چاپ_کن("FAIL: fsub.d\n");
        ok = 0;
    }
    إذا (test_fmul_d(3.0, 4.0) != 12.0) {
        چاپ_کن("FAIL: fmul.d\n");
        ok = 0;
    }
    إذا (test_fdiv_d(12.0, 4.0) != 3.0) {
        چاپ_کن("FAIL: fdiv.d\n");
        ok = 0;
    }
    أرجع ok;
}

صحيح csr_pseudo_main(فراغ)
{
    صحيح ok = 1;
    صحيح old, tmp;

    asm متطاير("csrr %0, 0x003" : "=r"(old));

    asm متطاير("csrr %0, 0x003" : "=r"(tmp));
    چاپ_کن("csrr fcsr=%x\n", (بیعلامت)tmp);

    asm متطاير("csrw 0x003, %0" : : "r"(0xE0));
    asm متطاير("csrr %0, 0x003" : "=r"(tmp));
    چاپ_کن("csrw: wrote e0 got %x\n", (بیعلامت)tmp);
    إذا (tmp != 0xE0) { چاپ_کن("FAIL: csrw\n"); ok = 0; }
    asm متطاير("csrw 0x003, %0" : : "r"(old));

    asm متطاير("csrwi 0x003, 0x10");
    asm متطاير("csrr %0, 0x003" : "=r"(tmp));
    چاپ_کن("csrwi: wrote 0x10 got %x\n", (بیعلامت)tmp);
    إذا (tmp != 0x10) { چاپ_کن("FAIL: csrwi\n"); ok = 0; }
    asm متطاير("csrw 0x003, %0" : : "r"(old));

    asm متطاير("csrsi 0x003, 0x03");
    asm متطاير("csrr %0, 0x003" : "=r"(tmp));
    چاپ_کن("csrsi: old|3=%x\n", (بیعلامت)tmp);
    إذا ((old | 0x03) != tmp) { چاپ_کن("FAIL: csrsi\n"); ok = 0; }
    asm متطاير("csrw 0x003, %0" : : "r"(old));

    asm متطاير("csrci 0x003, 0x03");
    asm متطاير("csrr %0, 0x003" : "=r"(tmp));
    چاپ_کن("csrci: old&~3=%x\n", (بیعلامت)tmp);
    إذا ((old & ~0x03) != tmp) { چاپ_کن("FAIL: csrci\n"); ok = 0; }
    asm متطاير("csrw 0x003, %0" : : "r"(old));

    أرجع ok;
}

صحيح fp_cmp_cvt_main(فراغ)
{
    /* F/D comparison (use raw regs to avoid inline asm float→int bug) */
    asm متطاير("feq.s a0, fa0, fa1");
    asm متطاير("feq.d a0, fa0, fa1");
    asm متطاير("flt.s a0, fa0, fa1");
    asm متطاير("flt.d a0, fa0, fa1");
    asm متطاير("fle.s a0, fa0, fa1");
    asm متطاير("fle.d a0, fa0, fa1");

    /* fcvt conversions */
    asm متطاير("fcvt.w.s a0, fa0");
    asm متطاير("fcvt.wu.s a0, fa0");
    asm متطاير("fcvt.s.w fa0, a0");
    asm متطاير("fcvt.w.d a0, fa0");
    asm متطاير("fcvt.d.w fa0, a0");
    asm متطاير("fcvt.d.s fa0, fa0");
    asm متطاير("fcvt.s.d fa0, fa0");

    /* fclass */
    asm متطاير("fclass.s a0, fa0");
    asm متطاير("fclass.d a0, fa0");

    أرجع 1;
}

صحيح amo_main(فراغ)
{
    صحيح x = 0, r;
    دراز دراز xd = 0xCAFEBABECAFEBABELL, rd, val = 0xDEADBEEFDEADBEEFLL;
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
    أرجع 1;
}

صحيح fcvt_دور_main(فراغ)
{
    asm متطاير("fcvt.w.s a0, fa0, rne");
    asm متطاير("fcvt.w.s a0, fa0, rtz");
    asm متطاير("fcvt.w.s a0, fa0, rup");
    asm متطاير("fcvt.w.d a0, fa0, rne");
    asm متطاير("fcvt.w.d a0, fa0, rtz");
    أرجع 1;
}

صحيح اصلی()
{
    صحيح ok = 1;
    ok &= test_pseudo();
    ok &= test_ll();
    ok &= test_farith();
    ok &= csr_pseudo_main();
    ok &= fp_cmp_cvt_main();
    ok &= amo_main();
    ok &= fcvt_دور_main();
    چاپ_کن("%s\n", ok ? "PASS" : "FAIL");
    أرجع !ok;
}

#وإلا
صحيح اصلی()
{
    چاپ_کن("SKIP\n");
}
#پایان_اگر
