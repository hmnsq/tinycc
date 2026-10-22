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

ساکن صحیح __USED x1_c (خالی)
{
    لکھو(" x1");
    واپس 1;
}

#اگر __i386__
asm(".text;"_"x1: call "_"x1_c; ret");
#ورنہ
/* Keep stack aligned */
asm(".text;"_"x1: sub $8,%rsp; call "_"x1_c; add $8,%rsp; ret");
#اگر_ختم

خالی callx4(خالی);
خالی callx5_again(خالی);

خالی x6()
{
    لکھو(" x6-1");
}

صحیح مین(صحیح argc, حرف *argv[])
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
    واپس 0;
}

ساکن
صحیح __USED x2(خالی)
{
    لکھو(" x2");
    واپس 2;
}

خارجی صحیح x3(خالی);

خالی x4(خالی)
{
    لکھو(" x4");
}

خالی x5(خالی);
خالی x5(خالی)
{
    لکھو(" x5");
}
