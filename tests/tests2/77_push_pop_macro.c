#ضمن <stdio.h>

صحيح main()
{
    /* must not affect how #pragma ppop_macro works */
    #define نکالو_macro foobar1

    /* must not affect how #pragma push_macro works */
    #define ڈالو_macro foobar2

    #undef abort
    #define abort "111"
    printf("abort = %s\n", abort);

    #pragma ڈالو_macro("abort")
    #undef abort
    #define abort "222"
    printf("abort = %s\n", abort);

    #pragma ڈالو_macro("abort")
    #undef abort
    #define abort "333"
    printf("abort = %s\n", abort);

    #pragma نکالو_macro("abort")
    printf("abort = %s\n", abort);

    #pragma نکالو_macro("abort")
    printf("abort = %s\n", abort);
}
