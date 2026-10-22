#অন্তর্ভাব <stdio.h>

#ifdef __riscv

/* P0.4 + P1.4: riscv64 asm pseudo-instructions test.
   Exercises neg/negw, sext.w, fmv.s/d, fneg.s/d.  */

পূর্ণাঙ্ক test_neg(পূর্ণাঙ্ক x)
{
    পূর্ণাঙ্ক r;
    asm("neg %0, %1" : "=r"(r) : "r"(x));
    প্রত্যাগম r;
}

long long test_negw(long long x)
{
    পূর্ণাঙ্ক r;
    asm("negw %0, %1" : "=r"(r) : "r"((পূর্ণাঙ্ক)x));
    প্রত্যাগম (long long)r;
}

long long test_sextw(পূর্ণাঙ্ক x)
{
    long long r;
    asm("sext.w %0, %1" : "=r"(r) : "r"(x));
    প্রত্যাগম r;
}

ভিন্ন test_fmv_s(ভিন্ন a)
{
    ভিন্ন r;
    asm("fmv.s %0, %1" : "=f"(r) : "f"(a));
    প্রত্যাগম r;
}

ভিন্ন test_fneg_s(ভিন্ন a)
{
    ভিন্ন r;
    asm("fneg.s %0, %1" : "=f"(r) : "f"(a));
    প্রত্যাগম r;
}

দ্বিগুণ test_fmv_d(দ্বিগুণ a)
{
    দ্বিগুণ r;
    asm("fmv.d %0, %1" : "=f"(r) : "f"(a));
    প্রত্যাগম r;
}

দ্বিগুণ test_fneg_d(দ্বিগুণ a)
{
    দ্বিগুণ r;
    asm("fneg.d %0, %1" : "=f"(r) : "f"(a));
    প্রত্যাগম r;
}

পূর্ণাঙ্ক test_pseudo(শূন্য)
{
    পূর্ণাঙ্ক ok = 1;

    যদি (test_neg(42) != -42) {
        printf("FAIL: neg\n");
        ok = 0;
    }
    যদি (test_negw(100) != -100) {
        printf("FAIL: negw\n");
        ok = 0;
    }
    যদি (test_sextw(0x80000000) != 0xffffffff80000000LL) {
        printf("FAIL: sext.w\n");
        ok = 0;
    }
    যদি (test_fmv_s(3.14f) != 3.14f) {
        printf("FAIL: fmv.s\n");
        ok = 0;
    }
    যদি (test_fneg_s(3.14f) != -3.14f) {
        printf("FAIL: fneg.s\n");
        ok = 0;
    }
    যদি (test_fmv_d(2.718281828) != 2.718281828) {
        printf("FAIL: fmv.d\n");
        ok = 0;
    }
    যদি (test_fneg_d(2.718281828) != -2.718281828) {
        printf("FAIL: fneg.d\n");
        ok = 0;
    }
    প্রত্যাগম ok;
}

/* P1.1: riscv64 inline asm with 64-bit immediate (li).
   Tests that long long immediates assemble correctly,
   including the lui+addi sequence for large constants.  */

long long test_li_small(শূন্য)
{
    long long r;
    asm("li %0, 42" : "=r"(r));
    প্রত্যাগম r;
}

long long test_li_large(শূন্য)
{
    long long r;
    asm("li %0, 0x123456789ABCDEF0" : "=r"(r));
    প্রত্যাগম r;
}

long long test_li_negative(শূন্য)
{
    long long r;
    asm("li %0, -1" : "=r"(r));
    প্রত্যাগম r;
}

পূর্ণাঙ্ক test_ll(শূন্য)
{
    পূর্ণাঙ্ক ok = 1;

    যদি (test_li_small() != 42) {
        printf("FAIL: li small\n");
        ok = 0;
    }
    যদি (test_li_large() != 0x123456789ABCDEF0LL) {
        printf("FAIL: li large\n");
        ok = 0;
    }
    যদি (test_li_negative() != -1) {
        printf("FAIL: li negative\n");
        ok = 0;
    }
    প্রত্যাগম ok;
}

/* P1.3: riscv64 F/D extension arithmetic instructions.
   Tests fadd/fsub/fmul/fdiv for both single and double precision.  */

ভিন্ন test_fadd_s(ভিন্ন a, ভিন্ন b)
{
    ভিন্ন r;
    asm("fadd.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    প্রত্যাগম r;
}

ভিন্ন test_fsub_s(ভিন্ন a, ভিন্ন b)
{
    ভিন্ন r;
    asm("fsub.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    প্রত্যাগম r;
}

ভিন্ন test_fmul_s(ভিন্ন a, ভিন্ন b)
{
    ভিন্ন r;
    asm("fmul.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    প্রত্যাগম r;
}

ভিন্ন test_fdiv_s(ভিন্ন a, ভিন্ন b)
{
    ভিন্ন r;
    asm("fdiv.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    প্রত্যাগম r;
}

দ্বিগুণ test_fadd_d(দ্বিগুণ a, দ্বিগুণ b)
{
    দ্বিগুণ r;
    asm("fadd.d %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    প্রত্যাগম r;
}

দ্বিগুণ test_fsub_d(দ্বিগুণ a, দ্বিগুণ b)
{
    দ্বিগুণ r;
    asm("fsub.d %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    প্রত্যাগম r;
}

দ্বিগুণ test_fmul_d(দ্বিগুণ a, দ্বিগুণ b)
{
    দ্বিগুণ r;
    asm("fmul.d %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    প্রত্যাগম r;
}

দ্বিগুণ test_fdiv_d(দ্বিগুণ a, দ্বিগুণ b)
{
    দ্বিগুণ r;
    asm("fdiv.d %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    প্রত্যাগম r;
}

পূর্ণাঙ্ক test_farith(শূন্য)
{
    পূর্ণাঙ্ক ok = 1;

    যদি (test_fadd_s(1.5f, 2.5f) != 4.0f) {
        printf("FAIL: fadd.s\n");
        ok = 0;
    }
    যদি (test_fsub_s(5.0f, 2.0f) != 3.0f) {
        printf("FAIL: fsub.s\n");
        ok = 0;
    }
    যদি (test_fmul_s(3.0f, 4.0f) != 12.0f) {
        printf("FAIL: fmul.s\n");
        ok = 0;
    }
    যদি (test_fdiv_s(12.0f, 4.0f) != 3.0f) {
        printf("FAIL: fdiv.s\n");
        ok = 0;
    }

    যদি (test_fadd_d(1.5, 2.5) != 4.0) {
        printf("FAIL: fadd.d\n");
        ok = 0;
    }
    যদি (test_fsub_d(5.0, 2.0) != 3.0) {
        printf("FAIL: fsub.d\n");
        ok = 0;
    }
    যদি (test_fmul_d(3.0, 4.0) != 12.0) {
        printf("FAIL: fmul.d\n");
        ok = 0;
    }
    যদি (test_fdiv_d(12.0, 4.0) != 3.0) {
        printf("FAIL: fdiv.d\n");
        ok = 0;
    }
    প্রত্যাগম ok;
}

পূর্ণাঙ্ক csr_pseudo_main(শূন্য)
{
    পূর্ণাঙ্ক ok = 1;
    পূর্ণাঙ্ক old, tmp;

    asm চঞ্চল("csrr %0, 0x003" : "=r"(old));

    asm চঞ্চল("csrr %0, 0x003" : "=r"(tmp));
    printf("csrr fcsr=%x\n", (unsigned)tmp);

    asm চঞ্চল("csrw 0x003, %0" : : "r"(0xE0));
    asm চঞ্চল("csrr %0, 0x003" : "=r"(tmp));
    printf("csrw: wrote e0 got %x\n", (unsigned)tmp);
    যদি (tmp != 0xE0) { printf("FAIL: csrw\n"); ok = 0; }
    asm চঞ্চল("csrw 0x003, %0" : : "r"(old));

    asm চঞ্চল("csrwi 0x003, 0x10");
    asm চঞ্চল("csrr %0, 0x003" : "=r"(tmp));
    printf("csrwi: wrote 0x10 got %x\n", (unsigned)tmp);
    যদি (tmp != 0x10) { printf("FAIL: csrwi\n"); ok = 0; }
    asm চঞ্চল("csrw 0x003, %0" : : "r"(old));

    asm চঞ্চল("csrsi 0x003, 0x03");
    asm চঞ্চল("csrr %0, 0x003" : "=r"(tmp));
    printf("csrsi: old|3=%x\n", (unsigned)tmp);
    যদি ((old | 0x03) != tmp) { printf("FAIL: csrsi\n"); ok = 0; }
    asm চঞ্চল("csrw 0x003, %0" : : "r"(old));

    asm চঞ্চল("csrci 0x003, 0x03");
    asm চঞ্চল("csrr %0, 0x003" : "=r"(tmp));
    printf("csrci: old&~3=%x\n", (unsigned)tmp);
    যদি ((old & ~0x03) != tmp) { printf("FAIL: csrci\n"); ok = 0; }
    asm চঞ্চল("csrw 0x003, %0" : : "r"(old));

    প্রত্যাগম ok;
}

পূর্ণাঙ্ক fp_cmp_cvt_main(শূন্য)
{
    /* F/D comparison (use raw regs to avoid inline asm float→int bug) */
    asm চঞ্চল("feq.s a0, fa0, fa1");
    asm চঞ্চল("feq.d a0, fa0, fa1");
    asm চঞ্চল("flt.s a0, fa0, fa1");
    asm চঞ্চল("flt.d a0, fa0, fa1");
    asm চঞ্চল("fle.s a0, fa0, fa1");
    asm চঞ্চল("fle.d a0, fa0, fa1");

    /* fcvt conversions */
    asm চঞ্চল("fcvt.w.s a0, fa0");
    asm চঞ্চল("fcvt.wu.s a0, fa0");
    asm চঞ্চল("fcvt.s.w fa0, a0");
    asm চঞ্চল("fcvt.w.d a0, fa0");
    asm চঞ্চল("fcvt.d.w fa0, a0");
    asm চঞ্চল("fcvt.d.s fa0, fa0");
    asm চঞ্চল("fcvt.s.d fa0, fa0");

    /* fclass */
    asm চঞ্চল("fclass.s a0, fa0");
    asm চঞ্চল("fclass.d a0, fa0");

    প্রত্যাগম 1;
}

পূর্ণাঙ্ক amo_main(শূন্য)
{
    পূর্ণাঙ্ক x = 0, r;
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
    প্রত্যাগম 1;
}

পূর্ণাঙ্ক fcvt_round_main(শূন্য)
{
    asm চঞ্চল("fcvt.w.s a0, fa0, rne");
    asm চঞ্চল("fcvt.w.s a0, fa0, rtz");
    asm চঞ্চল("fcvt.w.s a0, fa0, rup");
    asm চঞ্চল("fcvt.w.d a0, fa0, rne");
    asm চঞ্চল("fcvt.w.d a0, fa0, rtz");
    প্রত্যাগম 1;
}

পূর্ণাঙ্ক main()
{
    পূর্ণাঙ্ক ok = 1;
    ok &= test_pseudo();
    ok &= test_ll();
    ok &= test_farith();
    ok &= csr_pseudo_main();
    ok &= fp_cmp_cvt_main();
    ok &= amo_main();
    ok &= fcvt_round_main();
    printf("%s\n", ok ? "PASS" : "FAIL");
    প্রত্যাগম !ok;
}

#অন্যথা
পূর্ণাঙ্ক main()
{
    printf("SKIP\n");
}
#endif
