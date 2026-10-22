#அந்தர்பாவ <stdio.h>

முழு முதன்மை()
{
    /* must not affect how #pragma ppop_macro works */
    #define எடு_macro foobar1

    /* must not affect how #pragma push_macro works */
    #define தள்ளு_macro foobar2

    #undef abort
    #define abort "111"
    printf("abort = %s\n", abort);

    #pragma தள்ளு_macro("abort")
    #undef abort
    #define abort "222"
    printf("abort = %s\n", abort);

    #pragma தள்ளு_macro("abort")
    #undef abort
    #define abort "333"
    printf("abort = %s\n", abort);

    #pragma எடு_macro("abort")
    printf("abort = %s\n", abort);

    #pragma எடு_macro("abort")
    printf("abort = %s\n", abort);
}
