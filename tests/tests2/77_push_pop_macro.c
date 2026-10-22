#ضمن <stdio.h>

صحيح main()
{
    /* must not affect how #pragma ppop_macro works */
    #define چرو_macro foobar1

    /* must not affect how #pragma push_macro works */
    #define تور_macro foobar2

    #undef abort
    #define abort "111"
    printf("abort = %s\n", abort);

    #pragma تور_macro("abort")
    #undef abort
    #define abort "222"
    printf("abort = %s\n", abort);

    #pragma تور_macro("abort")
    #undef abort
    #define abort "333"
    printf("abort = %s\n", abort);

    #pragma چرو_macro("abort")
    printf("abort = %s\n", abort);

    #pragma چرو_macro("abort")
    printf("abort = %s\n", abort);
}
