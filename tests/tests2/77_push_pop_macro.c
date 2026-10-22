#ଅନ୍ତର୍ଭାଵ <stdio.h>

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ()
{
    /* must not affect how #pragma ppop_macro works */
    #define କାଢ଼_macro foobar1

    /* must not affect how #pragma push_macro works */
    #define ଠେଲ_macro foobar2

    #undef abort
    #define abort "111"
    printf("abort = %s\n", abort);

    #pragma ଠେଲ_macro("abort")
    #undef abort
    #define abort "222"
    printf("abort = %s\n", abort);

    #pragma ଠେଲ_macro("abort")
    #undef abort
    #define abort "333"
    printf("abort = %s\n", abort);

    #pragma କାଢ଼_macro("abort")
    printf("abort = %s\n", abort);

    #pragma କାଢ଼_macro("abort")
    printf("abort = %s\n", abort);
}
