#ضمن <stdio.h>

/* PROMOTE_RET test: verify char/short return values are properly
   zero/sign-extended to 64-bit per the RISC-V integer calling convention.
   Without PROMOTE_RET, upper bits of the return register may contain
   garbage, causing incorrect results when assigned to a wider type.  */

بنانشان حرف get_uc(فراغ) { أرجع 0x80; }
نشانوارو حرف get_sc(فراغ) { أرجع 0x80; }
بنانشان ننڍو get_us(فراغ) { أرجع 0x8000; }
نشانوارو ننڍو get_ss(فراغ) { أرجع 0x8000; }

/* Prevent inlining to force ABI-compliant calling.  */
بنانشان حرف (* متطاير fp_uc)(فراغ) = get_uc;
نشانوارو حرف (* متطاير fp_sc)(فراغ) = get_sc;
بنانشان ننڍو (* متطاير fp_us)(فراغ) = get_us;
نشانوارو ننڍو (* متطاير fp_ss)(فراغ) = get_ss;

صحيح promote_main(فراغ)
{
    صحيح ok = 1;
    بنانشان ڊگهو ڊگهو uc = fp_uc();
    نشانوارو ڊگهو ڊگهو sc = fp_sc();
    بنانشان ڊگهو ڊگهو us = fp_us();
    نشانوارو ڊگهو ڊگهو ss = fp_ss();

    لکو("uc=%llx sc=%llx us=%llx ss=%llx\n",
           (بنانشان ڊگهو ڊگهو)uc,
           (بنانشان ڊگهو ڊگهو)sc,
           (بنانشان ڊگهو ڊگهو)us,
           (بنانشان ڊگهو ڊگهو)ss);

    إذا (uc != 0x80) {
        لکو("FAIL: uc not zero-extended\n");
        ok = 0;
    }
    إذا (sc != 0xffffffffffffff80LL) {
        لکو("FAIL: sc not sign-extended\n");
        ok = 0;
    }
    إذا (us != 0x8000) {
        لکو("FAIL: us not zero-extended\n");
        ok = 0;
    }
    إذا (ss != 0xffffffffffff8000LL) {
        لکو("FAIL: ss not sign-extended\n");
        ok = 0;
    }

    لکو("%s\n", ok ? "PASS" : "FAIL");
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
    بنانشان حرف uc = (بنانشان حرف)x + 1;
    ننڍو s = (ننڍو)x + 1;
    بنانشان ننڍو us = (بنانشان ننڍو)x + 1;

    لکو("c=%x uc=%x s=%x us=%x\n",
           (بنانشان حرف)c, (بنانشان)uc,
           (بنانشان ننڍو)s, (بنانشان)us);

    إذا (c != (حرف)0x78 + 1) {
        لکو("FAIL: char conversion\n");
        ok = 0;
    }
    إذا (uc != (بنانشان حرف)0x78 + 1) {
        لکو("FAIL: unsigned char conversion\n");
        ok = 0;
    }
    إذا (s != (ننڍو)0x5678 + 1) {
        لکو("FAIL: short conversion\n");
        ok = 0;
    }
    إذا (us != (بنانشان ننڍو)0x5678 + 1) {
        لکو("FAIL: unsigned short conversion\n");
        ok = 0;
    }

    لکو("%s\n", ok ? "PASS" : "FAIL");
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
    ڊگهو ڊگهو y = (ڊگهو ڊگهو)x;

    لکو("y=%llx\n", (بنانشان ڊگهو ڊگهو)y);

    إذا (y != 0xffffffff80000000LL) {
        لکو("FAIL: int→long long sign-extension\n");
        ok = 0;
    }

    /* Also test positive value.  */
    x = 0x40000000;
    y = (ڊگهو ڊگهو)x;
    لکو("y=%llx\n", (بنانشان ڊگهو ڊگهو)y);

    إذا (y != 0x40000000LL) {
        لکو("FAIL: int→long long positive value\n");
        ok = 0;
    }

    /* Test via unsigned int to catch zero-extension vs sign-extension.  */
    بنانشان صحيح ux = 0x80000000;
    ڊگهو ڊگهو uy = (ڊگهو ڊگهو)(صحيح)ux;
    لکو("uy=%llx\n", (بنانشان ڊگهو ڊگهو)uy);

    إذا (uy != 0xffffffff80000000LL) {
        لکو("FAIL: unsigned→int→long long sign-extension\n");
        ok = 0;
    }

    لکو("%s\n", ok ? "PASS" : "FAIL");
    أرجع ok ? 0 : 1;
}

صحيح مکيه()
{
    أرجع
        promote_main()
        | cast_main()
        | sign_main();
}
