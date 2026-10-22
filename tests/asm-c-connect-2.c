#અન્તર્ભાવ <stdio.h>

#જો (defined _WIN32 || defined __APPLE__) && (!defined __TINYC__ || defined __leading_underscore)
# define _ "_"
#નહીંતર
# define _
#endif

#ifdef __clang__
/* clang needs some help tp not throw functions away even at -O0 */
#define __USED __attribute__((__used__))
#નહીંતર
#define __USED
#endif

પૂર્ણાંક x3(શૂન્ય)
{
    printf(" x3");
    પાછા 3;
}

/* That callx4 is defined globally (as if ".globl callx4")
   is a TCC extension.  GCC doesn't behave like this.  */
શૂન્ય callx4(શૂન્ય);
#જો __i386__
__asm__(_"callx4: call "_"x4; ret;"
#નહીંતર
/* Keep stack aligned */
__asm__(_"callx4: sub $8,%rsp; call "_"x4; add $8,%rsp; ret;"
#endif
#ifndef __TINYC__
    " .global "_"callx4"
#endif
);

બાહ્ય શૂન્ય x5(શૂન્ય);

શૂન્ય callx5_again(શૂન્ય);
શૂન્ય callx5_again(શૂન્ય)
{
    x5();
    asm("call "_"x6");
}

સ્થિર શૂન્ય __USED x6()
{
    printf(" x6-2");
}
