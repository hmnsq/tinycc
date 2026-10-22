#شامل <stdio.h>

#اگر (defined _WIN32 || defined __APPLE__) && (!defined __TINYC__ || defined __leading_underscore)
# define _ "_"
#ورنہ
# define _
#اگر_ختم

#اگر_تعریف_شدہ __clang__
/* clang needs some help tp not throw functions away even at -O0 */
#تعریف_کرو __USED __attribute__((__used__))
#ورنہ
#تعریف_کرو __USED
#اگر_ختم

صحیح x3(خالی)
{
    لکھو(" x3");
    واپس 3;
}

/* That callx4 is defined globally (as if ".globl callx4")
   is a TCC extension.  GCC doesn't behave like this.  */
خالی callx4(خالی);
#اگر __i386__
__asm__(_"callx4: call "_"x4; ret;"
#ورنہ
/* Keep stack aligned */
__asm__(_"callx4: sub $8,%rsp; call "_"x4; add $8,%rsp; ret;"
#اگر_ختم
#اگر_غیر_تعریف_شدہ __TINYC__
    " .global "_"callx4"
#اگر_ختم
);

خارجی خالی x5(خالی);

خالی callx5_again(خالی);
خالی callx5_again(خالی)
{
    x5();
    asm("call "_"x6");
}

ساکن خالی __USED x6()
{
    لکھو(" x6-2");
}
