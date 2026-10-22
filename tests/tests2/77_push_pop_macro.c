#অন্তর্ভাৱ <stdio.h>

পূর্ণাঙ্ক main()
{
    /* must not affect how #pragma ppop_macro works */
    #define বেৰ_কৰো_macro foobar1

    /* must not affect how #pragma push_macro works */
    #define ঠেলো_macro foobar2

    #undef abort
    #define abort "111"
    printf("abort = %s\n", abort);

    #pragma ঠেলো_macro("abort")
    #undef abort
    #define abort "222"
    printf("abort = %s\n", abort);

    #pragma ঠেলো_macro("abort")
    #undef abort
    #define abort "333"
    printf("abort = %s\n", abort);

    #pragma বেৰ_কৰো_macro("abort")
    printf("abort = %s\n", abort);

    #pragma বেৰ_কৰো_macro("abort")
    printf("abort = %s\n", abort);
}
