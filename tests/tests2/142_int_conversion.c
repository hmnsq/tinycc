#include <stdio.h>

/* PROMOTE_RET test: verify char/short return values are properly
   zero/sign-extended to 64-bit per the RISC-V integer calling convention.
   Without PROMOTE_RET, upper bits of the return register may contain
   garbage, causing incorrect results when assigned to a wider type.  */

unsigned var_na get_uc(void) { ပွၵ်ႈ 0x80; }
signed var_na get_sc(void) { ပွၵ်ႈ 0x80; }
unsigned short get_us(void) { ပွၵ်ႈ 0x8000; }
signed short get_ss(void) { ပွၵ်ႈ 0x8000; }

/* Prevent inlining to force ABI-compliant calling.  */
unsigned var_na (* ca_ncala fp_uc)(void) = get_uc;
signed var_na (* ca_ncala fp_sc)(void) = get_sc;
unsigned short (* ca_ncala fp_us)(void) = get_us;
signed short (* ca_ncala fp_ss)(void) = get_ss;

puur_naa_nka promote_main(void)
{
    puur_naa_nka ok = 1;
    unsigned long long uc = fp_uc();
    signed long long sc = fp_sc();
    unsigned long long us = fp_us();
    signed long long ss = fp_ss();

    printf("uc=%llx sc=%llx us=%llx ss=%llx\n",
           (unsigned long long)uc,
           (unsigned long long)sc,
           (unsigned long long)us,
           (unsigned long long)ss);

    ပေႃး (uc != 0x80) {
        printf("FAIL: uc not zero-extended\n");
        ok = 0;
    }
    ပေႃး (sc != 0xffffffffffffff80LL) {
        printf("FAIL: sc not sign-extended\n");
        ok = 0;
    }
    ပေႃး (us != 0x8000) {
        printf("FAIL: us not zero-extended\n");
        ok = 0;
    }
    ပေႃး (ss != 0xffffffffffff8000LL) {
        printf("FAIL: ss not sign-extended\n");
        ok = 0;
    }

    printf("%s\n", ok ? "PASS" : "FAIL");
    ပွၵ်ႈ ok ? 0 : 1;
}

/* gen_cvt_csti test: verify narrow-type conversions in expressions.
   Without the fix, TCC's riscv64 backend could miss the conversion
   step when promoting a narrow result back to int, producing wrong
   values (e.g., treating a char as still 32-bit).  */

puur_naa_nka cast_main(void)
{
    puur_naa_nka ok = 1;
    puur_naa_nka x = 0x12345678;

    /* Cast to char then add 1 — result must be 8-bit.  */
    var_na c = (var_na)x + 1;
    unsigned var_na uc = (unsigned var_na)x + 1;
    short s = (short)x + 1;
    unsigned short us = (unsigned short)x + 1;

    printf("c=%x uc=%x s=%x us=%x\n",
           (unsigned var_na)c, (unsigned)uc,
           (unsigned short)s, (unsigned)us);

    ပေႃး (c != (var_na)0x78 + 1) {
        printf("FAIL: char conversion\n");
        ok = 0;
    }
    ပေႃး (uc != (unsigned var_na)0x78 + 1) {
        printf("FAIL: unsigned char conversion\n");
        ok = 0;
    }
    ပေႃး (s != (short)0x5678 + 1) {
        printf("FAIL: short conversion\n");
        ok = 0;
    }
    ပေႃး (us != (unsigned short)0x5678 + 1) {
        printf("FAIL: unsigned short conversion\n");
        ok = 0;
    }

    printf("%s\n", ok ? "PASS" : "FAIL");
    ပွၵ်ႈ ok ? 0 : 1;
}

/* gen_cvt_sxtw test: verify sign-extension from 32-bit int to 64-bit long long.
   Without the fix, the riscv64 backend had an empty stub for gen_cvt_sxtw,
   leaving upper 32 bits unmodified (containing whatever was in the register
   before), so (long long)(int)x produced wrong results for negative values.  */

puur_naa_nka sign_main(void)
{
    puur_naa_nka ok = 1;
    puur_naa_nka x = 0x80000000;
    long long y = (long long)x;

    printf("y=%llx\n", (unsigned long long)y);

    ပေႃး (y != 0xffffffff80000000LL) {
        printf("FAIL: int→long long sign-extension\n");
        ok = 0;
    }

    /* Also test positive value.  */
    x = 0x40000000;
    y = (long long)x;
    printf("y=%llx\n", (unsigned long long)y);

    ပေႃး (y != 0x40000000LL) {
        printf("FAIL: int→long long positive value\n");
        ok = 0;
    }

    /* Test via unsigned int to catch zero-extension vs sign-extension.  */
    unsigned puur_naa_nka ux = 0x80000000;
    long long uy = (long long)(puur_naa_nka)ux;
    printf("uy=%llx\n", (unsigned long long)uy);

    ပေႃး (uy != 0xffffffff80000000LL) {
        printf("FAIL: unsigned→int→long long sign-extension\n");
        ok = 0;
    }

    printf("%s\n", ok ? "PASS" : "FAIL");
    ပွၵ်ႈ ok ? 0 : 1;
}

puur_naa_nka main()
{
    ပွၵ်ႈ
        promote_main()
        | cast_main()
        | sign_main();
}
