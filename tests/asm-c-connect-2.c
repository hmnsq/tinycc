#அந்தர்பாவ <stdio.h>

#எனில் (defined _WIN32 || defined __APPLE__) && (!defined __TINYC__ || defined __leading_underscore)
# define _ "_"
#இல்லையெனில்
# define _
#endif

#ifdef __clang__
/* clang needs some help tp not throw functions away even at -O0 */
#define __USED __attribute__((__used__))
#இல்லையெனில்
#define __USED
#endif

முழு x3(வெறுமை)
{
    printf(" x3");
    திரும்பு 3;
}

/* That callx4 is defined globally (as if ".globl callx4")
   is a TCC extension.  GCC doesn't behave like this.  */
வெறுமை callx4(வெறுமை);
#எனில் __i386__
__asm__(_"callx4: call "_"x4; ret;"
#இல்லையெனில்
/* Keep stack aligned */
__asm__(_"callx4: sub $8,%rsp; call "_"x4; add $8,%rsp; ret;"
#endif
#ifndef __TINYC__
    " .global "_"callx4"
#endif
);

வெளி வெறுமை x5(வெறுமை);

வெறுமை callx5_again(வெறுமை);
வெறுமை callx5_again(வெறுமை)
{
    x5();
    asm("call "_"x6");
}

நிலையான வெறுமை __USED x6()
{
    printf(" x6-2");
}
