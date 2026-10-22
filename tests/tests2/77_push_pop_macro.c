#अन्तर्भाव <stdio.h>

पूर्णांक main()
{
    /* must not affect how #pragma ppop_macro works */
    #define काढा_macro foobar1

    /* must not affect how #pragma push_macro works */
    #define ढकला_macro foobar2

    #undef पात
    #define पात "111"
    म_लिखो("abort = %s\n", पात);

    #pragma ढकला_macro("abort")
    #undef पात
    #define पात "222"
    म_लिखो("abort = %s\n", पात);

    #pragma ढकला_macro("abort")
    #undef पात
    #define पात "333"
    म_लिखो("abort = %s\n", पात);

    #pragma काढा_macro("abort")
    म_लिखो("abort = %s\n", पात);

    #pragma काढा_macro("abort")
    म_लिखो("abort = %s\n", पात);
}
