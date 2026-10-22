#അന്തര്ഭാവ <stdio.h>

പൂർണ്ണസംഖ്യ പ്രധാന()
{
    /* must not affect how #pragma ppop_macro works */
    #define എടുക്കുക_macro foobar1

    /* must not affect how #pragma push_macro works */
    #define തള്ളുക_macro foobar2

    #undef abort
    #define abort "111"
    printf("abort = %s\n", abort);

    #pragma തള്ളുക_macro("abort")
    #undef abort
    #define abort "222"
    printf("abort = %s\n", abort);

    #pragma തള്ളുക_macro("abort")
    #undef abort
    #define abort "333"
    printf("abort = %s\n", abort);

    #pragma എടുക്കുക_macro("abort")
    printf("abort = %s\n", abort);

    #pragma എടുക്കുക_macro("abort")
    printf("abort = %s\n", abort);
}
