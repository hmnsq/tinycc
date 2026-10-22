#include <stdio.h>

#ᰀᰧ (defined _WIN32 || defined __APPLE__) && (!defined __TINYC__ || defined __leading_underscore)
# define _ "_"
#ᰀᰧᰀ
# define _
#endif

#ifdef __clang__
/* clang needs some help tp not throw functions away even at -O0 */
#define __USED __attribute__((__used__))
#ᰀᰧᰀ
#define __USED
#endif

puur_naa_nka x3(void)
{
    printf(" x3");
    ᰀᰧᰌ 3;
}

/* That callx4 is defined globally (as if ".globl callx4")
   is a TCC extension.  GCC doesn't behave like this.  */
void callx4(void);
#ᰀᰧ __i386__
__asm__(_"callx4: call "_"x4; ret;"
#ᰀᰧᰀ
/* Keep stack aligned */
__asm__(_"callx4: sub $8,%rsp; call "_"x4; add $8,%rsp; ret;"
#endif
#ifndef __TINYC__
    " .global "_"callx4"
#endif
);

extern void x5(void);

void callx5_again(void);
void callx5_again(void)
{
    x5();
    asm("call "_"x6");
}

static void __USED x6()
{
    printf(" x6-2");
}
