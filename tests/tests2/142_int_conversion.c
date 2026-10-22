#شامل <stdio.h>

/* PROMOTE_RET test: verify char/short return values are properly
   zero/sign-extended to 64-bit per the RISC-V integer calling convention.
   Without PROMOTE_RET, upper bits of the return register may contain
   garbage, causing incorrect results when assigned to a wider type.  */

غیرعلامتی حرف get_uc(خالی) { واپس 0x80; }
علامتی حرف get_sc(خالی) { واپس 0x80; }
غیرعلامتی مختصر get_us(خالی) { واپس 0x8000; }
علامتی مختصر get_ss(خالی) { واپس 0x8000; }

/* Prevent inlining to force ABI-compliant calling.  */
غیرعلامتی حرف (* متلون fp_uc)(خالی) = get_uc;
علامتی حرف (* متلون fp_sc)(خالی) = get_sc;
غیرعلامتی مختصر (* متلون fp_us)(خالی) = get_us;
علامتی مختصر (* متلون fp_ss)(خالی) = get_ss;

صحیح promote_main(خالی)
{
    صحیح ok = 1;
    غیرعلامتی طویل طویل uc = fp_uc();
    علامتی طویل طویل sc = fp_sc();
    غیرعلامتی طویل طویل us = fp_us();
    علامتی طویل طویل ss = fp_ss();

    لکھو("uc=%llx sc=%llx us=%llx ss=%llx\n",
           (غیرعلامتی طویل طویل)uc,
           (غیرعلامتی طویل طویل)sc,
           (غیرعلامتی طویل طویل)us,
           (غیرعلامتی طویل طویل)ss);

    اگر (uc != 0x80) {
        لکھو("FAIL: uc not zero-extended\n");
        ok = 0;
    }
    اگر (sc != 0xffffffffffffff80LL) {
        لکھو("FAIL: sc not sign-extended\n");
        ok = 0;
    }
    اگر (us != 0x8000) {
        لکھو("FAIL: us not zero-extended\n");
        ok = 0;
    }
    اگر (ss != 0xffffffffffff8000LL) {
        لکھو("FAIL: ss not sign-extended\n");
        ok = 0;
    }

    لکھو("%s\n", ok ? "PASS" : "FAIL");
    واپس ok ? 0 : 1;
}

/* gen_cvt_csti test: verify narrow-type conversions in expressions.
   Without the fix, TCC's riscv64 backend could miss the conversion
   step when promoting a narrow result back to int, producing wrong
   values (e.g., treating a char as still 32-bit).  */

صحیح cast_main(خالی)
{
    صحیح ok = 1;
    صحیح x = 0x12345678;

    /* Cast to char then add 1 — result must be 8-bit.  */
    حرف c = (حرف)x + 1;
    غیرعلامتی حرف uc = (غیرعلامتی حرف)x + 1;
    مختصر s = (مختصر)x + 1;
    غیرعلامتی مختصر us = (غیرعلامتی مختصر)x + 1;

    لکھو("c=%x uc=%x s=%x us=%x\n",
           (غیرعلامتی حرف)c, (غیرعلامتی)uc,
           (غیرعلامتی مختصر)s, (غیرعلامتی)us);

    اگر (c != (حرف)0x78 + 1) {
        لکھو("FAIL: char conversion\n");
        ok = 0;
    }
    اگر (uc != (غیرعلامتی حرف)0x78 + 1) {
        لکھو("FAIL: unsigned char conversion\n");
        ok = 0;
    }
    اگر (s != (مختصر)0x5678 + 1) {
        لکھو("FAIL: short conversion\n");
        ok = 0;
    }
    اگر (us != (غیرعلامتی مختصر)0x5678 + 1) {
        لکھو("FAIL: unsigned short conversion\n");
        ok = 0;
    }

    لکھو("%s\n", ok ? "PASS" : "FAIL");
    واپس ok ? 0 : 1;
}

/* gen_cvt_sxtw test: verify sign-extension from 32-bit int to 64-bit long long.
   Without the fix, the riscv64 backend had an empty stub for gen_cvt_sxtw,
   leaving upper 32 bits unmodified (containing whatever was in the register
   before), so (long long)(int)x produced wrong results for negative values.  */

صحیح sign_main(خالی)
{
    صحیح ok = 1;
    صحیح x = 0x80000000;
    طویل طویل y = (طویل طویل)x;

    لکھو("y=%llx\n", (غیرعلامتی طویل طویل)y);

    اگر (y != 0xffffffff80000000LL) {
        لکھو("FAIL: int→long long sign-extension\n");
        ok = 0;
    }

    /* Also test positive value.  */
    x = 0x40000000;
    y = (طویل طویل)x;
    لکھو("y=%llx\n", (غیرعلامتی طویل طویل)y);

    اگر (y != 0x40000000LL) {
        لکھو("FAIL: int→long long positive value\n");
        ok = 0;
    }

    /* Test via unsigned int to catch zero-extension vs sign-extension.  */
    غیرعلامتی صحیح ux = 0x80000000;
    طویل طویل uy = (طویل طویل)(صحیح)ux;
    لکھو("uy=%llx\n", (غیرعلامتی طویل طویل)uy);

    اگر (uy != 0xffffffff80000000LL) {
        لکھو("FAIL: unsigned→int→long long sign-extension\n");
        ok = 0;
    }

    لکھو("%s\n", ok ? "PASS" : "FAIL");
    واپس ok ? 0 : 1;
}

صحیح مین()
{
    واپس
        promote_main()
        | cast_main()
        | sign_main();
}
