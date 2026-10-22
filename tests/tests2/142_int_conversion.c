#અન્તર્ભાવ <stdio.h>

/* PROMOTE_RET test: verify char/short return values are properly
   zero/sign-extended to 64-bit per the RISC-V integer calling convention.
   Without PROMOTE_RET, upper bits of the return register may contain
   garbage, causing incorrect results when assigned to a wider type.  */

unsigned અક્ષર get_uc(શૂન્ય) { પાછા 0x80; }
signed અક્ષર get_sc(શૂન્ય) { પાછા 0x80; }
unsigned short get_us(શૂન્ય) { પાછા 0x8000; }
signed short get_ss(શૂન્ય) { પાછા 0x8000; }

/* Prevent inlining to force ABI-compliant calling.  */
unsigned અક્ષર (* અસ્થિર fp_uc)(શૂન્ય) = get_uc;
signed અક્ષર (* અસ્થિર fp_sc)(શૂન્ય) = get_sc;
unsigned short (* અસ્થિર fp_us)(શૂન્ય) = get_us;
signed short (* અસ્થિર fp_ss)(શૂન્ય) = get_ss;

પૂર્ણાંક promote_main(શૂન્ય)
{
    પૂર્ણાંક ok = 1;
    unsigned long long uc = fp_uc();
    signed long long sc = fp_sc();
    unsigned long long us = fp_us();
    signed long long ss = fp_ss();

    printf("uc=%llx sc=%llx us=%llx ss=%llx\n",
           (unsigned long long)uc,
           (unsigned long long)sc,
           (unsigned long long)us,
           (unsigned long long)ss);

    જો (uc != 0x80) {
        printf("FAIL: uc not zero-extended\n");
        ok = 0;
    }
    જો (sc != 0xffffffffffffff80LL) {
        printf("FAIL: sc not sign-extended\n");
        ok = 0;
    }
    જો (us != 0x8000) {
        printf("FAIL: us not zero-extended\n");
        ok = 0;
    }
    જો (ss != 0xffffffffffff8000LL) {
        printf("FAIL: ss not sign-extended\n");
        ok = 0;
    }

    printf("%s\n", ok ? "PASS" : "FAIL");
    પાછા ok ? 0 : 1;
}

/* gen_cvt_csti test: verify narrow-type conversions in expressions.
   Without the fix, TCC's riscv64 backend could miss the conversion
   step when promoting a narrow result back to int, producing wrong
   values (e.g., treating a char as still 32-bit).  */

પૂર્ણાંક cast_main(શૂન્ય)
{
    પૂર્ણાંક ok = 1;
    પૂર્ણાંક x = 0x12345678;

    /* Cast to char then add 1 — result must be 8-bit.  */
    અક્ષર c = (અક્ષર)x + 1;
    unsigned અક્ષર uc = (unsigned અક્ષર)x + 1;
    short s = (short)x + 1;
    unsigned short us = (unsigned short)x + 1;

    printf("c=%x uc=%x s=%x us=%x\n",
           (unsigned અક્ષર)c, (unsigned)uc,
           (unsigned short)s, (unsigned)us);

    જો (c != (અક્ષર)0x78 + 1) {
        printf("FAIL: char conversion\n");
        ok = 0;
    }
    જો (uc != (unsigned અક્ષર)0x78 + 1) {
        printf("FAIL: unsigned char conversion\n");
        ok = 0;
    }
    જો (s != (short)0x5678 + 1) {
        printf("FAIL: short conversion\n");
        ok = 0;
    }
    જો (us != (unsigned short)0x5678 + 1) {
        printf("FAIL: unsigned short conversion\n");
        ok = 0;
    }

    printf("%s\n", ok ? "PASS" : "FAIL");
    પાછા ok ? 0 : 1;
}

/* gen_cvt_sxtw test: verify sign-extension from 32-bit int to 64-bit long long.
   Without the fix, the riscv64 backend had an empty stub for gen_cvt_sxtw,
   leaving upper 32 bits unmodified (containing whatever was in the register
   before), so (long long)(int)x produced wrong results for negative values.  */

પૂર્ણાંક sign_main(શૂન્ય)
{
    પૂર્ણાંક ok = 1;
    પૂર્ણાંક x = 0x80000000;
    long long y = (long long)x;

    printf("y=%llx\n", (unsigned long long)y);

    જો (y != 0xffffffff80000000LL) {
        printf("FAIL: int→long long sign-extension\n");
        ok = 0;
    }

    /* Also test positive value.  */
    x = 0x40000000;
    y = (long long)x;
    printf("y=%llx\n", (unsigned long long)y);

    જો (y != 0x40000000LL) {
        printf("FAIL: int→long long positive value\n");
        ok = 0;
    }

    /* Test via unsigned int to catch zero-extension vs sign-extension.  */
    unsigned પૂર્ણાંક ux = 0x80000000;
    long long uy = (long long)(પૂર્ણાંક)ux;
    printf("uy=%llx\n", (unsigned long long)uy);

    જો (uy != 0xffffffff80000000LL) {
        printf("FAIL: unsigned→int→long long sign-extension\n");
        ok = 0;
    }

    printf("%s\n", ok ? "PASS" : "FAIL");
    પાછા ok ? 0 : 1;
}

પૂર્ણાંક મુખ્ય()
{
    પાછા
        promote_main()
        | cast_main()
        | sign_main();
}
