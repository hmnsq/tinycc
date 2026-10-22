#ಅನ್ತರ್ಭಾವ <stdio.h>

ಪೂರ್ಣಾಙ್ಕ main()
{
    /* must not affect how #pragma ppop_macro works */
    #define ತೆಗೆ_macro foobar1

    /* must not affect how #pragma push_macro works */
    #define ತಳ್ಳು_macro foobar2

    #undef abort
    #define abort "111"
    printf("abort = %s\n", abort);

    #pragma ತಳ್ಳು_macro("abort")
    #undef abort
    #define abort "222"
    printf("abort = %s\n", abort);

    #pragma ತಳ್ಳು_macro("abort")
    #undef abort
    #define abort "333"
    printf("abort = %s\n", abort);

    #pragma ತೆಗೆ_macro("abort")
    printf("abort = %s\n", abort);

    #pragma ತೆಗೆ_macro("abort")
    printf("abort = %s\n", abort);
}
