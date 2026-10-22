#include <stdio.h>

int main()
{
    /* must not affect how #pragma ppop_macro works */
    #define आलिसिन_macro foobar1

    /* must not affect how #pragma push_macro works */
    #define इतुलाक_macro foobar2

    #undef abort
    #define abort "111"
    printf("abort = %s\n", abort);

    #pragma इतुलाक_macro("abort")
    #undef abort
    #define abort "222"
    printf("abort = %s\n", abort);

    #pragma इतुलाक_macro("abort")
    #undef abort
    #define abort "333"
    printf("abort = %s\n", abort);

    #pragma आलिसिन_macro("abort")
    printf("abort = %s\n", abort);

    #pragma आलिसिन_macro("abort")
    printf("abort = %s\n", abort);
}
