#ضمن <stdio.h>

#إذا (defined _WIN32 || defined __APPLE__) && (!defined __TINYC__ || defined __leading_underscore)
# define _ "_"
#وإلا
# define _
#پایان_اگر

#اگر_تعریف_شده __clang__
/* clang needs some help tp not throw functions away even at -O0 */
#تعریف_کن __USED __attribute__((__used__))
#وإلا
#تعریف_کن __USED
#پایان_اگر

ساكن صحيح __USED x1_c (فراغ)
{
    چاپ_کن(" x1");
    أرجع 1;
}

#إذا __i386__
asm(".text;"_"x1: call "_"x1_c; ret");
#وإلا
/* Keep stack aligned */
asm(".text;"_"x1: sub $8,%rsp; call "_"x1_c; add $8,%rsp; ret");
#پایان_اگر

فراغ callx4(فراغ);
فراغ callx5_again(فراغ);

فراغ x6()
{
    چاپ_کن(" x6-1");
}

صحيح اصلی(صحيح argc, حرف *argv[])
{
    چاپ_کن("*");
    asm("call "_"x1");
    asm("call "_"x2");
    asm("call "_"x3");
    callx4();
    asm("call "_"x5");
    callx5_again();
    x6();
    چاپ_کن(" *\n");
    أرجع 0;
}

ساكن
صحيح __USED x2(فراغ)
{
    چاپ_کن(" x2");
    أرجع 2;
}

خارجي صحيح x3(فراغ);

فراغ x4(فراغ)
{
    چاپ_کن(" x4");
}

فراغ x5(فراغ);
فراغ x5(فراغ)
{
    چاپ_کن(" x5");
}
