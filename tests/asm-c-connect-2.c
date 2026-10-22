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

صحيح x3(فراغ)
{
    چاپ_کن(" x3");
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
#پایان_اگر
#اگر_تعریف_نشده __TINYC__
    " .global "_"callx4"
#پایان_اگر
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
    چاپ_کن(" x6-2");
}
