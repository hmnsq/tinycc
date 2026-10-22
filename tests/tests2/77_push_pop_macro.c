#अन्तर्भाव <stdio.h>

पूर्णाङ्क main()
{
    /* must not affect how #pragma ppop_macro works */
    #define निकालो_macro foobar1

    /* must not affect how #pragma push_macro works */
    #define धकेलो_macro foobar2

    #undef abort
    #define abort "111"
    printf("abort = %s\n", abort);

    #pragma धकेलो_macro("abort")
    #undef abort
    #define abort "222"
    printf("abort = %s\n", abort);

    #pragma धकेलो_macro("abort")
    #undef abort
    #define abort "333"
    printf("abort = %s\n", abort);

    #pragma निकालो_macro("abort")
    printf("abort = %s\n", abort);

    #pragma निकालो_macro("abort")
    printf("abort = %s\n", abort);
}
