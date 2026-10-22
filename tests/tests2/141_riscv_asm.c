#شامل <stdio.h>

#ifdef __riscv

/* P0.4 + P1.4: riscv64 asm pseudo-instructions test.
   Exercises neg/negw, sext.w, fmv.s/d, fneg.s/d.  */

صحیح test_neg(صحیح x)
{
    صحیح r;
    asm("neg %0, %1" : "=r"(r) : "r"(x));
    بازگشت r;
}

long long test_negw(long long x)
{
    صحیح r;
    asm("negw %0, %1" : "=r"(r) : "r"((صحیح)x));
    بازگشت (long long)r;
}

long long test_sextw(صحیح x)
{
    long long r;
    asm("sext.w %0, %1" : "=r"(r) : "r"(x));
    بازگشت r;
}

اعشاری test_fmv_s(اعشاری a)
{
    اعشاری r;
    asm("fmv.s %0, %1" : "=f"(r) : "f"(a));
    بازگشت r;
}

اعشاری test_fneg_s(اعشاری a)
{
    اعشاری r;
    asm("fneg.s %0, %1" : "=f"(r) : "f"(a));
    بازگشت r;
}

دوگانه test_fmv_d(دوگانه a)
{
    دوگانه r;
    asm("fmv.d %0, %1" : "=f"(r) : "f"(a));
    بازگشت r;
}

دوگانه test_fneg_d(دوگانه a)
{
    دوگانه r;
    asm("fneg.d %0, %1" : "=f"(r) : "f"(a));
    بازگشت r;
}

صحیح test_pseudo(تهی)
{
    صحیح ok = 1;

    اگر (test_neg(42) != -42) {
        printf("FAIL: neg\n");
        ok = 0;
    }
    اگر (test_negw(100) != -100) {
        printf("FAIL: negw\n");
        ok = 0;
    }
    اگر (test_sextw(0x80000000) != 0xffffffff80000000LL) {
        printf("FAIL: sext.w\n");
        ok = 0;
    }
    اگر (test_fmv_s(3.14f) != 3.14f) {
        printf("FAIL: fmv.s\n");
        ok = 0;
    }
    اگر (test_fneg_s(3.14f) != -3.14f) {
        printf("FAIL: fneg.s\n");
        ok = 0;
    }
    اگر (test_fmv_d(2.718281828) != 2.718281828) {
        printf("FAIL: fmv.d\n");
        ok = 0;
    }
    اگر (test_fneg_d(2.718281828) != -2.718281828) {
        printf("FAIL: fneg.d\n");
        ok = 0;
    }
    بازگشت ok;
}

/* P1.1: riscv64 inline asm with 64-bit immediate (li).
   Tests that long long immediates assemble correctly,
   including the lui+addi sequence for large constants.  */

long long test_li_small(تهی)
{
    long long r;
    asm("li %0, 42" : "=r"(r));
    بازگشت r;
}

long long test_li_large(تهی)
{
    long long r;
    asm("li %0, 0x123456789ABCDEF0" : "=r"(r));
    بازگشت r;
}

long long test_li_negative(تهی)
{
    long long r;
    asm("li %0, -1" : "=r"(r));
    بازگشت r;
}

صحیح test_ll(تهی)
{
    صحیح ok = 1;

    اگر (test_li_small() != 42) {
        printf("FAIL: li small\n");
        ok = 0;
    }
    اگر (test_li_large() != 0x123456789ABCDEF0LL) {
        printf("FAIL: li large\n");
        ok = 0;
    }
    اگر (test_li_negative() != -1) {
        printf("FAIL: li negative\n");
        ok = 0;
    }
    بازگشت ok;
}

/* P1.3: riscv64 F/D extension arithmetic instructions.
   Tests fadd/fsub/fmul/fdiv for both single and double precision.  */

اعشاری test_fadd_s(اعشاری a, اعشاری b)
{
    اعشاری r;
    asm("fadd.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    بازگشت r;
}

اعشاری test_fsub_s(اعشاری a, اعشاری b)
{
    اعشاری r;
    asm("fsub.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    بازگشت r;
}

اعشاری test_fmul_s(اعشاری a, اعشاری b)
{
    اعشاری r;
    asm("fmul.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    بازگشت r;
}

اعشاری test_fdiv_s(اعشاری a, اعشاری b)
{
    اعشاری r;
    asm("fdiv.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    بازگشت r;
}

دوگانه test_fadd_d(دوگانه a, دوگانه b)
{
    دوگانه r;
    asm("fadd.d %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    بازگشت r;
}

دوگانه test_fsub_d(دوگانه a, دوگانه b)
{
    دوگانه r;
    asm("fsub.d %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    بازگشت r;
}

دوگانه test_fmul_d(دوگانه a, دوگانه b)
{
    دوگانه r;
    asm("fmul.d %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    بازگشت r;
}

دوگانه test_fdiv_d(دوگانه a, دوگانه b)
{
    دوگانه r;
    asm("fdiv.d %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    بازگشت r;
}

صحیح test_farith(تهی)
{
    صحیح ok = 1;

    اگر (test_fadd_s(1.5f, 2.5f) != 4.0f) {
        printf("FAIL: fadd.s\n");
        ok = 0;
    }
    اگر (test_fsub_s(5.0f, 2.0f) != 3.0f) {
        printf("FAIL: fsub.s\n");
        ok = 0;
    }
    اگر (test_fmul_s(3.0f, 4.0f) != 12.0f) {
        printf("FAIL: fmul.s\n");
        ok = 0;
    }
    اگر (test_fdiv_s(12.0f, 4.0f) != 3.0f) {
        printf("FAIL: fdiv.s\n");
        ok = 0;
    }

    اگر (test_fadd_d(1.5, 2.5) != 4.0) {
        printf("FAIL: fadd.d\n");
        ok = 0;
    }
    اگر (test_fsub_d(5.0, 2.0) != 3.0) {
        printf("FAIL: fsub.d\n");
        ok = 0;
    }
    اگر (test_fmul_d(3.0, 4.0) != 12.0) {
        printf("FAIL: fmul.d\n");
        ok = 0;
    }
    اگر (test_fdiv_d(12.0, 4.0) != 3.0) {
        printf("FAIL: fdiv.d\n");
        ok = 0;
    }
    بازگشت ok;
}

صحیح csr_pseudo_main(تهی)
{
    صحیح ok = 1;
    صحیح old, tmp;

    asm فرار("csrr %0, 0x003" : "=r"(old));

    asm فرار("csrr %0, 0x003" : "=r"(tmp));
    printf("csrr fcsr=%x\n", (unsigned)tmp);

    asm فرار("csrw 0x003, %0" : : "r"(0xE0));
    asm فرار("csrr %0, 0x003" : "=r"(tmp));
    printf("csrw: wrote e0 got %x\n", (unsigned)tmp);
    اگر (tmp != 0xE0) { printf("FAIL: csrw\n"); ok = 0; }
    asm فرار("csrw 0x003, %0" : : "r"(old));

    asm فرار("csrwi 0x003, 0x10");
    asm فرار("csrr %0, 0x003" : "=r"(tmp));
    printf("csrwi: wrote 0x10 got %x\n", (unsigned)tmp);
    اگر (tmp != 0x10) { printf("FAIL: csrwi\n"); ok = 0; }
    asm فرار("csrw 0x003, %0" : : "r"(old));

    asm فرار("csrsi 0x003, 0x03");
    asm فرار("csrr %0, 0x003" : "=r"(tmp));
    printf("csrsi: old|3=%x\n", (unsigned)tmp);
    اگر ((old | 0x03) != tmp) { printf("FAIL: csrsi\n"); ok = 0; }
    asm فرار("csrw 0x003, %0" : : "r"(old));

    asm فرار("csrci 0x003, 0x03");
    asm فرار("csrr %0, 0x003" : "=r"(tmp));
    printf("csrci: old&~3=%x\n", (unsigned)tmp);
    اگر ((old & ~0x03) != tmp) { printf("FAIL: csrci\n"); ok = 0; }
    asm فرار("csrw 0x003, %0" : : "r"(old));

    بازگشت ok;
}

صحیح fp_cmp_cvt_main(تهی)
{
    /* F/D comparison (use raw regs to avoid inline asm float→int bug) */
    asm فرار("feq.s a0, fa0, fa1");
    asm فرار("feq.d a0, fa0, fa1");
    asm فرار("flt.s a0, fa0, fa1");
    asm فرار("flt.d a0, fa0, fa1");
    asm فرار("fle.s a0, fa0, fa1");
    asm فرار("fle.d a0, fa0, fa1");

    /* fcvt conversions */
    asm فرار("fcvt.w.s a0, fa0");
    asm فرار("fcvt.wu.s a0, fa0");
    asm فرار("fcvt.s.w fa0, a0");
    asm فرار("fcvt.w.d a0, fa0");
    asm فرار("fcvt.d.w fa0, a0");
    asm فرار("fcvt.d.s fa0, fa0");
    asm فرار("fcvt.s.d fa0, fa0");

    /* fclass */
    asm فرار("fclass.s a0, fa0");
    asm فرار("fclass.d a0, fa0");

    بازگشت 1;
}

صحیح amo_main(تهی)
{
    صحیح x = 0, r;
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
    بازگشت 1;
}

صحیح fcvt_round_main(تهی)
{
    asm فرار("fcvt.w.s a0, fa0, rne");
    asm فرار("fcvt.w.s a0, fa0, rtz");
    asm فرار("fcvt.w.s a0, fa0, rup");
    asm فرار("fcvt.w.d a0, fa0, rne");
    asm فرار("fcvt.w.d a0, fa0, rtz");
    بازگشت 1;
}

صحیح اصلی()
{
    صحیح ok = 1;
    ok &= test_pseudo();
    ok &= test_ll();
    ok &= test_farith();
    ok &= csr_pseudo_main();
    ok &= fp_cmp_cvt_main();
    ok &= amo_main();
    ok &= fcvt_round_main();
    printf("%s\n", ok ? "PASS" : "FAIL");
    بازگشت !ok;
}

#وگرنه
صحیح اصلی()
{
    printf("SKIP\n");
}
#endif
