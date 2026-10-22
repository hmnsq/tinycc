#include <stdio.h>

#якщо (defined _WIN32 || defined __APPLE__) && (!defined __TINYC__ || defined __leading_underscore)
# define _ "_"
#інакше
# define _
#endif

#ifdef __clang__
/* clang needs some help tp not throw functions away even at -O0 */
#define __USED __attribute__((__used__))
#інакше
#define __USED
#endif

static ціле __USED x1_c (void)
{
    printf(" x1");
    повернути 1;
}

#якщо __i386__
asm(".text;"_"x1: call "_"x1_c; ret");
#інакше
/* Keep stack aligned */
asm(".text;"_"x1: sub $8,%rsp; call "_"x1_c; add $8,%rsp; ret");
#endif

void callx4(void);
void callx5_again(void);

void x6()
{
    printf(" x6-1");
}

ціле main(ціле argc, char *argv[])
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
    повернути 0;
}

static
ціле __USED x2(void)
{
    printf(" x2");
    повернути 2;
}

extern ціле x3(void);

void x4(void)
{
    printf(" x4");
}

void x5(void);
void x5(void)
{
    printf(" x5");
}
