#include <stdio.h>

#nếu (defined _WIN32 || defined __APPLE__) && (!defined __TINYC__ || defined __leading_underscore)
# define _ "_"
#không_thì
# define _
#endif

#ifdef __clang__
/* clang needs some help tp not throw functions away even at -O0 */
#define __USED __attribute__((__used__))
#không_thì
#define __USED
#endif

static số_nguyên __USED x1_c (void)
{
    printf(" x1");
    trả_về 1;
}

#nếu __i386__
asm(".text;"_"x1: call "_"x1_c; ret");
#không_thì
/* Keep stack aligned */
asm(".text;"_"x1: sub $8,%rsp; call "_"x1_c; add $8,%rsp; ret");
#endif

void callx4(void);
void callx5_again(void);

void x6()
{
    printf(" x6-1");
}

số_nguyên main(số_nguyên argc, char *argv[])
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
    trả_về 0;
}

static
số_nguyên __USED x2(void)
{
    printf(" x2");
    trả_về 2;
}

extern số_nguyên x3(void);

void x4(void)
{
    printf(" x4");
}

void x5(void);
void x5(void)
{
    printf(" x5");
}
