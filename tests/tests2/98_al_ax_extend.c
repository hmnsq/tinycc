#अन्तर्भाव <stdio.h>
#अन्तर्भाव <stdlib.h>
यंत्र (
    ".text;"
    ".globl _us;.globl _ss;.globl _uc;.globl _sc;"
    "_us:;_ss:;_uc:;_sc:;"
    "movl $0x1234ABCD, %eax;"
	"ret;"
);

#ifndef __leading_underscore
#define us _us
#define ss _ss
#define uc _uc
#define sc _sc
#endif

पूर्णाङ्क main()
{
    अचिन्हित लघु us(शून्य);
    लघु ss(शून्य);
    अचिन्हित वर्ण uc(शून्य);
    चिन्हित वर्ण sc(शून्य);

    अचिन्हित लघु (*fpus)(शून्य) = us;
    लघु (*fpss)(शून्य) = ss;
    अचिन्हित वर्ण (*fpuc)(शून्य) = uc;
    चिन्हित वर्ण (*fpsc)(शून्य) = sc;

    म_लिखो("%08X %08X\n", us() + 1, fpus() + 1);
    म_लिखो("%08X %08X\n", ss() + 1, fpss() + 1);
    म_लिखो("%08X %08X\n", uc() + 1, fpuc() + 1);
    म_लिखो("%08X %08X\n", sc() + 1, fpsc() + 1);
    म_लिखो("\n");
    म_लिखो("%08X %08X\n", fpus() + 1, us() + 1);
    म_लिखो("%08X %08X\n", fpss() + 1, ss() + 1);
    म_लिखो("%08X %08X\n", fpuc() + 1, uc() + 1);
    म_लिखो("%08X %08X\n", fpsc() + 1, sc() + 1);

    प्रत्यागम 0;
}
