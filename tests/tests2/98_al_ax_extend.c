#ضمن <stdio.h>
#ضمن <stdlib.h>
asm (
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

صحيح main()
{
    unsigned short us(فراغ);
    short ss(فراغ);
    unsigned حرف uc(فراغ);
    signed حرف sc(فراغ);

    unsigned short (*fpus)(فراغ) = us;
    short (*fpss)(فراغ) = ss;
    unsigned حرف (*fpuc)(فراغ) = uc;
    signed حرف (*fpsc)(فراغ) = sc;

    printf("%08X %08X\n", us() + 1, fpus() + 1);
    printf("%08X %08X\n", ss() + 1, fpss() + 1);
    printf("%08X %08X\n", uc() + 1, fpuc() + 1);
    printf("%08X %08X\n", sc() + 1, fpsc() + 1);
    printf("\n");
    printf("%08X %08X\n", fpus() + 1, us() + 1);
    printf("%08X %08X\n", fpss() + 1, ss() + 1);
    printf("%08X %08X\n", fpuc() + 1, uc() + 1);
    printf("%08X %08X\n", fpsc() + 1, sc() + 1);

    ܦܢܐ 0;
}
