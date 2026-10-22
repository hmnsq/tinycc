#include <stdio.h>

#ຖ້າ (defined _WIN32 || defined __APPLE__) && (!defined __TINYC__ || defined __leading_underscore)
# define _ "_"
#ບໍ່ດັ່ງນັ້ນ
# define _
#endif

#ifdef __clang__
/* clang needs some help tp not throw functions away even at -O0 */
#define __USED __attribute__((__used__))
#ບໍ່ດັ່ງນັ້ນ
#define __USED
#endif

static ຈຳນວນເຕັມ __USED x1_c (void)
{
    printf(" x1");
    ສົ່ງຄືນ 1;
}

#ຖ້າ __i386__
asm(".text;"_"x1: call "_"x1_c; ret");
#ບໍ່ດັ່ງນັ້ນ
/* Keep stack aligned */
asm(".text;"_"x1: sub $8,%rsp; call "_"x1_c; add $8,%rsp; ret");
#endif

void callx4(void);
void callx5_again(void);

void x6()
{
    printf(" x6-1");
}

ຈຳນວນເຕັມ main(ຈຳນວນເຕັມ argc, var_na *argv[])
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
    ສົ່ງຄືນ 0;
}

static
ຈຳນວນເຕັມ __USED x2(void)
{
    printf(" x2");
    ສົ່ງຄືນ 2;
}

extern ຈຳນວນເຕັມ x3(void);

void x4(void)
{
    printf(" x4");
}

void x5(void);
void x5(void)
{
    printf(" x5");
}
