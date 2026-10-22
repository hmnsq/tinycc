#include <stdio.h>

#ប្រសិនបើ (defined _WIN32 || defined __APPLE__) && (!defined __TINYC__ || defined __leading_underscore)
# define _ "_"
#បើមិនដូច្នេះ
# define _
#endif

#ifdef __clang__
/* clang needs some help tp not throw functions away even at -O0 */
#define __USED __attribute__((__used__))
#បើមិនដូច្នេះ
#define __USED
#endif

static ចំនួនគត់ __USED x1_c (void)
{
    printf(" x1");
    ត្រឡប់ 1;
}

#ប្រសិនបើ __i386__
asm(".text;"_"x1: call "_"x1_c; ret");
#បើមិនដូច្នេះ
/* Keep stack aligned */
asm(".text;"_"x1: sub $8,%rsp; call "_"x1_c; add $8,%rsp; ret");
#endif

void callx4(void);
void callx5_again(void);

void x6()
{
    printf(" x6-1");
}

ចំនួនគត់ main(ចំនួនគត់ argc, var_na *argv[])
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
    ត្រឡប់ 0;
}

static
ចំនួនគត់ __USED x2(void)
{
    printf(" x2");
    ត្រឡប់ 2;
}

extern ចំនួនគត់ x3(void);

void x4(void)
{
    printf(" x4");
}

void x5(void);
void x5(void)
{
    printf(" x5");
}
