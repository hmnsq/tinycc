#ضمن <stdio.h>

/* PROMOTE_RET test: verify char/short return values are properly
   zero/sign-extended to 64-bit per the RISC-V integer calling convention.
   Without PROMOTE_RET, upper bits of the return register may contain
   garbage, causing incorrect results when assigned to a wider type.  */

بنانشانی حرف get_uc(فراغ) { أرجع 0x80; }
نشانیوالا حرف get_sc(فراغ) { أرجع 0x80; }
بنانشانی چھوٹا get_us(فراغ) { أرجع 0x8000; }
نشانیوالا چھوٹا get_ss(فراغ) { أرجع 0x8000; }

/* Prevent inlining to force ABI-compliant calling.  */
بنانشانی حرف (* متطاير fp_uc)(فراغ) = get_uc;
نشانیوالا حرف (* متطاير fp_sc)(فراغ) = get_sc;
بنانشانی چھوٹا (* متطاير fp_us)(فراغ) = get_us;
نشانیوالا چھوٹا (* متطاير fp_ss)(فراغ) = get_ss;

صحيح promote_main(فراغ)
{
    صحيح ok = 1;
    بنانشانی لما لما uc = fp_uc();
    نشانیوالا لما لما sc = fp_sc();
    بنانشانی لما لما us = fp_us();
    نشانیوالا لما لما ss = fp_ss();

    لکھو("uc=%llx sc=%llx us=%llx ss=%llx\n",
           (بنانشانی لما لما)uc,
           (بنانشانی لما لما)sc,
           (بنانشانی لما لما)us,
           (بنانشانی لما لما)ss);

    إذا (uc != 0x80) {
        لکھو("FAIL: uc not zero-extended\n");
        ok = 0;
    }
    إذا (sc != 0xffffffffffffff80LL) {
        لکھو("FAIL: sc not sign-extended\n");
        ok = 0;
    }
    إذا (us != 0x8000) {
        لکھو("FAIL: us not zero-extended\n");
        ok = 0;
    }
    إذا (ss != 0xffffffffffff8000LL) {
        لکھو("FAIL: ss not sign-extended\n");
        ok = 0;
    }

    لکھو("%s\n", ok ? "PASS" : "FAIL");
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
    بنانشانی حرف uc = (بنانشانی حرف)x + 1;
    چھوٹا s = (چھوٹا)x + 1;
    بنانشانی چھوٹا us = (بنانشانی چھوٹا)x + 1;

    لکھو("c=%x uc=%x s=%x us=%x\n",
           (بنانشانی حرف)c, (بنانشانی)uc,
           (بنانشانی چھوٹا)s, (بنانشانی)us);

    إذا (c != (حرف)0x78 + 1) {
        لکھو("FAIL: char conversion\n");
        ok = 0;
    }
    إذا (uc != (بنانشانی حرف)0x78 + 1) {
        لکھو("FAIL: unsigned char conversion\n");
        ok = 0;
    }
    إذا (s != (چھوٹا)0x5678 + 1) {
        لکھو("FAIL: short conversion\n");
        ok = 0;
    }
    إذا (us != (بنانشانی چھوٹا)0x5678 + 1) {
        لکھو("FAIL: unsigned short conversion\n");
        ok = 0;
    }

    لکھو("%s\n", ok ? "PASS" : "FAIL");
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
    لما لما y = (لما لما)x;

    لکھو("y=%llx\n", (بنانشانی لما لما)y);

    إذا (y != 0xffffffff80000000LL) {
        لکھو("FAIL: int→long long sign-extension\n");
        ok = 0;
    }

    /* Also test positive value.  */
    x = 0x40000000;
    y = (لما لما)x;
    لکھو("y=%llx\n", (بنانشانی لما لما)y);

    إذا (y != 0x40000000LL) {
        لکھو("FAIL: int→long long positive value\n");
        ok = 0;
    }

    /* Test via unsigned int to catch zero-extension vs sign-extension.  */
    بنانشانی صحيح ux = 0x80000000;
    لما لما uy = (لما لما)(صحيح)ux;
    لکھو("uy=%llx\n", (بنانشانی لما لما)uy);

    إذا (uy != 0xffffffff80000000LL) {
        لکھو("FAIL: unsigned→int→long long sign-extension\n");
        ok = 0;
    }

    لکھو("%s\n", ok ? "PASS" : "FAIL");
    أرجع ok ? 0 : 1;
}

صحيح مکھ()
{
    أرجع
        promote_main()
        | cast_main()
        | sign_main();
}
