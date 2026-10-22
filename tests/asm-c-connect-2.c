#അന്തര്ഭാവ <stdio.h>

#എങ്കിൽ (defined _WIN32 || defined __APPLE__) && (!defined __TINYC__ || defined __leading_underscore)
# define _ "_"
#അല്ലെങ്കിൽ
# define _
#endif

#ifdef __clang__
/* clang needs some help tp not throw functions away even at -O0 */
#define __USED __attribute__((__used__))
#അല്ലെങ്കിൽ
#define __USED
#endif

പൂർണ്ണസംഖ്യ x3(ശൂന്യം)
{
    printf(" x3");
    തിരികെ 3;
}

/* That callx4 is defined globally (as if ".globl callx4")
   is a TCC extension.  GCC doesn't behave like this.  */
ശൂന്യം callx4(ശൂന്യം);
#എങ്കിൽ __i386__
__asm__(_"callx4: call "_"x4; ret;"
#അല്ലെങ്കിൽ
/* Keep stack aligned */
__asm__(_"callx4: sub $8,%rsp; call "_"x4; add $8,%rsp; ret;"
#endif
#ifndef __TINYC__
    " .global "_"callx4"
#endif
);

ബാഹ്യ ശൂന്യം x5(ശൂന്യം);

ശൂന്യം callx5_again(ശൂന്യം);
ശൂന്യം callx5_again(ശൂന്യം)
{
    x5();
    asm("call "_"x6");
}

സ്ഥിതം ശൂന്യം __USED x6()
{
    printf(" x6-2");
}
