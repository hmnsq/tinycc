#شامل <stdio.h>

#اگر (defined _WIN32 || defined __APPLE__) && (!defined __TINYC__ || defined __leading_underscore)
# define _ "_"
#وگرنه
# define _
#endif

#ifdef __clang__
/* clang needs some help tp not throw functions away even at -O0 */
#define __USED __attribute__((__used__))
#وگرنه
#define __USED
#endif

ایستا صحیح __USED x1_c (تهی)
{
    printf(" x1");
    بازگشت 1;
}

#اگر __i386__
asm(".text;"_"x1: call "_"x1_c; ret");
#وگرنه
/* Keep stack aligned */
asm(".text;"_"x1: sub $8,%rsp; call "_"x1_c; add $8,%rsp; ret");
#endif

تهی callx4(تهی);
تهی callx5_again(تهی);

تهی x6()
{
    printf(" x6-1");
}

صحیح اصلی(صحیح argc, نویسه *argv[])
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
    بازگشت 0;
}

ایستا
صحیح __USED x2(تهی)
{
    printf(" x2");
    بازگشت 2;
}

بیرونی صحیح x3(تهی);

تهی x4(تهی)
{
    printf(" x4");
}

تهی x5(تهی);
تهی x5(تهی)
{
    printf(" x5");
}
