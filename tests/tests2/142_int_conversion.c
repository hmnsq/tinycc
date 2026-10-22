#ضمن <stdio.h>

/* PROMOTE_RET test: verify char/short return values are properly
   zero/sign-extended to 64-bit per the RISC-V integer calling convention.
   Without PROMOTE_RET, upper bits of the return register may contain
   garbage, causing incorrect results when assigned to a wider type.  */

بینښه حرف get_uc(فراغ) { أرجع 0x80; }
نښهدار حرف get_sc(فراغ) { أرجع 0x80; }
بینښه لنډ get_us(فراغ) { أرجع 0x8000; }
نښهدار لنډ get_ss(فراغ) { أرجع 0x8000; }

/* Prevent inlining to force ABI-compliant calling.  */
بینښه حرف (* متطاير fp_uc)(فراغ) = get_uc;
نښهدار حرف (* متطاير fp_sc)(فراغ) = get_sc;
بینښه لنډ (* متطاير fp_us)(فراغ) = get_us;
نښهدار لنډ (* متطاير fp_ss)(فراغ) = get_ss;

صحيح promote_main(فراغ)
{
    صحيح ok = 1;
    بینښه اوږد اوږد uc = fp_uc();
    نښهدار اوږد اوږد sc = fp_sc();
    بینښه اوږد اوږد us = fp_us();
    نښهدار اوږد اوږد ss = fp_ss();

    چاپ_کړه("uc=%llx sc=%llx us=%llx ss=%llx\n",
           (بینښه اوږد اوږد)uc,
           (بینښه اوږد اوږد)sc,
           (بینښه اوږد اوږد)us,
           (بینښه اوږد اوږد)ss);

    إذا (uc != 0x80) {
        چاپ_کړه("FAIL: uc not zero-extended\n");
        ok = 0;
    }
    إذا (sc != 0xffffffffffffff80LL) {
        چاپ_کړه("FAIL: sc not sign-extended\n");
        ok = 0;
    }
    إذا (us != 0x8000) {
        چاپ_کړه("FAIL: us not zero-extended\n");
        ok = 0;
    }
    إذا (ss != 0xffffffffffff8000LL) {
        چاپ_کړه("FAIL: ss not sign-extended\n");
        ok = 0;
    }

    چاپ_کړه("%s\n", ok ? "PASS" : "FAIL");
    أرجع ok ? 0 : 1;
}

/* gen_cvt_csti test: verify narrow-type conversions in expressions.
   Without the fix, TCC's riscv64 backend could miss the conversion
   step when promoting a narrow result back to int, producing wrong
   values (e.g., treating a char as still 32-bit).  */

صحيح cast_main(فراغ)
{
    صحيح ok = 1;
    صحيح x = 0x12345678;

    /* Cast to char then add 1 — result must be 8-bit.  */
    حرف c = (حرف)x + 1;
    بینښه حرف uc = (بینښه حرف)x + 1;
    لنډ s = (لنډ)x + 1;
    بینښه لنډ us = (بینښه لنډ)x + 1;

    چاپ_کړه("c=%x uc=%x s=%x us=%x\n",
           (بینښه حرف)c, (بینښه)uc,
           (بینښه لنډ)s, (بینښه)us);

    إذا (c != (حرف)0x78 + 1) {
        چاپ_کړه("FAIL: char conversion\n");
        ok = 0;
    }
    إذا (uc != (بینښه حرف)0x78 + 1) {
        چاپ_کړه("FAIL: unsigned char conversion\n");
        ok = 0;
    }
    إذا (s != (لنډ)0x5678 + 1) {
        چاپ_کړه("FAIL: short conversion\n");
        ok = 0;
    }
    إذا (us != (بینښه لنډ)0x5678 + 1) {
        چاپ_کړه("FAIL: unsigned short conversion\n");
        ok = 0;
    }

    چاپ_کړه("%s\n", ok ? "PASS" : "FAIL");
    أرجع ok ? 0 : 1;
}

/* gen_cvt_sxtw test: verify sign-extension from 32-bit int to 64-bit long long.
   Without the fix, the riscv64 backend had an empty stub for gen_cvt_sxtw,
   leaving upper 32 bits unmodified (containing whatever was in the register
   before), so (long long)(int)x produced wrong results for negative values.  */

صحيح sign_main(فراغ)
{
    صحيح ok = 1;
    صحيح x = 0x80000000;
    اوږد اوږد y = (اوږد اوږد)x;

    چاپ_کړه("y=%llx\n", (بینښه اوږد اوږد)y);

    إذا (y != 0xffffffff80000000LL) {
        چاپ_کړه("FAIL: int→long long sign-extension\n");
        ok = 0;
    }

    /* Also test positive value.  */
    x = 0x40000000;
    y = (اوږد اوږد)x;
    چاپ_کړه("y=%llx\n", (بینښه اوږد اوږد)y);

    إذا (y != 0x40000000LL) {
        چاپ_کړه("FAIL: int→long long positive value\n");
        ok = 0;
    }

    /* Test via unsigned int to catch zero-extension vs sign-extension.  */
    بینښه صحيح ux = 0x80000000;
    اوږد اوږد uy = (اوږد اوږد)(صحيح)ux;
    چاپ_کړه("uy=%llx\n", (بینښه اوږد اوږد)uy);

    إذا (uy != 0xffffffff80000000LL) {
        چاپ_کړه("FAIL: unsigned→int→long long sign-extension\n");
        ok = 0;
    }

    چاپ_کړه("%s\n", ok ? "PASS" : "FAIL");
    أرجع ok ? 0 : 1;
}

صحيح اصلي()
{
    أرجع
        promote_main()
        | cast_main()
        | sign_main();
}
