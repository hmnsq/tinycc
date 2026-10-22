#समावेश <stdio.h>

#अगर_घोषित __riscv

/* P0.4 + P1.4: riscv64 asm pseudo-instructions test.
   Exercises neg/negw, sext.w, fmv.s/d, fneg.s/d.  */

पूर्णांक test_neg(पूर्णांक x)
{
    पूर्णांक r;
    यंत्र("neg %0, %1" : "=r"(r) : "r"(x));
    वापस r;
}

दीर्घ दीर्घ test_negw(दीर्घ दीर्घ x)
{
    पूर्णांक r;
    यंत्र("negw %0, %1" : "=r"(r) : "r"((पूर्णांक)x));
    वापस (दीर्घ दीर्घ)r;
}

दीर्घ दीर्घ test_sextw(पूर्णांक x)
{
    दीर्घ दीर्घ r;
    यंत्र("sext.w %0, %1" : "=r"(r) : "r"(x));
    वापस r;
}

भग्न test_fmv_s(भग्न a)
{
    भग्न r;
    यंत्र("fmv.s %0, %1" : "=f"(r) : "f"(a));
    वापस r;
}

भग्न test_fneg_s(भग्न a)
{
    भग्न r;
    यंत्र("fneg.s %0, %1" : "=f"(r) : "f"(a));
    वापस r;
}

द्विगुन test_fmv_d(द्विगुन a)
{
    द्विगुन r;
    यंत्र("fmv.d %0, %1" : "=f"(r) : "f"(a));
    वापस r;
}

द्विगुन test_fneg_d(द्विगुन a)
{
    द्विगुन r;
    यंत्र("fneg.d %0, %1" : "=f"(r) : "f"(a));
    वापस r;
}

पूर्णांक test_pseudo(व्योम)
{
    पूर्णांक ok = 1;

    अगर (test_neg(42) != -42) {
        म_लिखो("FAIL: neg\n");
        ok = 0;
    }
    अगर (test_negw(100) != -100) {
        म_लिखो("FAIL: negw\n");
        ok = 0;
    }
    अगर (test_sextw(0x80000000) != 0xffffffff80000000LL) {
        म_लिखो("FAIL: sext.w\n");
        ok = 0;
    }
    अगर (test_fmv_s(3.14f) != 3.14f) {
        म_लिखो("FAIL: fmv.s\n");
        ok = 0;
    }
    अगर (test_fneg_s(3.14f) != -3.14f) {
        म_लिखो("FAIL: fneg.s\n");
        ok = 0;
    }
    अगर (test_fmv_d(2.718281828) != 2.718281828) {
        म_लिखो("FAIL: fmv.d\n");
        ok = 0;
    }
    अगर (test_fneg_d(2.718281828) != -2.718281828) {
        म_लिखो("FAIL: fneg.d\n");
        ok = 0;
    }
    वापस ok;
}

/* P1.1: riscv64 inline asm with 64-bit immediate (li).
   Tests that long long immediates assemble correctly,
   including the lui+addi sequence for large constants.  */

दीर्घ दीर्घ test_li_small(व्योम)
{
    दीर्घ दीर्घ r;
    यंत्र("li %0, 42" : "=r"(r));
    वापस r;
}

दीर्घ दीर्घ test_li_large(व्योम)
{
    दीर्घ दीर्घ r;
    यंत्र("li %0, 0x123456789ABCDEF0" : "=r"(r));
    वापस r;
}

दीर्घ दीर्घ test_li_negative(व्योम)
{
    दीर्घ दीर्घ r;
    यंत्र("li %0, -1" : "=r"(r));
    वापस r;
}

पूर्णांक test_ll(व्योम)
{
    पूर्णांक ok = 1;

    अगर (test_li_small() != 42) {
        म_लिखो("FAIL: li small\n");
        ok = 0;
    }
    अगर (test_li_large() != 0x123456789ABCDEF0LL) {
        म_लिखो("FAIL: li large\n");
        ok = 0;
    }
    अगर (test_li_negative() != -1) {
        म_लिखो("FAIL: li negative\n");
        ok = 0;
    }
    वापस ok;
}

/* P1.3: riscv64 F/D extension arithmetic instructions.
   Tests fadd/fsub/fmul/fdiv for both single and double precision.  */

भग्न test_fadd_s(भग्न a, भग्न b)
{
    भग्न r;
    यंत्र("fadd.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    वापस r;
}

भग्न test_fsub_s(भग्न a, भग्न b)
{
    भग्न r;
    यंत्र("fsub.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    वापस r;
}

भग्न test_fmul_s(भग्न a, भग्न b)
{
    भग्न r;
    यंत्र("fmul.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    वापस r;
}

भग्न test_fdiv_s(भग्न a, भग्न b)
{
    भग्न r;
    यंत्र("fdiv.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    वापस r;
}

द्विगुन test_fadd_d(द्विगुन a, द्विगुन b)
{
    द्विगुन r;
    यंत्र("fadd.d %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    वापस r;
}

द्विगुन test_fsub_d(द्विगुन a, द्विगुन b)
{
    द्विगुन r;
    यंत्र("fsub.d %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    वापस r;
}

द्विगुन test_fmul_d(द्विगुन a, द्विगुन b)
{
    द्विगुन r;
    यंत्र("fmul.d %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    वापस r;
}

द्विगुन test_fdiv_d(द्विगुन a, द्विगुन b)
{
    द्विगुन r;
    यंत्र("fdiv.d %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    वापस r;
}

पूर्णांक test_farith(व्योम)
{
    पूर्णांक ok = 1;

    अगर (test_fadd_s(1.5f, 2.5f) != 4.0f) {
        म_लिखो("FAIL: fadd.s\n");
        ok = 0;
    }
    अगर (test_fsub_s(5.0f, 2.0f) != 3.0f) {
        म_लिखो("FAIL: fsub.s\n");
        ok = 0;
    }
    अगर (test_fmul_s(3.0f, 4.0f) != 12.0f) {
        म_लिखो("FAIL: fmul.s\n");
        ok = 0;
    }
    अगर (test_fdiv_s(12.0f, 4.0f) != 3.0f) {
        म_लिखो("FAIL: fdiv.s\n");
        ok = 0;
    }

    अगर (test_fadd_d(1.5, 2.5) != 4.0) {
        म_लिखो("FAIL: fadd.d\n");
        ok = 0;
    }
    अगर (test_fsub_d(5.0, 2.0) != 3.0) {
        म_लिखो("FAIL: fsub.d\n");
        ok = 0;
    }
    अगर (test_fmul_d(3.0, 4.0) != 12.0) {
        म_लिखो("FAIL: fmul.d\n");
        ok = 0;
    }
    अगर (test_fdiv_d(12.0, 4.0) != 3.0) {
        म_लिखो("FAIL: fdiv.d\n");
        ok = 0;
    }
    वापस ok;
}

पूर्णांक csr_pseudo_main(व्योम)
{
    पूर्णांक ok = 1;
    पूर्णांक old, tmp;

    यंत्र अस्थिर("csrr %0, 0x003" : "=r"(old));

    यंत्र अस्थिर("csrr %0, 0x003" : "=r"(tmp));
    म_लिखो("csrr fcsr=%x\n", (अचिन्हित)tmp);

    यंत्र अस्थिर("csrw 0x003, %0" : : "r"(0xE0));
    यंत्र अस्थिर("csrr %0, 0x003" : "=r"(tmp));
    म_लिखो("csrw: wrote e0 got %x\n", (अचिन्हित)tmp);
    अगर (tmp != 0xE0) { म_लिखो("FAIL: csrw\n"); ok = 0; }
    यंत्र अस्थिर("csrw 0x003, %0" : : "r"(old));

    यंत्र अस्थिर("csrwi 0x003, 0x10");
    यंत्र अस्थिर("csrr %0, 0x003" : "=r"(tmp));
    म_लिखो("csrwi: wrote 0x10 got %x\n", (अचिन्हित)tmp);
    अगर (tmp != 0x10) { म_लिखो("FAIL: csrwi\n"); ok = 0; }
    यंत्र अस्थिर("csrw 0x003, %0" : : "r"(old));

    यंत्र अस्थिर("csrsi 0x003, 0x03");
    यंत्र अस्थिर("csrr %0, 0x003" : "=r"(tmp));
    म_लिखो("csrsi: old|3=%x\n", (अचिन्हित)tmp);
    अगर ((old | 0x03) != tmp) { म_लिखो("FAIL: csrsi\n"); ok = 0; }
    यंत्र अस्थिर("csrw 0x003, %0" : : "r"(old));

    यंत्र अस्थिर("csrci 0x003, 0x03");
    यंत्र अस्थिर("csrr %0, 0x003" : "=r"(tmp));
    म_लिखो("csrci: old&~3=%x\n", (अचिन्हित)tmp);
    अगर ((old & ~0x03) != tmp) { म_लिखो("FAIL: csrci\n"); ok = 0; }
    यंत्र अस्थिर("csrw 0x003, %0" : : "r"(old));

    वापस ok;
}

पूर्णांक fp_cmp_cvt_main(व्योम)
{
    /* F/D comparison (use raw regs to avoid inline asm float→int bug) */
    यंत्र अस्थिर("feq.s a0, fa0, fa1");
    यंत्र अस्थिर("feq.d a0, fa0, fa1");
    यंत्र अस्थिर("flt.s a0, fa0, fa1");
    यंत्र अस्थिर("flt.d a0, fa0, fa1");
    यंत्र अस्थिर("fle.s a0, fa0, fa1");
    यंत्र अस्थिर("fle.d a0, fa0, fa1");

    /* fcvt conversions */
    यंत्र अस्थिर("fcvt.w.s a0, fa0");
    यंत्र अस्थिर("fcvt.wu.s a0, fa0");
    यंत्र अस्थिर("fcvt.s.w fa0, a0");
    यंत्र अस्थिर("fcvt.w.d a0, fa0");
    यंत्र अस्थिर("fcvt.d.w fa0, a0");
    यंत्र अस्थिर("fcvt.d.s fa0, fa0");
    यंत्र अस्थिर("fcvt.s.d fa0, fa0");

    /* fclass */
    यंत्र अस्थिर("fclass.s a0, fa0");
    यंत्र अस्थिर("fclass.d a0, fa0");

    वापस 1;
}

पूर्णांक amo_main(व्योम)
{
    पूर्णांक x = 0, r;
    दीर्घ दीर्घ xd = 0xCAFEBABECAFEBABELL, rd, val = 0xDEADBEEFDEADBEEFLL;
    यंत्र("amoadd.w %0, %2, (%1)" : "=r"(r) : "r"(&x), "r"(val));
    यंत्र("amoswap.w %0, %2, (%1)" : "=r"(r) : "r"(&x), "r"(val));
    यंत्र("amoand.w %0, %2, (%1)" : "=r"(r) : "r"(&x), "r"(val));
    यंत्र("amoor.d %0, %2, (%1)" : "=r"(rd) : "r"(&xd), "r"(val));
    यंत्र("amoxor.w %0, %2, (%1)" : "=r"(r) : "r"(&x), "r"(val));
    यंत्र("amomax.w %0, %2, (%1)" : "=r"(r) : "r"(&x), "r"(val));
    यंत्र("amomaxu.d %0, %2, (%1)" : "=r"(rd) : "r"(&xd), "r"(val));
    यंत्र("amomin.w %0, %2, (%1)" : "=r"(r) : "r"(&x), "r"(val));
    यंत्र("amominu.d %0, %2, (%1)" : "=r"(rd) : "r"(&xd), "r"(val));
    यंत्र("amoadd.w.aq %0, %2, (%1)" : "=r"(r) : "r"(&x), "r"(val));
    यंत्र("amoadd.w.rl %0, %2, (%1)" : "=r"(r) : "r"(&x), "r"(val));
    यंत्र("amoadd.d.aqrl %0, %2, (%1)" : "=r"(rd) : "r"(&xd), "r"(val));
    यंत्र("amoswap.w.aq %0, %2, (%1)" : "=r"(r) : "r"(&x), "r"(val));
    यंत्र("amoswap.d.rl %0, %2, (%1)" : "=r"(rd) : "r"(&xd), "r"(val));
    यंत्र("amoand.w.aqrl %0, %2, (%1)" : "=r"(r) : "r"(&x), "r"(val));
    यंत्र("amoor.w.rl %0, %2, (%1)" : "=r"(r) : "r"(&x), "r"(val));
    यंत्र("amoor.d.aq %0, %2, (%1)" : "=r"(rd) : "r"(&xd), "r"(val));
    यंत्र("amoxor.w.aq %0, %2, (%1)" : "=r"(r) : "r"(&x), "r"(val));
    यंत्र("amomax.d.rl %0, %2, (%1)" : "=r"(rd) : "r"(&xd), "r"(val));
    यंत्र("amomaxu.w.aqrl %0, %2, (%1)" : "=r"(r) : "r"(&x), "r"(val));
    यंत्र("amomin.w.rl %0, %2, (%1)" : "=r"(r) : "r"(&x), "r"(val));
    यंत्र("amominu.d.aq %0, %2, (%1)" : "=r"(rd) : "r"(&xd), "r"(val));
    वापस 1;
}

पूर्णांक fcvt_round_main(व्योम)
{
    यंत्र अस्थिर("fcvt.w.s a0, fa0, rne");
    यंत्र अस्थिर("fcvt.w.s a0, fa0, rtz");
    यंत्र अस्थिर("fcvt.w.s a0, fa0, rup");
    यंत्र अस्थिर("fcvt.w.d a0, fa0, rne");
    यंत्र अस्थिर("fcvt.w.d a0, fa0, rtz");
    वापस 1;
}

पूर्णांक मुख्य()
{
    पूर्णांक ok = 1;
    ok &= test_pseudo();
    ok &= test_ll();
    ok &= test_farith();
    ok &= csr_pseudo_main();
    ok &= fp_cmp_cvt_main();
    ok &= amo_main();
    ok &= fcvt_round_main();
    म_लिखो("%s\n", ok ? "PASS" : "FAIL");
    वापस !ok;
}

#अन्यथा
पूर्णांक मुख्य()
{
    म_लिखो("SKIP\n");
}
#पूर्ण_अगर
