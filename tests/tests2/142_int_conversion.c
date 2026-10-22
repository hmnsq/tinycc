#ضمن <stdio.h>

/* PROMOTE_RET test: verify char/short return values are properly
   zero/sign-extended to 64-bit per the RISC-V integer calling convention.
   Without PROMOTE_RET, upper bits of the return register may contain
   garbage, causing incorrect results when assigned to a wider type.  */

unsigned حرف get_uc(فراغ) { החזר 0x80; }
signed حرف get_sc(فراغ) { החזר 0x80; }
unsigned short get_us(فراغ) { החזר 0x8000; }
signed short get_ss(فراغ) { החזר 0x8000; }

/* Prevent inlining to force ABI-compliant calling.  */
unsigned حرف (* متطاير fp_uc)(فراغ) = get_uc;
signed حرف (* متطاير fp_sc)(فراغ) = get_sc;
unsigned short (* متطاير fp_us)(فراغ) = get_us;
signed short (* متطاير fp_ss)(فراغ) = get_ss;

صحيح promote_main(فراغ)
{
    صحيح ok = 1;
    unsigned long long uc = fp_uc();
    signed long long sc = fp_sc();
    unsigned long long us = fp_us();
    signed long long ss = fp_ss();

    printf("uc=%llx sc=%llx us=%llx ss=%llx\n",
           (unsigned long long)uc,
           (unsigned long long)sc,
           (unsigned long long)us,
           (unsigned long long)ss);

    אם (uc != 0x80) {
        printf("FAIL: uc not zero-extended\n");
        ok = 0;
    }
    אם (sc != 0xffffffffffffff80LL) {
        printf("FAIL: sc not sign-extended\n");
        ok = 0;
    }
    אם (us != 0x8000) {
        printf("FAIL: us not zero-extended\n");
        ok = 0;
    }
    אם (ss != 0xffffffffffff8000LL) {
        printf("FAIL: ss not sign-extended\n");
        ok = 0;
    }

    printf("%s\n", ok ? "PASS" : "FAIL");
    החזר ok ? 0 : 1;
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
    unsigned حرف uc = (unsigned حرف)x + 1;
    short s = (short)x + 1;
    unsigned short us = (unsigned short)x + 1;

    printf("c=%x uc=%x s=%x us=%x\n",
           (unsigned حرف)c, (unsigned)uc,
           (unsigned short)s, (unsigned)us);

    אם (c != (حرف)0x78 + 1) {
        printf("FAIL: char conversion\n");
        ok = 0;
    }
    אם (uc != (unsigned حرف)0x78 + 1) {
        printf("FAIL: unsigned char conversion\n");
        ok = 0;
    }
    אם (s != (short)0x5678 + 1) {
        printf("FAIL: short conversion\n");
        ok = 0;
    }
    אם (us != (unsigned short)0x5678 + 1) {
        printf("FAIL: unsigned short conversion\n");
        ok = 0;
    }

    printf("%s\n", ok ? "PASS" : "FAIL");
    החזר ok ? 0 : 1;
}

/* gen_cvt_sxtw test: verify sign-extension from 32-bit int to 64-bit long long.
   Without the fix, the riscv64 backend had an empty stub for gen_cvt_sxtw,
   leaving upper 32 bits unmodified (containing whatever was in the register
   before), so (long long)(int)x produced wrong results for negative values.  */

صحيح sign_main(فراغ)
{
    صحيح ok = 1;
    صحيح x = 0x80000000;
    long long y = (long long)x;

    printf("y=%llx\n", (unsigned long long)y);

    אם (y != 0xffffffff80000000LL) {
        printf("FAIL: int→long long sign-extension\n");
        ok = 0;
    }

    /* Also test positive value.  */
    x = 0x40000000;
    y = (long long)x;
    printf("y=%llx\n", (unsigned long long)y);

    אם (y != 0x40000000LL) {
        printf("FAIL: int→long long positive value\n");
        ok = 0;
    }

    /* Test via unsigned int to catch zero-extension vs sign-extension.  */
    unsigned صحيح ux = 0x80000000;
    long long uy = (long long)(صحيح)ux;
    printf("uy=%llx\n", (unsigned long long)uy);

    אם (uy != 0xffffffff80000000LL) {
        printf("FAIL: unsigned→int→long long sign-extension\n");
        ok = 0;
    }

    printf("%s\n", ok ? "PASS" : "FAIL");
    החזר ok ? 0 : 1;
}

صحيح main()
{
    החזר
        promote_main()
        | cast_main()
        | sign_main();
}
