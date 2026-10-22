#include <stdio.h>

#もし (defined _WIN32 || defined __APPLE__) && (!defined __TINYC__ || defined __leading_underscore)
# define _ "_"
#否则
# define _
#endif

#ifdef __clang__
/* clang needs some help tp not throw functions away even at -O0 */
#define __USED __attribute__((__used__))
#否则
#define __USED
#endif

static 整数 __USED x1_c (void)
{
    printf(" x1");
    戻る 1;
}

#もし __i386__
asm(".text;"_"x1: call "_"x1_c; ret");
#否则
/* Keep stack aligned */
asm(".text;"_"x1: sub $8,%rsp; call "_"x1_c; add $8,%rsp; ret");
#endif

void callx4(void);
void callx5_again(void);

void x6()
{
    printf(" x6-1");
}

整数 メインページ(整数 argc, char *argv[])
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
    戻る 0;
}

static
整数 __USED x2(void)
{
    printf(" x2");
    戻る 2;
}

extern 整数 x3(void);

void x4(void)
{
    printf(" x4");
}

void x5(void);
void x5(void)
{
    printf(" x5");
}
