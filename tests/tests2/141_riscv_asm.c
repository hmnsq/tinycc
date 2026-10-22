#अन्तर्भाव <stdio.h>

#ifdef __riscv

/* P0.4 + P1.4: riscv64 asm pseudo-instructions test.
   Exercises neg/negw, sext.w, fmv.s/d, fneg.s/d.  */

पूर्णाङ्क test_neg(पूर्णाङ्क x)
{
    पूर्णाङ्क r;
    यंत्र("neg %0, %1" : "=r"(r) : "r"(x));
    फर्काऊ r;
}

दीर्घ दीर्घ test_negw(दीर्घ दीर्घ x)
{
    पूर्णाङ्क r;
    यंत्र("negw %0, %1" : "=r"(r) : "r"((पूर्णाङ्क)x));
    फर्काऊ (दीर्घ दीर्घ)r;
}

दीर्घ दीर्घ test_sextw(पूर्णाङ्क x)
{
    दीर्घ दीर्घ r;
    यंत्र("sext.w %0, %1" : "=r"(r) : "r"(x));
    फर्काऊ r;
}

भिन्न test_fmv_s(भिन्न a)
{
    भिन्न r;
    यंत्र("fmv.s %0, %1" : "=f"(r) : "f"(a));
    फर्काऊ r;
}

भिन्न test_fneg_s(भिन्न a)
{
    भिन्न r;
    यंत्र("fneg.s %0, %1" : "=f"(r) : "f"(a));
    फर्काऊ r;
}

द्विगुण test_fmv_d(द्विगुण a)
{
    द्विगुण r;
    यंत्र("fmv.d %0, %1" : "=f"(r) : "f"(a));
    फर्काऊ r;
}

द्विगुण test_fneg_d(द्विगुण a)
{
    द्विगुण r;
    यंत्र("fneg.d %0, %1" : "=f"(r) : "f"(a));
    फर्काऊ r;
}

पूर्णाङ्क test_pseudo(शून्य)
{
    पूर्णाङ्क ok = 1;

    यदि (test_neg(42) != -42) {
        म_लिखो("FAIL: neg\n");
        ok = 0;
    }
    यदि (test_negw(100) != -100) {
        म_लिखो("FAIL: negw\n");
        ok = 0;
    }
    यदि (test_sextw(0x80000000) != 0xffffffff80000000LL) {
        म_लिखो("FAIL: sext.w\n");
        ok = 0;
    }
    यदि (test_fmv_s(3.14f) != 3.14f) {
        म_लिखो("FAIL: fmv.s\n");
        ok = 0;
    }
    यदि (test_fneg_s(3.14f) != -3.14f) {
        म_लिखो("FAIL: fneg.s\n");
        ok = 0;
    }
    यदि (test_fmv_d(2.718281828) != 2.718281828) {
        म_लिखो("FAIL: fmv.d\n");
        ok = 0;
    }
    यदि (test_fneg_d(2.718281828) != -2.718281828) {
        म_लिखो("FAIL: fneg.d\n");
        ok = 0;
    }
    फर्काऊ ok;
}

/* P1.1: riscv64 inline asm with 64-bit immediate (li).
   Tests that long long immediates assemble correctly,
   including the lui+addi sequence for large constants.  */

दीर्घ दीर्घ test_li_small(शून्य)
{
    दीर्घ दीर्घ r;
    यंत्र("li %0, 42" : "=r"(r));
    फर्काऊ r;
}

दीर्घ दीर्घ test_li_large(शून्य)
{
    दीर्घ दीर्घ r;
    यंत्र("li %0, 0x123456789ABCDEF0" : "=r"(r));
    फर्काऊ r;
}

दीर्घ दीर्घ test_li_negative(शून्य)
{
    दीर्घ दीर्घ r;
    यंत्र("li %0, -1" : "=r"(r));
    फर्काऊ r;
}

पूर्णाङ्क test_ll(शून्य)
{
    पूर्णाङ्क ok = 1;

    यदि (test_li_small() != 42) {
        म_लिखो("FAIL: li small\n");
        ok = 0;
    }
    यदि (test_li_large() != 0x123456789ABCDEF0LL) {
        म_लिखो("FAIL: li large\n");
        ok = 0;
    }
    यदि (test_li_negative() != -1) {
        म_लिखो("FAIL: li negative\n");
        ok = 0;
    }
    फर्काऊ ok;
}

/* P1.3: riscv64 F/D extension arithmetic instructions.
   Tests fadd/fsub/fmul/fdiv for both single and double precision.  */

भिन्न test_fadd_s(भिन्न a, भिन्न b)
{
    भिन्न r;
    यंत्र("fadd.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    फर्काऊ r;
}

भिन्न test_fsub_s(भिन्न a, भिन्न b)
{
    भिन्न r;
    यंत्र("fsub.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    फर्काऊ r;
}

भिन्न test_fmul_s(भिन्न a, भिन्न b)
{
    भिन्न r;
    यंत्र("fmul.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    फर्काऊ r;
}

भिन्न test_fdiv_s(भिन्न a, भिन्न b)
{
    भिन्न r;
    यंत्र("fdiv.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    फर्काऊ r;
}

द्विगुण test_fadd_d(द्विगुण a, द्विगुण b)
{
    द्विगुण r;
    यंत्र("fadd.d %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    फर्काऊ r;
}

द्विगुण test_fsub_d(द्विगुण a, द्विगुण b)
{
    द्विगुण r;
    यंत्र("fsub.d %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    फर्काऊ r;
}

द्विगुण test_fmul_d(द्विगुण a, द्विगुण b)
{
    द्विगुण r;
    यंत्र("fmul.d %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    फर्काऊ r;
}

द्विगुण test_fdiv_d(द्विगुण a, द्विगुण b)
{
    द्विगुण r;
    यंत्र("fdiv.d %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    फर्काऊ r;
}

पूर्णाङ्क test_farith(शून्य)
{
    पूर्णाङ्क ok = 1;

    यदि (test_fadd_s(1.5f, 2.5f) != 4.0f) {
        म_लिखो("FAIL: fadd.s\n");
        ok = 0;
    }
    यदि (test_fsub_s(5.0f, 2.0f) != 3.0f) {
        म_लिखो("FAIL: fsub.s\n");
        ok = 0;
    }
    यदि (test_fmul_s(3.0f, 4.0f) != 12.0f) {
        म_लिखो("FAIL: fmul.s\n");
        ok = 0;
    }
    यदि (test_fdiv_s(12.0f, 4.0f) != 3.0f) {
        म_लिखो("FAIL: fdiv.s\n");
        ok = 0;
    }

    यदि (test_fadd_d(1.5, 2.5) != 4.0) {
        म_लिखो("FAIL: fadd.d\n");
        ok = 0;
    }
    यदि (test_fsub_d(5.0, 2.0) != 3.0) {
        म_लिखो("FAIL: fsub.d\n");
        ok = 0;
    }
    यदि (test_fmul_d(3.0, 4.0) != 12.0) {
        म_लिखो("FAIL: fmul.d\n");
        ok = 0;
    }
    यदि (test_fdiv_d(12.0, 4.0) != 3.0) {
        म_लिखो("FAIL: fdiv.d\n");
        ok = 0;
    }
    फर्काऊ ok;
}

पूर्णाङ्क csr_pseudo_main(शून्य)
{
    पूर्णाङ्क ok = 1;
    पूर्णाङ्क old, tmp;

    यंत्र चञ्चल("csrr %0, 0x003" : "=r"(old));

    यंत्र चञ्चल("csrr %0, 0x003" : "=r"(tmp));
    म_लिखो("csrr fcsr=%x\n", (अचिन्हित)tmp);

    यंत्र चञ्चल("csrw 0x003, %0" : : "r"(0xE0));
    यंत्र चञ्चल("csrr %0, 0x003" : "=r"(tmp));
    म_लिखो("csrw: wrote e0 got %x\n", (अचिन्हित)tmp);
    यदि (tmp != 0xE0) { म_लिखो("FAIL: csrw\n"); ok = 0; }
    यंत्र चञ्चल("csrw 0x003, %0" : : "r"(old));

    यंत्र चञ्चल("csrwi 0x003, 0x10");
    यंत्र चञ्चल("csrr %0, 0x003" : "=r"(tmp));
    म_लिखो("csrwi: wrote 0x10 got %x\n", (अचिन्हित)tmp);
    यदि (tmp != 0x10) { म_लिखो("FAIL: csrwi\n"); ok = 0; }
    यंत्र चञ्चल("csrw 0x003, %0" : : "r"(old));

    यंत्र चञ्चल("csrsi 0x003, 0x03");
    यंत्र चञ्चल("csrr %0, 0x003" : "=r"(tmp));
    म_लिखो("csrsi: old|3=%x\n", (अचिन्हित)tmp);
    यदि ((old | 0x03) != tmp) { म_लिखो("FAIL: csrsi\n"); ok = 0; }
    यंत्र चञ्चल("csrw 0x003, %0" : : "r"(old));

    यंत्र चञ्चल("csrci 0x003, 0x03");
    यंत्र चञ्चल("csrr %0, 0x003" : "=r"(tmp));
    म_लिखो("csrci: old&~3=%x\n", (अचिन्हित)tmp);
    यदि ((old & ~0x03) != tmp) { म_लिखो("FAIL: csrci\n"); ok = 0; }
    यंत्र चञ्चल("csrw 0x003, %0" : : "r"(old));

    फर्काऊ ok;
}

पूर्णाङ्क fp_cmp_cvt_main(शून्य)
{
    /* F/D comparison (use raw regs to avoid inline asm float→int bug) */
    यंत्र चञ्चल("feq.s a0, fa0, fa1");
    यंत्र चञ्चल("feq.d a0, fa0, fa1");
    यंत्र चञ्चल("flt.s a0, fa0, fa1");
    यंत्र चञ्चल("flt.d a0, fa0, fa1");
    यंत्र चञ्चल("fle.s a0, fa0, fa1");
    यंत्र चञ्चल("fle.d a0, fa0, fa1");

    /* fcvt conversions */
    यंत्र चञ्चल("fcvt.w.s a0, fa0");
    यंत्र चञ्चल("fcvt.wu.s a0, fa0");
    यंत्र चञ्चल("fcvt.s.w fa0, a0");
    यंत्र चञ्चल("fcvt.w.d a0, fa0");
    यंत्र चञ्चल("fcvt.d.w fa0, a0");
    यंत्र चञ्चल("fcvt.d.s fa0, fa0");
    यंत्र चञ्चल("fcvt.s.d fa0, fa0");

    /* fclass */
    यंत्र चञ्चल("fclass.s a0, fa0");
    यंत्र चञ्चल("fclass.d a0, fa0");

    फर्काऊ 1;
}

पूर्णाङ्क amo_main(शून्य)
{
    पूर्णाङ्क x = 0, r;
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
    फर्काऊ 1;
}

पूर्णाङ्क fcvt_round_main(शून्य)
{
    यंत्र चञ्चल("fcvt.w.s a0, fa0, rne");
    यंत्र चञ्चल("fcvt.w.s a0, fa0, rtz");
    यंत्र चञ्चल("fcvt.w.s a0, fa0, rup");
    यंत्र चञ्चल("fcvt.w.d a0, fa0, rne");
    यंत्र चञ्चल("fcvt.w.d a0, fa0, rtz");
    फर्काऊ 1;
}

पूर्णाङ्क main()
{
    पूर्णाङ्क ok = 1;
    ok &= test_pseudo();
    ok &= test_ll();
    ok &= test_farith();
    ok &= csr_pseudo_main();
    ok &= fp_cmp_cvt_main();
    ok &= amo_main();
    ok &= fcvt_round_main();
    म_लिखो("%s\n", ok ? "PASS" : "FAIL");
    फर्काऊ !ok;
}

#अन्यथा
पूर्णाङ्क main()
{
    म_लिखो("SKIP\n");
}
#endif
