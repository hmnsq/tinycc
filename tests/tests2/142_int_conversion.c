#ضمن <stdio.h>

/* PROMOTE_RET test: verify char/short return values are properly
   zero/sign-extended to 64-bit per the RISC-V integer calling convention.
   Without PROMOTE_RET, upper bits of the return register may contain
   garbage, causing incorrect results when assigned to a wider type.  */

بیعلامت حرف get_uc(فراغ) { أرجع 0x80; }
علامتدار حرف get_sc(فراغ) { أرجع 0x80; }
بیعلامت کوتاه get_us(فراغ) { أرجع 0x8000; }
علامتدار کوتاه get_ss(فراغ) { أرجع 0x8000; }

/* Prevent inlining to force ABI-compliant calling.  */
بیعلامت حرف (* متطاير fp_uc)(فراغ) = get_uc;
علامتدار حرف (* متطاير fp_sc)(فراغ) = get_sc;
بیعلامت کوتاه (* متطاير fp_us)(فراغ) = get_us;
علامتدار کوتاه (* متطاير fp_ss)(فراغ) = get_ss;

صحيح promote_main(فراغ)
{
    صحيح ok = 1;
    بیعلامت دراز دراز uc = fp_uc();
    علامتدار دراز دراز sc = fp_sc();
    بیعلامت دراز دراز us = fp_us();
    علامتدار دراز دراز ss = fp_ss();

    چاپ_کن("uc=%llx sc=%llx us=%llx ss=%llx\n",
           (بیعلامت دراز دراز)uc,
           (بیعلامت دراز دراز)sc,
           (بیعلامت دراز دراز)us,
           (بیعلامت دراز دراز)ss);

    إذا (uc != 0x80) {
        چاپ_کن("FAIL: uc not zero-extended\n");
        ok = 0;
    }
    إذا (sc != 0xffffffffffffff80LL) {
        چاپ_کن("FAIL: sc not sign-extended\n");
        ok = 0;
    }
    إذا (us != 0x8000) {
        چاپ_کن("FAIL: us not zero-extended\n");
        ok = 0;
    }
    إذا (ss != 0xffffffffffff8000LL) {
        چاپ_کن("FAIL: ss not sign-extended\n");
        ok = 0;
    }

    چاپ_کن("%s\n", ok ? "PASS" : "FAIL");
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
    بیعلامت حرف uc = (بیعلامت حرف)x + 1;
    کوتاه s = (کوتاه)x + 1;
    بیعلامت کوتاه us = (بیعلامت کوتاه)x + 1;

    چاپ_کن("c=%x uc=%x s=%x us=%x\n",
           (بیعلامت حرف)c, (بیعلامت)uc,
           (بیعلامت کوتاه)s, (بیعلامت)us);

    إذا (c != (حرف)0x78 + 1) {
        چاپ_کن("FAIL: char conversion\n");
        ok = 0;
    }
    إذا (uc != (بیعلامت حرف)0x78 + 1) {
        چاپ_کن("FAIL: unsigned char conversion\n");
        ok = 0;
    }
    إذا (s != (کوتاه)0x5678 + 1) {
        چاپ_کن("FAIL: short conversion\n");
        ok = 0;
    }
    إذا (us != (بیعلامت کوتاه)0x5678 + 1) {
        چاپ_کن("FAIL: unsigned short conversion\n");
        ok = 0;
    }

    چاپ_کن("%s\n", ok ? "PASS" : "FAIL");
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
    دراز دراز y = (دراز دراز)x;

    چاپ_کن("y=%llx\n", (بیعلامت دراز دراز)y);

    إذا (y != 0xffffffff80000000LL) {
        چاپ_کن("FAIL: int→long long sign-extension\n");
        ok = 0;
    }

    /* Also test positive value.  */
    x = 0x40000000;
    y = (دراز دراز)x;
    چاپ_کن("y=%llx\n", (بیعلامت دراز دراز)y);

    إذا (y != 0x40000000LL) {
        چاپ_کن("FAIL: int→long long positive value\n");
        ok = 0;
    }

    /* Test via unsigned int to catch zero-extension vs sign-extension.  */
    بیعلامت صحيح ux = 0x80000000;
    دراز دراز uy = (دراز دراز)(صحيح)ux;
    چاپ_کن("uy=%llx\n", (بیعلامت دراز دراز)uy);

    إذا (uy != 0xffffffff80000000LL) {
        چاپ_کن("FAIL: unsigned→int→long long sign-extension\n");
        ok = 0;
    }

    چاپ_کن("%s\n", ok ? "PASS" : "FAIL");
    أرجع ok ? 0 : 1;
}

صحيح اصلی()
{
    أرجع
        promote_main()
        | cast_main()
        | sign_main();
}
