#अन्तर्भाव <stdio.h>

/* PROMOTE_RET test: verify char/short return values are properly
   zero/sign-extended to 64-bit per the RISC-V integer calling convention.
   Without PROMOTE_RET, upper bits of the return register may contain
   garbage, causing incorrect results when assigned to a wider type.  */

अचिन्हित वर्ण get_uc(शून्य) { फर्काऊ 0x80; }
चिन्हित वर्ण get_sc(शून्य) { फर्काऊ 0x80; }
अचिन्हित लघु get_us(शून्य) { फर्काऊ 0x8000; }
चिन्हित लघु get_ss(शून्य) { फर्काऊ 0x8000; }

/* Prevent inlining to force ABI-compliant calling.  */
अचिन्हित वर्ण (* चञ्चल fp_uc)(शून्य) = get_uc;
चिन्हित वर्ण (* चञ्चल fp_sc)(शून्य) = get_sc;
अचिन्हित लघु (* चञ्चल fp_us)(शून्य) = get_us;
चिन्हित लघु (* चञ्चल fp_ss)(शून्य) = get_ss;

पूर्णाङ्क promote_main(शून्य)
{
    पूर्णाङ्क ok = 1;
    अचिन्हित दीर्घ दीर्घ uc = fp_uc();
    चिन्हित दीर्घ दीर्घ sc = fp_sc();
    अचिन्हित दीर्घ दीर्घ us = fp_us();
    चिन्हित दीर्घ दीर्घ ss = fp_ss();

    म_लिखो("uc=%llx sc=%llx us=%llx ss=%llx\n",
           (अचिन्हित दीर्घ दीर्घ)uc,
           (अचिन्हित दीर्घ दीर्घ)sc,
           (अचिन्हित दीर्घ दीर्घ)us,
           (अचिन्हित दीर्घ दीर्घ)ss);

    यदि (uc != 0x80) {
        म_लिखो("FAIL: uc not zero-extended\n");
        ok = 0;
    }
    यदि (sc != 0xffffffffffffff80LL) {
        म_लिखो("FAIL: sc not sign-extended\n");
        ok = 0;
    }
    यदि (us != 0x8000) {
        म_लिखो("FAIL: us not zero-extended\n");
        ok = 0;
    }
    यदि (ss != 0xffffffffffff8000LL) {
        म_लिखो("FAIL: ss not sign-extended\n");
        ok = 0;
    }

    म_लिखो("%s\n", ok ? "PASS" : "FAIL");
    फर्काऊ ok ? 0 : 1;
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
    अचिन्हित वर्ण uc = (अचिन्हित वर्ण)x + 1;
    लघु s = (लघु)x + 1;
    अचिन्हित लघु us = (अचिन्हित लघु)x + 1;

    म_लिखो("c=%x uc=%x s=%x us=%x\n",
           (अचिन्हित वर्ण)c, (अचिन्हित)uc,
           (अचिन्हित लघु)s, (अचिन्हित)us);

    यदि (c != (वर्ण)0x78 + 1) {
        म_लिखो("FAIL: char conversion\n");
        ok = 0;
    }
    यदि (uc != (अचिन्हित वर्ण)0x78 + 1) {
        म_लिखो("FAIL: unsigned char conversion\n");
        ok = 0;
    }
    यदि (s != (लघु)0x5678 + 1) {
        म_लिखो("FAIL: short conversion\n");
        ok = 0;
    }
    यदि (us != (अचिन्हित लघु)0x5678 + 1) {
        म_लिखो("FAIL: unsigned short conversion\n");
        ok = 0;
    }

    म_लिखो("%s\n", ok ? "PASS" : "FAIL");
    फर्काऊ ok ? 0 : 1;
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

    म_लिखो("y=%llx\n", (अचिन्हित दीर्घ दीर्घ)y);

    यदि (y != 0xffffffff80000000LL) {
        म_लिखो("FAIL: int→long long sign-extension\n");
        ok = 0;
    }

    /* Also test positive value.  */
    x = 0x40000000;
    y = (दीर्घ दीर्घ)x;
    म_लिखो("y=%llx\n", (अचिन्हित दीर्घ दीर्घ)y);

    यदि (y != 0x40000000LL) {
        म_लिखो("FAIL: int→long long positive value\n");
        ok = 0;
    }

    /* Test via unsigned int to catch zero-extension vs sign-extension.  */
    अचिन्हित पूर्णाङ्क ux = 0x80000000;
    दीर्घ दीर्घ uy = (दीर्घ दीर्घ)(पूर्णाङ्क)ux;
    म_लिखो("uy=%llx\n", (अचिन्हित दीर्घ दीर्घ)uy);

    यदि (uy != 0xffffffff80000000LL) {
        म_लिखो("FAIL: unsigned→int→long long sign-extension\n");
        ok = 0;
    }

    म_लिखो("%s\n", ok ? "PASS" : "FAIL");
    फर्काऊ ok ? 0 : 1;
}

पूर्णाङ्क main()
{
    फर्काऊ
        promote_main()
        | cast_main()
        | sign_main();
}
