#અન્તર્ભાવ <stdio.h>

પૂર્ણાંક મુખ્ય()
{
    /* must not affect how #pragma ppop_macro works */
    #define કાઢો_macro foobar1

    /* must not affect how #pragma push_macro works */
    #define ધકેલો_macro foobar2

    #undef abort
    #define abort "111"
    printf("abort = %s\n", abort);

    #pragma ધકેલો_macro("abort")
    #undef abort
    #define abort "222"
    printf("abort = %s\n", abort);

    #pragma ધકેલો_macro("abort")
    #undef abort
    #define abort "333"
    printf("abort = %s\n", abort);

    #pragma કાઢો_macro("abort")
    printf("abort = %s\n", abort);

    #pragma કાઢો_macro("abort")
    printf("abort = %s\n", abort);
}
