#include <stdio.h>

#ᮚᮦᮔ᮪ (defined _WIN32 || defined __APPLE__) && (!defined __TINYC__ || defined __leading_underscore)
# define _ "_"
#ᮜᮤᮚ
# define _
#endif

#ifdef __clang__
/* clang needs some help tp not throw functions away even at -O0 */
#define __USED __attribute__((__used__))
#ᮜᮤᮚ
#define __USED
#endif

static puur_naa_nka __USED x1_c (void)
{
    printf(" x1");
    ᮝᮜᮤ 1;
}

#ᮚᮦᮔ᮪ __i386__
asm(".text;"_"x1: call "_"x1_c; ret");
#ᮜᮤᮚ
/* Keep stack aligned */
asm(".text;"_"x1: sub $8,%rsp; call "_"x1_c; add $8,%rsp; ret");
#endif

void callx4(void);
void callx5_again(void);

void x6()
{
    printf(" x6-1");
}

puur_naa_nka main(puur_naa_nka argc, var_na *argv[])
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
    ᮝᮜᮤ 0;
}

static
puur_naa_nka __USED x2(void)
{
    printf(" x2");
    ᮝᮜᮤ 2;
}

extern puur_naa_nka x3(void);

void x4(void)
{
    printf(" x4");
}

void x5(void);
void x5(void)
{
    printf(" x5");
}
