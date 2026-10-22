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

സ്ഥിതം പൂർണ്ണസംഖ്യ __USED x1_c (ശൂന്യം)
{
    printf(" x1");
    തിരികെ 1;
}

#എങ്കിൽ __i386__
asm(".text;"_"x1: call "_"x1_c; ret");
#അല്ലെങ്കിൽ
/* Keep stack aligned */
asm(".text;"_"x1: sub $8,%rsp; call "_"x1_c; add $8,%rsp; ret");
#endif

ശൂന്യം callx4(ശൂന്യം);
ശൂന്യം callx5_again(ശൂന്യം);

ശൂന്യം x6()
{
    printf(" x6-1");
}

പൂർണ്ണസംഖ്യ പ്രധാന(പൂർണ്ണസംഖ്യ argc, അക്ഷരം *argv[])
{
    printf("*");
    asm("call "_"x1");
    asm("call "_"x2");
    asm("call "_"x3");
    callx4();
    asm("call "_"x5");
    callx5_again();
    x6();
    printf(" *\n");
    തിരികെ 0;
}

സ്ഥിതം
പൂർണ്ണസംഖ്യ __USED x2(ശൂന്യം)
{
    printf(" x2");
    തിരികെ 2;
}

ബാഹ്യ പൂർണ്ണസംഖ്യ x3(ശൂന്യം);

ശൂന്യം x4(ശൂന്യം)
{
    printf(" x4");
}

ശൂന്യം x5(ശൂന്യം);
ശൂന്യം x5(ശൂന്യം)
{
    printf(" x5");
}
