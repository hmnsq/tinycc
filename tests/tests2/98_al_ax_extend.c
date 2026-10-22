#অন্তর্ভাৱ <stdio.h>
#অন্তর্ভাৱ <stdlib.h>
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

পূর্ণাঙ্ক main()
{
    unsigned short us(শূন্য);
    short ss(শূন্য);
    unsigned ৱর্ণ uc(শূন্য);
    signed ৱর্ণ sc(শূন্য);

    unsigned short (*fpus)(শূন্য) = us;
    short (*fpss)(শূন্য) = ss;
    unsigned ৱর্ণ (*fpuc)(শূন্য) = uc;
    signed ৱর্ণ (*fpsc)(শূন্য) = sc;

    printf("%08X %08X\n", us() + 1, fpus() + 1);
    printf("%08X %08X\n", ss() + 1, fpss() + 1);
    printf("%08X %08X\n", uc() + 1, fpuc() + 1);
    printf("%08X %08X\n", sc() + 1, fpsc() + 1);
    printf("\n");
    printf("%08X %08X\n", fpus() + 1, us() + 1);
    printf("%08X %08X\n", fpss() + 1, ss() + 1);
    printf("%08X %08X\n", fpuc() + 1, uc() + 1);
    printf("%08X %08X\n", fpsc() + 1, sc() + 1);

    ঘূৰাই 0;
}
