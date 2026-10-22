#ضمن <stdio.h>

صحيح main()
{
    /* must not affect how #pragma ppop_macro works */
    #define کلوار_macro foobar1

    /* must not affect how #pragma push_macro works */
    #define تولق_macro foobar2

    #undef abort
    #define abort "111"
    printf("abort = %s\n", abort);

    #pragma تولق_macro("abort")
    #undef abort
    #define abort "222"
    printf("abort = %s\n", abort);

    #pragma تولق_macro("abort")
    #undef abort
    #define abort "333"
    printf("abort = %s\n", abort);

    #pragma کلوار_macro("abort")
    printf("abort = %s\n", abort);

    #pragma کلوار_macro("abort")
    printf("abort = %s\n", abort);
}
