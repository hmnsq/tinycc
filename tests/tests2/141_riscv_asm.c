#شامل <stdio.h>

#اگر_تعریف_شدہ __riscv

/* P0.4 + P1.4: riscv64 asm pseudo-instructions test.
   Exercises neg/negw, sext.w, fmv.s/d, fneg.s/d.  */

صحیح test_neg(صحیح x)
{
    صحیح r;
    asm("neg %0, %1" : "=r"(r) : "r"(x));
    واپس r;
}

طویل طویل test_negw(طویل طویل x)
{
    صحیح r;
    asm("negw %0, %1" : "=r"(r) : "r"((صحیح)x));
    واپس (طویل طویل)r;
}

طویل طویل test_sextw(صحیح x)
{
    طویل طویل r;
    asm("sext.w %0, %1" : "=r"(r) : "r"(x));
    واپس r;
}

اعشاری test_fmv_s(اعشاری a)
{
    اعشاری r;
    asm("fmv.s %0, %1" : "=f"(r) : "f"(a));
    واپس r;
}

اعشاری test_fneg_s(اعشاری a)
{
    اعشاری r;
    asm("fneg.s %0, %1" : "=f"(r) : "f"(a));
    واپس r;
}

دوہرا test_fmv_d(دوہرا a)
{
    دوہرا r;
    asm("fmv.d %0, %1" : "=f"(r) : "f"(a));
    واپس r;
}

دوہرا test_fneg_d(دوہرا a)
{
    دوہرا r;
    asm("fneg.d %0, %1" : "=f"(r) : "f"(a));
    واپس r;
}

صحیح test_pseudo(خالی)
{
    صحیح ok = 1;

    اگر (test_neg(42) != -42) {
        لکھو("FAIL: neg\n");
        ok = 0;
    }
    اگر (test_negw(100) != -100) {
        لکھو("FAIL: negw\n");
        ok = 0;
    }
    اگر (test_sextw(0x80000000) != 0xffffffff80000000LL) {
        لکھو("FAIL: sext.w\n");
        ok = 0;
    }
    اگر (test_fmv_s(3.14f) != 3.14f) {
        لکھو("FAIL: fmv.s\n");
        ok = 0;
    }
    اگر (test_fneg_s(3.14f) != -3.14f) {
        لکھو("FAIL: fneg.s\n");
        ok = 0;
    }
    اگر (test_fmv_d(2.718281828) != 2.718281828) {
        لکھو("FAIL: fmv.d\n");
        ok = 0;
    }
    اگر (test_fneg_d(2.718281828) != -2.718281828) {
        لکھو("FAIL: fneg.d\n");
        ok = 0;
    }
    واپس ok;
}

/* P1.1: riscv64 inline asm with 64-bit immediate (li).
   Tests that long long immediates assemble correctly,
   including the lui+addi sequence for large constants.  */

طویل طویل test_li_small(خالی)
{
    طویل طویل r;
    asm("li %0, 42" : "=r"(r));
    واپس r;
}

طویل طویل test_li_large(خالی)
{
    طویل طویل r;
    asm("li %0, 0x123456789ABCDEF0" : "=r"(r));
    واپس r;
}

طویل طویل test_li_negative(خالی)
{
    طویل طویل r;
    asm("li %0, -1" : "=r"(r));
    واپس r;
}

صحیح test_ll(خالی)
{
    صحیح ok = 1;

    اگر (test_li_small() != 42) {
        لکھو("FAIL: li small\n");
        ok = 0;
    }
    اگر (test_li_large() != 0x123456789ABCDEF0LL) {
        لکھو("FAIL: li large\n");
        ok = 0;
    }
    اگر (test_li_negative() != -1) {
        لکھو("FAIL: li negative\n");
        ok = 0;
    }
    واپس ok;
}

/* P1.3: riscv64 F/D extension arithmetic instructions.
   Tests fadd/fsub/fmul/fdiv for both single and double precision.  */

اعشاری test_fadd_s(اعشاری a, اعشاری b)
{
    اعشاری r;
    asm("fadd.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    واپس r;
}

اعشاری test_fsub_s(اعشاری a, اعشاری b)
{
    اعشاری r;
    asm("fsub.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    واپس r;
}

اعشاری test_fmul_s(اعشاری a, اعشاری b)
{
    اعشاری r;
    asm("fmul.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    واپس r;
}

اعشاری test_fdiv_s(اعشاری a, اعشاری b)
{
    اعشاری r;
    asm("fdiv.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    واپس r;
}

دوہرا test_fadd_d(دوہرا a, دوہرا b)
{
    دوہرا r;
    asm("fadd.d %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    واپس r;
}

دوہرا test_fsub_d(دوہرا a, دوہرا b)
{
    دوہرا r;
    asm("fsub.d %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    واپس r;
}

دوہرا test_fmul_d(دوہرا a, دوہرا b)
{
    دوہرا r;
    asm("fmul.d %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    واپس r;
}

دوہرا test_fdiv_d(دوہرا a, دوہرا b)
{
    دوہرا r;
    asm("fdiv.d %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    واپس r;
}

صحیح test_farith(خالی)
{
    صحیح ok = 1;

    اگر (test_fadd_s(1.5f, 2.5f) != 4.0f) {
        لکھو("FAIL: fadd.s\n");
        ok = 0;
    }
    اگر (test_fsub_s(5.0f, 2.0f) != 3.0f) {
        لکھو("FAIL: fsub.s\n");
        ok = 0;
    }
    اگر (test_fmul_s(3.0f, 4.0f) != 12.0f) {
        لکھو("FAIL: fmul.s\n");
        ok = 0;
    }
    اگر (test_fdiv_s(12.0f, 4.0f) != 3.0f) {
        لکھو("FAIL: fdiv.s\n");
        ok = 0;
    }

    اگر (test_fadd_d(1.5, 2.5) != 4.0) {
        لکھو("FAIL: fadd.d\n");
        ok = 0;
    }
    اگر (test_fsub_d(5.0, 2.0) != 3.0) {
        لکھو("FAIL: fsub.d\n");
        ok = 0;
    }
    اگر (test_fmul_d(3.0, 4.0) != 12.0) {
        لکھو("FAIL: fmul.d\n");
        ok = 0;
    }
    اگر (test_fdiv_d(12.0, 4.0) != 3.0) {
        لکھو("FAIL: fdiv.d\n");
        ok = 0;
    }
    واپس ok;
}

صحیح csr_pseudo_main(خالی)
{
    صحیح ok = 1;
    صحیح old, tmp;

    asm متلون("csrr %0, 0x003" : "=r"(old));

    asm متلون("csrr %0, 0x003" : "=r"(tmp));
    لکھو("csrr fcsr=%x\n", (غیرعلامتی)tmp);

    asm متلون("csrw 0x003, %0" : : "r"(0xE0));
    asm متلون("csrr %0, 0x003" : "=r"(tmp));
    لکھو("csrw: wrote e0 got %x\n", (غیرعلامتی)tmp);
    اگر (tmp != 0xE0) { لکھو("FAIL: csrw\n"); ok = 0; }
    asm متلون("csrw 0x003, %0" : : "r"(old));

    asm متلون("csrwi 0x003, 0x10");
    asm متلون("csrr %0, 0x003" : "=r"(tmp));
    لکھو("csrwi: wrote 0x10 got %x\n", (غیرعلامتی)tmp);
    اگر (tmp != 0x10) { لکھو("FAIL: csrwi\n"); ok = 0; }
    asm متلون("csrw 0x003, %0" : : "r"(old));

    asm متلون("csrsi 0x003, 0x03");
    asm متلون("csrr %0, 0x003" : "=r"(tmp));
    لکھو("csrsi: old|3=%x\n", (غیرعلامتی)tmp);
    اگر ((old | 0x03) != tmp) { لکھو("FAIL: csrsi\n"); ok = 0; }
    asm متلون("csrw 0x003, %0" : : "r"(old));

    asm متلون("csrci 0x003, 0x03");
    asm متلون("csrr %0, 0x003" : "=r"(tmp));
    لکھو("csrci: old&~3=%x\n", (غیرعلامتی)tmp);
    اگر ((old & ~0x03) != tmp) { لکھو("FAIL: csrci\n"); ok = 0; }
    asm متلون("csrw 0x003, %0" : : "r"(old));

    واپس ok;
}

صحیح fp_cmp_cvt_main(خالی)
{
    /* F/D comparison (use raw regs to avoid inline asm float→int bug) */
    asm متلون("feq.s a0, fa0, fa1");
    asm متلون("feq.d a0, fa0, fa1");
    asm متلون("flt.s a0, fa0, fa1");
    asm متلون("flt.d a0, fa0, fa1");
    asm متلون("fle.s a0, fa0, fa1");
    asm متلون("fle.d a0, fa0, fa1");

    /* fcvt conversions */
    asm متلون("fcvt.w.s a0, fa0");
    asm متلون("fcvt.wu.s a0, fa0");
    asm متلون("fcvt.s.w fa0, a0");
    asm متلون("fcvt.w.d a0, fa0");
    asm متلون("fcvt.d.w fa0, a0");
    asm متلون("fcvt.d.s fa0, fa0");
    asm متلون("fcvt.s.d fa0, fa0");

    /* fclass */
    asm متلون("fclass.s a0, fa0");
    asm متلون("fclass.d a0, fa0");

    واپس 1;
}

صحیح amo_main(خالی)
{
    صحیح x = 0, r;
    طویل طویل xd = 0xCAFEBABECAFEBABELL, rd, val = 0xDEADBEEFDEADBEEFLL;
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
    واپس 1;
}

صحیح fcvt_باری_main(خالی)
{
    asm متلون("fcvt.w.s a0, fa0, rne");
    asm متلون("fcvt.w.s a0, fa0, rtz");
    asm متلون("fcvt.w.s a0, fa0, rup");
    asm متلون("fcvt.w.d a0, fa0, rne");
    asm متلون("fcvt.w.d a0, fa0, rtz");
    واپس 1;
}

صحیح مین()
{
    صحیح ok = 1;
    ok &= test_pseudo();
    ok &= test_ll();
    ok &= test_farith();
    ok &= csr_pseudo_main();
    ok &= fp_cmp_cvt_main();
    ok &= amo_main();
    ok &= fcvt_باری_main();
    لکھو("%s\n", ok ? "PASS" : "FAIL");
    واپس !ok;
}

#ورنہ
صحیح مین()
{
    لکھو("SKIP\n");
}
#اگر_ختم
