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

நிலையான முழு __USED x1_c (வெறுமை)
{
    printf(" x1");
    திரும்பு 1;
}

#எனில் __i386__
asm(".text;"_"x1: call "_"x1_c; ret");
#இல்லையெனில்
/* Keep stack aligned */
asm(".text;"_"x1: sub $8,%rsp; call "_"x1_c; add $8,%rsp; ret");
#endif

வெறுமை callx4(வெறுமை);
வெறுமை callx5_again(வெறுமை);

வெறுமை x6()
{
    printf(" x6-1");
}

முழு முதன்மை(முழு argc, எழுத்து *argv[])
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
    திரும்பு 0;
}

நிலையான
முழு __USED x2(வெறுமை)
{
    printf(" x2");
    திரும்பு 2;
}

வெளி முழு x3(வெறுமை);

வெறுமை x4(வெறுமை)
{
    printf(" x4");
}

வெறுமை x5(வெறுமை);
வெறுமை x5(வெறுமை)
{
    printf(" x5");
}
