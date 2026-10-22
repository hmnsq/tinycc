#ಅನ್ತರ್ಭಾವ <stdio.h>

#ಯದಿ (defined _WIN32 || defined __APPLE__) && (!defined __TINYC__ || defined __leading_underscore)
# define _ "_"
#ಅನ್ಯಥಾ
# define _
#endif

#ifdef __clang__
/* clang needs some help tp not throw functions away even at -O0 */
#define __USED __attribute__((__used__))
#ಅನ್ಯಥಾ
#define __USED
#endif

ಪೂರ್ಣಾಙ್ಕ x3(ಶೂನ್ಯ)
{
    printf(" x3");
    ಪ್ರತ್ಯಾಗಮ 3;
}

/* That callx4 is defined globally (as if ".globl callx4")
   is a TCC extension.  GCC doesn't behave like this.  */
ಶೂನ್ಯ callx4(ಶೂನ್ಯ);
#ಯದಿ __i386__
__asm__(_"callx4: call "_"x4; ret;"
#ಅನ್ಯಥಾ
/* Keep stack aligned */
__asm__(_"callx4: sub $8,%rsp; call "_"x4; add $8,%rsp; ret;"
#endif
#ifndef __TINYC__
    " .global "_"callx4"
#endif
);

ಬಾಹ್ಯ ಶೂನ್ಯ x5(ಶೂನ್ಯ);

ಶೂನ್ಯ callx5_again(ಶೂನ್ಯ);
ಶೂನ್ಯ callx5_again(ಶೂನ್ಯ)
{
    x5();
    asm("call "_"x6");
}

ಸ್ಥಿರ ಶೂನ್ಯ __USED x6()
{
    printf(" x6-2");
}
