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

صحيح x3(فراغ)
{
    لکھو(" x3");
    أرجع 3;
}

/* That callx4 is defined globally (as if ".globl callx4")
   is a TCC extension.  GCC doesn't behave like this.  */
فراغ callx4(فراغ);
#إذا __i386__
__asm__(_"callx4: call "_"x4; ret;"
#وإلا
/* Keep stack aligned */
__asm__(_"callx4: sub $8,%rsp; call "_"x4; add $8,%rsp; ret;"
#جے_انت
#جے_بنا_تعریف __TINYC__
    " .global "_"callx4"
#جے_انت
);

خارجي فراغ x5(فراغ);

فراغ callx5_again(فراغ);
فراغ callx5_again(فراغ)
{
    x5();
    asm("call "_"x6");
}

ساكن فراغ __USED x6()
{
    لکھو(" x6-2");
}
