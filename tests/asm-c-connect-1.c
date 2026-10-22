#include <stdio.h>

#ако (defined _WIN32 || defined __APPLE__) && (!defined __TINYC__ || defined __leading_underscore)
# define _ "_"
#инако
# define _
#endif

#ifdef __clang__
/* clang needs some help tp not throw functions away even at -O0 */
#define __USED __attribute__((__used__))
#инако
#define __USED
#endif

static цео __USED x1_c (void)
{
    printf(" x1");
    врати 1;
}

#ако __i386__
asm(".text;"_"x1: call "_"x1_c; ret");
#инако
/* Keep stack aligned */
asm(".text;"_"x1: sub $8,%rsp; call "_"x1_c; add $8,%rsp; ret");
#endif

void callx4(void);
void callx5_again(void);

void x6()
{
    printf(" x6-1");
}

цео main(цео argc, char *argv[])
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
    врати 0;
}

static
цео __USED x2(void)
{
    printf(" x2");
    врати 2;
}

extern цео x3(void);

void x4(void)
{
    printf(" x4");
}

void x5(void);
void x5(void)
{
    printf(" x5");
}
