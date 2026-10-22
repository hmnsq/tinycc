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

صحیح x3(تهی)
{
    printf(" x3");
    بازگشت 3;
}

/* That callx4 is defined globally (as if ".globl callx4")
   is a TCC extension.  GCC doesn't behave like this.  */
تهی callx4(تهی);
#اگر __i386__
__asm__(_"callx4: call "_"x4; ret;"
#وگرنه
/* Keep stack aligned */
__asm__(_"callx4: sub $8,%rsp; call "_"x4; add $8,%rsp; ret;"
#endif
#ifndef __TINYC__
    " .global "_"callx4"
#endif
);

بیرونی تهی x5(تهی);

تهی callx5_again(تهی);
تهی callx5_again(تهی)
{
    x5();
    asm("call "_"x6");
}

ایستا تهی __USED x6()
{
    printf(" x6-2");
}
