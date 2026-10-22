#ضمن <stdio.h>

#إذا (defined _WIN32 || defined __APPLE__) && (!defined __TINYC__ || defined __leading_underscore)
# define _ "_"
#وإلا
# define _
#جے_انت

#جے_تعریف_شدہ __clang__
/* clang needs some help tp not throw functions away even at -O0 */
#تعریف_کرو __USED __attribute__((__used__))
#وإلا
#تعریف_کرو __USED
#جے_انت

ساكن صحيح __USED x1_c (فراغ)
{
    لکھو(" x1");
    أرجع 1;
}

#إذا __i386__
asm(".text;"_"x1: call "_"x1_c; ret");
#وإلا
/* Keep stack aligned */
asm(".text;"_"x1: sub $8,%rsp; call "_"x1_c; add $8,%rsp; ret");
#جے_انت

فراغ callx4(فراغ);
فراغ callx5_again(فراغ);

فراغ x6()
{
    لکھو(" x6-1");
}

صحيح مکھ(صحيح argc, حرف *argv[])
{
    لکھو("*");
    asm("call "_"x1");
    asm("call "_"x2");
    asm("call "_"x3");
    callx4();
    asm("call "_"x5");
    callx5_again();
    x6();
    لکھو(" *\n");
    أرجع 0;
}

ساكن
صحيح __USED x2(فراغ)
{
    لکھو(" x2");
    أرجع 2;
}

خارجي صحيح x3(فراغ);

فراغ x4(فراغ)
{
    لکھو(" x4");
}

فراغ x5(فراغ);
فراغ x5(فراغ)
{
    لکھو(" x5");
}
