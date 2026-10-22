#অন্তর্ভাৱ <stdio.h>

#যদি (defined _WIN32 || defined __APPLE__) && (!defined __TINYC__ || defined __leading_underscore)
# define _ "_"
#অন্যথা
# define _
#endif

#ifdef __clang__
/* clang needs some help tp not throw functions away even at -O0 */
#define __USED __attribute__((__used__))
#অন্যথা
#define __USED
#endif

স্থির পূর্ণাঙ্ক __USED x1_c (শূন্য)
{
    printf(" x1");
    ঘূৰাই 1;
}

#যদি __i386__
asm(".text;"_"x1: call "_"x1_c; ret");
#অন্যথা
/* Keep stack aligned */
asm(".text;"_"x1: sub $8,%rsp; call "_"x1_c; add $8,%rsp; ret");
#endif

শূন্য callx4(শূন্য);
শূন্য callx5_again(শূন্য);

শূন্য x6()
{
    printf(" x6-1");
}

পূর্ণাঙ্ক main(পূর্ণাঙ্ক argc, ৱর্ণ *argv[])
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
    ঘূৰাই 0;
}

স্থির
পূর্ণাঙ্ক __USED x2(শূন্য)
{
    printf(" x2");
    ঘূৰাই 2;
}

বাহ্য পূর্ণাঙ্ক x3(শূন্য);

শূন্য x4(শূন্য)
{
    printf(" x4");
}

শূন্য x5(শূন্য);
শূন্য x5(শূন্য)
{
    printf(" x5");
}
