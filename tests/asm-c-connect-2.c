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

পূর্ণাঙ্ক x3(শূন্য)
{
    printf(" x3");
    ঘূৰাই 3;
}

/* That callx4 is defined globally (as if ".globl callx4")
   is a TCC extension.  GCC doesn't behave like this.  */
শূন্য callx4(শূন্য);
#যদি __i386__
__asm__(_"callx4: call "_"x4; ret;"
#অন্যথা
/* Keep stack aligned */
__asm__(_"callx4: sub $8,%rsp; call "_"x4; add $8,%rsp; ret;"
#endif
#ifndef __TINYC__
    " .global "_"callx4"
#endif
);

বাহ্য শূন্য x5(শূন্য);

শূন্য callx5_again(শূন্য);
শূন্য callx5_again(শূন্য)
{
    x5();
    asm("call "_"x6");
}

স্থির শূন্য __USED x6()
{
    printf(" x6-2");
}
