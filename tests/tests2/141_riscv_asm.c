#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __riscv

/* P0.4 + P1.4: riscv64 asm pseudo-instructions test.
   Exercises neg/negw, sext.w, fmv.s/d, fneg.s/d.  */

ਪੂਰਨ test_neg(ਪੂਰਨ x)
{
    ਪੂਰਨ r;
    asm("neg %0, %1" : "=r"(r) : "r"(x));
    ਵਾਪਸ r;
}

ਲੰਮਾ ਲੰਮਾ test_negw(ਲੰਮਾ ਲੰਮਾ x)
{
    ਪੂਰਨ r;
    asm("negw %0, %1" : "=r"(r) : "r"((ਪੂਰਨ)x));
    ਵਾਪਸ (ਲੰਮਾ ਲੰਮਾ)r;
}

ਲੰਮਾ ਲੰਮਾ test_sextw(ਪੂਰਨ x)
{
    ਲੰਮਾ ਲੰਮਾ r;
    asm("sext.w %0, %1" : "=r"(r) : "r"(x));
    ਵਾਪਸ r;
}

ਦਸ਼ਮਲਵ test_fmv_s(ਦਸ਼ਮਲਵ a)
{
    ਦਸ਼ਮਲਵ r;
    asm("fmv.s %0, %1" : "=f"(r) : "f"(a));
    ਵਾਪਸ r;
}

ਦਸ਼ਮਲਵ test_fneg_s(ਦਸ਼ਮਲਵ a)
{
    ਦਸ਼ਮਲਵ r;
    asm("fneg.s %0, %1" : "=f"(r) : "f"(a));
    ਵਾਪਸ r;
}

ਦੁੱਗਣਾ test_fmv_d(ਦੁੱਗਣਾ a)
{
    ਦੁੱਗਣਾ r;
    asm("fmv.d %0, %1" : "=f"(r) : "f"(a));
    ਵਾਪਸ r;
}

ਦੁੱਗਣਾ test_fneg_d(ਦੁੱਗਣਾ a)
{
    ਦੁੱਗਣਾ r;
    asm("fneg.d %0, %1" : "=f"(r) : "f"(a));
    ਵਾਪਸ r;
}

ਪੂਰਨ test_pseudo(ਖਾਲੀ)
{
    ਪੂਰਨ ok = 1;

    ਜੇ (test_neg(42) != -42) {
        ਲਿਖੋ("FAIL: neg\n");
        ok = 0;
    }
    ਜੇ (test_negw(100) != -100) {
        ਲਿਖੋ("FAIL: negw\n");
        ok = 0;
    }
    ਜੇ (test_sextw(0x80000000) != 0xffffffff80000000LL) {
        ਲਿਖੋ("FAIL: sext.w\n");
        ok = 0;
    }
    ਜੇ (test_fmv_s(3.14f) != 3.14f) {
        ਲਿਖੋ("FAIL: fmv.s\n");
        ok = 0;
    }
    ਜੇ (test_fneg_s(3.14f) != -3.14f) {
        ਲਿਖੋ("FAIL: fneg.s\n");
        ok = 0;
    }
    ਜੇ (test_fmv_d(2.718281828) != 2.718281828) {
        ਲਿਖੋ("FAIL: fmv.d\n");
        ok = 0;
    }
    ਜੇ (test_fneg_d(2.718281828) != -2.718281828) {
        ਲਿਖੋ("FAIL: fneg.d\n");
        ok = 0;
    }
    ਵਾਪਸ ok;
}

/* P1.1: riscv64 inline asm with 64-bit immediate (li).
   Tests that long long immediates assemble correctly,
   including the lui+addi sequence for large constants.  */

ਲੰਮਾ ਲੰਮਾ test_li_small(ਖਾਲੀ)
{
    ਲੰਮਾ ਲੰਮਾ r;
    asm("li %0, 42" : "=r"(r));
    ਵਾਪਸ r;
}

ਲੰਮਾ ਲੰਮਾ test_li_large(ਖਾਲੀ)
{
    ਲੰਮਾ ਲੰਮਾ r;
    asm("li %0, 0x123456789ABCDEF0" : "=r"(r));
    ਵਾਪਸ r;
}

ਲੰਮਾ ਲੰਮਾ test_li_negative(ਖਾਲੀ)
{
    ਲੰਮਾ ਲੰਮਾ r;
    asm("li %0, -1" : "=r"(r));
    ਵਾਪਸ r;
}

ਪੂਰਨ test_ll(ਖਾਲੀ)
{
    ਪੂਰਨ ok = 1;

    ਜੇ (test_li_small() != 42) {
        ਲਿਖੋ("FAIL: li small\n");
        ok = 0;
    }
    ਜੇ (test_li_large() != 0x123456789ABCDEF0LL) {
        ਲਿਖੋ("FAIL: li large\n");
        ok = 0;
    }
    ਜੇ (test_li_negative() != -1) {
        ਲਿਖੋ("FAIL: li negative\n");
        ok = 0;
    }
    ਵਾਪਸ ok;
}

/* P1.3: riscv64 F/D extension arithmetic instructions.
   Tests fadd/fsub/fmul/fdiv for both single and double precision.  */

ਦਸ਼ਮਲਵ test_fadd_s(ਦਸ਼ਮਲਵ a, ਦਸ਼ਮਲਵ b)
{
    ਦਸ਼ਮਲਵ r;
    asm("fadd.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    ਵਾਪਸ r;
}

ਦਸ਼ਮਲਵ test_fsub_s(ਦਸ਼ਮਲਵ a, ਦਸ਼ਮਲਵ b)
{
    ਦਸ਼ਮਲਵ r;
    asm("fsub.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    ਵਾਪਸ r;
}

ਦਸ਼ਮਲਵ test_fmul_s(ਦਸ਼ਮਲਵ a, ਦਸ਼ਮਲਵ b)
{
    ਦਸ਼ਮਲਵ r;
    asm("fmul.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    ਵਾਪਸ r;
}

ਦਸ਼ਮਲਵ test_fdiv_s(ਦਸ਼ਮਲਵ a, ਦਸ਼ਮਲਵ b)
{
    ਦਸ਼ਮਲਵ r;
    asm("fdiv.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    ਵਾਪਸ r;
}

ਦੁੱਗਣਾ test_fadd_d(ਦੁੱਗਣਾ a, ਦੁੱਗਣਾ b)
{
    ਦੁੱਗਣਾ r;
    asm("fadd.d %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    ਵਾਪਸ r;
}

ਦੁੱਗਣਾ test_fsub_d(ਦੁੱਗਣਾ a, ਦੁੱਗਣਾ b)
{
    ਦੁੱਗਣਾ r;
    asm("fsub.d %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    ਵਾਪਸ r;
}

ਦੁੱਗਣਾ test_fmul_d(ਦੁੱਗਣਾ a, ਦੁੱਗਣਾ b)
{
    ਦੁੱਗਣਾ r;
    asm("fmul.d %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    ਵਾਪਸ r;
}

ਦੁੱਗਣਾ test_fdiv_d(ਦੁੱਗਣਾ a, ਦੁੱਗਣਾ b)
{
    ਦੁੱਗਣਾ r;
    asm("fdiv.d %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    ਵਾਪਸ r;
}

ਪੂਰਨ test_farith(ਖਾਲੀ)
{
    ਪੂਰਨ ok = 1;

    ਜੇ (test_fadd_s(1.5f, 2.5f) != 4.0f) {
        ਲਿਖੋ("FAIL: fadd.s\n");
        ok = 0;
    }
    ਜੇ (test_fsub_s(5.0f, 2.0f) != 3.0f) {
        ਲਿਖੋ("FAIL: fsub.s\n");
        ok = 0;
    }
    ਜੇ (test_fmul_s(3.0f, 4.0f) != 12.0f) {
        ਲਿਖੋ("FAIL: fmul.s\n");
        ok = 0;
    }
    ਜੇ (test_fdiv_s(12.0f, 4.0f) != 3.0f) {
        ਲਿਖੋ("FAIL: fdiv.s\n");
        ok = 0;
    }

    ਜੇ (test_fadd_d(1.5, 2.5) != 4.0) {
        ਲਿਖੋ("FAIL: fadd.d\n");
        ok = 0;
    }
    ਜੇ (test_fsub_d(5.0, 2.0) != 3.0) {
        ਲਿਖੋ("FAIL: fsub.d\n");
        ok = 0;
    }
    ਜੇ (test_fmul_d(3.0, 4.0) != 12.0) {
        ਲਿਖੋ("FAIL: fmul.d\n");
        ok = 0;
    }
    ਜੇ (test_fdiv_d(12.0, 4.0) != 3.0) {
        ਲਿਖੋ("FAIL: fdiv.d\n");
        ok = 0;
    }
    ਵਾਪਸ ok;
}

ਪੂਰਨ csr_pseudo_main(ਖਾਲੀ)
{
    ਪੂਰਨ ok = 1;
    ਪੂਰਨ old, tmp;

    asm ਅਸਥਿਰ("csrr %0, 0x003" : "=r"(old));

    asm ਅਸਥਿਰ("csrr %0, 0x003" : "=r"(tmp));
    ਲਿਖੋ("csrr fcsr=%x\n", (ਬਿਨਾਨਿਸ਼ਾਨੀ)tmp);

    asm ਅਸਥਿਰ("csrw 0x003, %0" : : "r"(0xE0));
    asm ਅਸਥਿਰ("csrr %0, 0x003" : "=r"(tmp));
    ਲਿਖੋ("csrw: wrote e0 got %x\n", (ਬਿਨਾਨਿਸ਼ਾਨੀ)tmp);
    ਜੇ (tmp != 0xE0) { ਲਿਖੋ("FAIL: csrw\n"); ok = 0; }
    asm ਅਸਥਿਰ("csrw 0x003, %0" : : "r"(old));

    asm ਅਸਥਿਰ("csrwi 0x003, 0x10");
    asm ਅਸਥਿਰ("csrr %0, 0x003" : "=r"(tmp));
    ਲਿਖੋ("csrwi: wrote 0x10 got %x\n", (ਬਿਨਾਨਿਸ਼ਾਨੀ)tmp);
    ਜੇ (tmp != 0x10) { ਲਿਖੋ("FAIL: csrwi\n"); ok = 0; }
    asm ਅਸਥਿਰ("csrw 0x003, %0" : : "r"(old));

    asm ਅਸਥਿਰ("csrsi 0x003, 0x03");
    asm ਅਸਥਿਰ("csrr %0, 0x003" : "=r"(tmp));
    ਲਿਖੋ("csrsi: old|3=%x\n", (ਬਿਨਾਨਿਸ਼ਾਨੀ)tmp);
    ਜੇ ((old | 0x03) != tmp) { ਲਿਖੋ("FAIL: csrsi\n"); ok = 0; }
    asm ਅਸਥਿਰ("csrw 0x003, %0" : : "r"(old));

    asm ਅਸਥਿਰ("csrci 0x003, 0x03");
    asm ਅਸਥਿਰ("csrr %0, 0x003" : "=r"(tmp));
    ਲਿਖੋ("csrci: old&~3=%x\n", (ਬਿਨਾਨਿਸ਼ਾਨੀ)tmp);
    ਜੇ ((old & ~0x03) != tmp) { ਲਿਖੋ("FAIL: csrci\n"); ok = 0; }
    asm ਅਸਥਿਰ("csrw 0x003, %0" : : "r"(old));

    ਵਾਪਸ ok;
}

ਪੂਰਨ fp_cmp_cvt_main(ਖਾਲੀ)
{
    /* F/D comparison (use raw regs to avoid inline asm float→int bug) */
    asm ਅਸਥਿਰ("feq.s a0, fa0, fa1");
    asm ਅਸਥਿਰ("feq.d a0, fa0, fa1");
    asm ਅਸਥਿਰ("flt.s a0, fa0, fa1");
    asm ਅਸਥਿਰ("flt.d a0, fa0, fa1");
    asm ਅਸਥਿਰ("fle.s a0, fa0, fa1");
    asm ਅਸਥਿਰ("fle.d a0, fa0, fa1");

    /* fcvt conversions */
    asm ਅਸਥਿਰ("fcvt.w.s a0, fa0");
    asm ਅਸਥਿਰ("fcvt.wu.s a0, fa0");
    asm ਅਸਥਿਰ("fcvt.s.w fa0, a0");
    asm ਅਸਥਿਰ("fcvt.w.d a0, fa0");
    asm ਅਸਥਿਰ("fcvt.d.w fa0, a0");
    asm ਅਸਥਿਰ("fcvt.d.s fa0, fa0");
    asm ਅਸਥਿਰ("fcvt.s.d fa0, fa0");

    /* fclass */
    asm ਅਸਥਿਰ("fclass.s a0, fa0");
    asm ਅਸਥਿਰ("fclass.d a0, fa0");

    ਵਾਪਸ 1;
}

ਪੂਰਨ amo_main(ਖਾਲੀ)
{
    ਪੂਰਨ x = 0, r;
    ਲੰਮਾ ਲੰਮਾ xd = 0xCAFEBABECAFEBABELL, rd, val = 0xDEADBEEFDEADBEEFLL;
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
    ਵਾਪਸ 1;
}

ਪੂਰਨ fcvt_ਗੇੜਾ_main(ਖਾਲੀ)
{
    asm ਅਸਥਿਰ("fcvt.w.s a0, fa0, rne");
    asm ਅਸਥਿਰ("fcvt.w.s a0, fa0, rtz");
    asm ਅਸਥਿਰ("fcvt.w.s a0, fa0, rup");
    asm ਅਸਥਿਰ("fcvt.w.d a0, fa0, rne");
    asm ਅਸਥਿਰ("fcvt.w.d a0, fa0, rtz");
    ਵਾਪਸ 1;
}

ਪੂਰਨ ਮੁੱਖ()
{
    ਪੂਰਨ ok = 1;
    ok &= test_pseudo();
    ok &= test_ll();
    ok &= test_farith();
    ok &= csr_pseudo_main();
    ok &= fp_cmp_cvt_main();
    ok &= amo_main();
    ok &= fcvt_ਗੇੜਾ_main();
    ਲਿਖੋ("%s\n", ok ? "PASS" : "FAIL");
    ਵਾਪਸ !ok;
}

#ਨਹੀਂਤਾਂ
ਪੂਰਨ ਮੁੱਖ()
{
    ਲਿਖੋ("SKIP\n");
}
#ਜੇ_ਅੰਤ
