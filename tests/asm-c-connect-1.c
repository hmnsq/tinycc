#ضمن <stdio.h>

#إذا (defined _WIN32 || defined __APPLE__) && (!defined __TINYC__ || defined __leading_underscore)
# define _ "_"
#وإلا
# define _
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل __clang__
/* clang needs some help tp not throw functions away even at -O0 */
#وصف_ڪريو __USED __attribute__((__used__))
#وإلا
#وصف_ڪريو __USED
#جيڪڏهن_پورو

ساكن صحيح __USED x1_c (فراغ)
{
    لکو(" x1");
    أرجع 1;
}

#إذا __i386__
asm(".text;"_"x1: call "_"x1_c; ret");
#وإلا
/* Keep stack aligned */
asm(".text;"_"x1: sub $8,%rsp; call "_"x1_c; add $8,%rsp; ret");
#جيڪڏهن_پورو

فراغ callx4(فراغ);
فراغ callx5_again(فراغ);

فراغ x6()
{
    لکو(" x6-1");
}

صحيح مکيه(صحيح argc, حرف *argv[])
{
    لکو("*");
    asm("call "_"x1");
    asm("call "_"x2");
    asm("call "_"x3");
    callx4();
    asm("call "_"x5");
    callx5_again();
    x6();
    لکو(" *\n");
    أرجع 0;
}

ساكن
صحيح __USED x2(فراغ)
{
    لکو(" x2");
    أرجع 2;
}

خارجي صحيح x3(فراغ);

فراغ x4(فراغ)
{
    لکو(" x4");
}

فراغ x5(فراغ);
فراغ x5(فراغ)
{
    لکو(" x5");
}
