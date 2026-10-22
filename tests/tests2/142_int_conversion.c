#अन्तर्भाव <stdio.h>

/* PROMOTE_RET test: verify char/short return values are properly
   zero/sign-extended to 64-bit per the RISC-V integer calling convention.
   Without PROMOTE_RET, upper bits of the return register may contain
   garbage, causing incorrect results when assigned to a wider type.  */

अचिह्नित वर्ण get_uc(शून्य) { प्रत्यागम 0x80; }
चिह्नित वर्ण get_sc(शून्य) { प्रत्यागम 0x80; }
अचिह्नित ह्रस्व get_us(शून्य) { प्रत्यागम 0x8000; }
चिह्नित ह्रस्व get_ss(शून्य) { प्रत्यागम 0x8000; }

/* Prevent inlining to force ABI-compliant calling.  */
अचिह्नित वर्ण (* चञ्चल fp_uc)(शून्य) = get_uc;
चिह्नित वर्ण (* चञ्चल fp_sc)(शून्य) = get_sc;
अचिह्नित ह्रस्व (* चञ्चल fp_us)(शून्य) = get_us;
चिह्नित ह्रस्व (* चञ्चल fp_ss)(शून्य) = get_ss;

पूर्णाङ्क promote_main(शून्य)
{
    पूर्णाङ्क ok = 1;
    अचिह्नित दीर्घ दीर्घ uc = fp_uc();
    चिह्नित दीर्घ दीर्घ sc = fp_sc();
    अचिह्नित दीर्घ दीर्घ us = fp_us();
    चिह्नित दीर्घ दीर्घ ss = fp_ss();

    प्रारूप_लिख("uc=%llx sc=%llx us=%llx ss=%llx\n",
           (अचिह्नित दीर्घ दीर्घ)uc,
           (अचिह्नित दीर्घ दीर्घ)sc,
           (अचिह्नित दीर्घ दीर्घ)us,
           (अचिह्नित दीर्घ दीर्घ)ss);

    यदि (uc != 0x80) {
        प्रारूप_लिख("FAIL: uc not zero-extended\n");
        ok = 0;
    }
    यदि (sc != 0xffffffffffffff80LL) {
        प्रारूप_लिख("FAIL: sc not sign-extended\n");
        ok = 0;
    }
    यदि (us != 0x8000) {
        प्रारूप_लिख("FAIL: us not zero-extended\n");
        ok = 0;
    }
    यदि (ss != 0xffffffffffff8000LL) {
        प्रारूप_लिख("FAIL: ss not sign-extended\n");
        ok = 0;
    }

    प्रारूप_लिख("%s\n", ok ? "PASS" : "FAIL");
    प्रत्यागम ok ? 0 : 1;
}

/* gen_cvt_csti test: verify narrow-type conversions in expressions.
   Without the fix, TCC's riscv64 backend could miss the conversion
   step when promoting a narrow result back to int, producing wrong
   values (e.g., treating a char as still 32-bit).  */

पूर्णाङ्क cast_main(शून्य)
{
    पूर्णाङ्क ok = 1;
    पूर्णाङ्क x = 0x12345678;

    /* Cast to char then add 1 — result must be 8-bit.  */
    वर्ण c = (वर्ण)x + 1;
    अचिह्नित वर्ण uc = (अचिह्नित वर्ण)x + 1;
    ह्रस्व s = (ह्रस्व)x + 1;
    अचिह्नित ह्रस्व us = (अचिह्नित ह्रस्व)x + 1;

    प्रारूप_लिख("c=%x uc=%x s=%x us=%x\n",
           (अचिह्नित वर्ण)c, (अचिह्नित)uc,
           (अचिह्नित ह्रस्व)s, (अचिह्नित)us);

    यदि (c != (वर्ण)0x78 + 1) {
        प्रारूप_लिख("FAIL: char conversion\n");
        ok = 0;
    }
    यदि (uc != (अचिह्नित वर्ण)0x78 + 1) {
        प्रारूप_लिख("FAIL: unsigned char conversion\n");
        ok = 0;
    }
    यदि (s != (ह्रस्व)0x5678 + 1) {
        प्रारूप_लिख("FAIL: short conversion\n");
        ok = 0;
    }
    यदि (us != (अचिह्नित ह्रस्व)0x5678 + 1) {
        प्रारूप_लिख("FAIL: unsigned short conversion\n");
        ok = 0;
    }

    प्रारूप_लिख("%s\n", ok ? "PASS" : "FAIL");
    प्रत्यागम ok ? 0 : 1;
}

/* gen_cvt_sxtw test: verify sign-extension from 32-bit int to 64-bit long long.
   Without the fix, the riscv64 backend had an empty stub for gen_cvt_sxtw,
   leaving upper 32 bits unmodified (containing whatever was in the register
   before), so (long long)(int)x produced wrong results for negative values.  */

पूर्णाङ्क sign_main(शून्य)
{
    पूर्णाङ्क ok = 1;
    पूर्णाङ्क x = 0x80000000;
    दीर्घ दीर्घ y = (दीर्घ दीर्घ)x;

    प्रारूप_लिख("y=%llx\n", (अचिह्नित दीर्घ दीर्घ)y);

    यदि (y != 0xffffffff80000000LL) {
        प्रारूप_लिख("FAIL: int→long long sign-extension\n");
        ok = 0;
    }

    /* Also test positive value.  */
    x = 0x40000000;
    y = (दीर्घ दीर्घ)x;
    प्रारूप_लिख("y=%llx\n", (अचिह्नित दीर्घ दीर्घ)y);

    यदि (y != 0x40000000LL) {
        प्रारूप_लिख("FAIL: int→long long positive value\n");
        ok = 0;
    }

    /* Test via unsigned int to catch zero-extension vs sign-extension.  */
    अचिह्नित पूर्णाङ्क ux = 0x80000000;
    दीर्घ दीर्घ uy = (दीर्घ दीर्घ)(पूर्णाङ्क)ux;
    प्रारूप_लिख("uy=%llx\n", (अचिह्नित दीर्घ दीर्घ)uy);

    यदि (uy != 0xffffffff80000000LL) {
        प्रारूप_लिख("FAIL: unsigned→int→long long sign-extension\n");
        ok = 0;
    }

    प्रारूप_लिख("%s\n", ok ? "PASS" : "FAIL");
    प्रत्यागम ok ? 0 : 1;
}

पूर्णाङ्क मुख्यम्()
{
    प्रत्यागम
        promote_main()
        | cast_main()
        | sign_main();
}
