#include <stdio.h>

#만약 (defined _WIN32 || defined __APPLE__) && (!defined __TINYC__ || defined __leading_underscore)
# define _ "_"
#아니면
# define _
#endif

#ifdef __clang__
/* clang needs some help tp not throw functions away even at -O0 */
#define __USED __attribute__((__used__))
#아니면
#define __USED
#endif

static 정수 __USED x1_c (void)
{
    printf(" x1");
    반환 1;
}

#만약 __i386__
asm(".text;"_"x1: call "_"x1_c; ret");
#아니면
/* Keep stack aligned */
asm(".text;"_"x1: sub $8,%rsp; call "_"x1_c; add $8,%rsp; ret");
#endif

void callx4(void);
void callx5_again(void);

void x6()
{
    printf(" x6-1");
}

정수 main(정수 argc, char *argv[])
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
    반환 0;
}

static
정수 __USED x2(void)
{
    printf(" x2");
    반환 2;
}

extern 정수 x3(void);

void x4(void)
{
    printf(" x4");
}

void x5(void);
void x5(void)
{
    printf(" x5");
}
