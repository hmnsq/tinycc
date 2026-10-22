#अन्तर्भाव <stdio.h>

#यदि (defined _WIN32 || defined __APPLE__) && (!defined __TINYC__ || defined __leading_underscore)
# define _ "_"
#अन्यथा
# define _
#endif

#ifdef __clang__
/* clang needs some help tp not throw functions away even at -O0 */
#define __USED __attribute__((__used__))
#अन्यथा
#define __USED
#endif

पूर्णाङ्क x3(शून्य)
{
    printf(" x3");
    प्रत्यागम 3;
}

/* That callx4 is defined globally (as if ".globl callx4")
   is a TCC extension.  GCC doesn't behave like this.  */
शून्य callx4(शून्य);
#यदि __i386__
__asm__(_"callx4: call "_"x4; ret;"
#अन्यथा
/* Keep stack aligned */
__asm__(_"callx4: sub $8,%rsp; call "_"x4; add $8,%rsp; ret;"
#endif
#ifndef __TINYC__
    " .global "_"callx4"
#endif
);

बाह्य शून्य x5(शून्य);

शून्य callx5_again(शून्य);
शून्य callx5_again(शून्य)
{
    x5();
    asm("call "_"x6");
}

स्थिर शून्य __USED x6()
{
    printf(" x6-2");
}
