#شامل <stdio.h>

صحیح اصلی()
{
    /* must not affect how #pragma ppop_macro works */
    #define برداشت_macro foobar1

    /* must not affect how #pragma push_macro works */
    #define افزودن_macro foobar2

    #undef abort
    #define abort "111"
    printf("abort = %s\n", abort);

    #pragma افزودن_macro("abort")
    #undef abort
    #define abort "222"
    printf("abort = %s\n", abort);

    #pragma افزودن_macro("abort")
    #undef abort
    #define abort "333"
    printf("abort = %s\n", abort);

    #pragma برداشت_macro("abort")
    printf("abort = %s\n", abort);

    #pragma برداشت_macro("abort")
    printf("abort = %s\n", abort);
}
