#ଅନ୍ତର୍ଭାଵ <stdio.h>
#ଅନ୍ତର୍ଭାଵ <stdlib.h>
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

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ()
{
    unsigned short us(ଶୂନ୍ୟ);
    short ss(ଶୂନ୍ୟ);
    unsigned ଅକ୍ଷର uc(ଶୂନ୍ୟ);
    signed ଅକ୍ଷର sc(ଶୂନ୍ୟ);

    unsigned short (*fpus)(ଶୂନ୍ୟ) = us;
    short (*fpss)(ଶୂନ୍ୟ) = ss;
    unsigned ଅକ୍ଷର (*fpuc)(ଶୂନ୍ୟ) = uc;
    signed ଅକ୍ଷର (*fpsc)(ଶୂନ୍ୟ) = sc;

    printf("%08X %08X\n", us() + 1, fpus() + 1);
    printf("%08X %08X\n", ss() + 1, fpss() + 1);
    printf("%08X %08X\n", uc() + 1, fpuc() + 1);
    printf("%08X %08X\n", sc() + 1, fpsc() + 1);
    printf("\n");
    printf("%08X %08X\n", fpus() + 1, us() + 1);
    printf("%08X %08X\n", fpss() + 1, ss() + 1);
    printf("%08X %08X\n", fpuc() + 1, uc() + 1);
    printf("%08X %08X\n", fpsc() + 1, sc() + 1);

    ଫେରନ୍ତୁ 0;
}
