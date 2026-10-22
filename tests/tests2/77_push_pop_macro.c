#अन्तर्भाव <stdio.h>

पूर्णाङ्क main()
{
    /* must not affect how #pragma ppop_macro works */
    #define निष्कासय_macro foobar1

    /* must not affect how #pragma push_macro works */
    #define प्रक्षिप_macro foobar2

    #undef abort
    #define abort "111"
    printf("abort = %s\n", abort);

    #pragma प्रक्षिप_macro("abort")
    #undef abort
    #define abort "222"
    printf("abort = %s\n", abort);

    #pragma प्रक्षिप_macro("abort")
    #undef abort
    #define abort "333"
    printf("abort = %s\n", abort);

    #pragma निष्कासय_macro("abort")
    printf("abort = %s\n", abort);

    #pragma निष्कासय_macro("abort")
    printf("abort = %s\n", abort);
}
