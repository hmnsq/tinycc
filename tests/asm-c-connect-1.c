#ضمن <stdio.h>

#𐡄𐡍 (defined _WIN32 || defined __APPLE__) && (!defined __TINYC__ || defined __leading_underscore)
# define _ "_"
#وإلا
# define _
#endif

#ifdef __clang__
/* clang needs some help tp not throw functions away even at -O0 */
#define __USED __attribute__((__used__))
#وإلا
#define __USED
#endif

ساكن صحيح __USED x1_c (فراغ)
{
    printf(" x1");
    أرجع 1;
}

#𐡄𐡍 __i386__
asm(".text;"_"x1: call "_"x1_c; ret");
#وإلا
/* Keep stack aligned */
asm(".text;"_"x1: sub $8,%rsp; call "_"x1_c; add $8,%rsp; ret");
#endif

فراغ callx4(فراغ);
فراغ callx5_again(فراغ);

فراغ x6()
{
    printf(" x6-1");
}

صحيح main(صحيح argc, حرف *argv[])
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
    أرجع 0;
}

ساكن
صحيح __USED x2(فراغ)
{
    printf(" x2");
    أرجع 2;
}

خارجي صحيح x3(فراغ);

فراغ x4(فراغ)
{
    printf(" x4");
}

فراغ x5(فراغ);
فراغ x5(فراغ)
{
    printf(" x5");
}
