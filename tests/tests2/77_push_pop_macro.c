#अन्तर्भाव <stdio.h>

पूर्णाङ्क main()
{
    /* must not affect how #pragma ppop_macro works */
    #define निकालो_macro foobar1

    /* must not affect how #pragma push_macro works */
    #define धकेलो_macro foobar2

    #undef पात
    #define पात "111"
    म_लिखो("abort = %s\n", पात);

    #pragma धकेलो_macro("abort")
    #undef पात
    #define पात "222"
    म_लिखो("abort = %s\n", पात);

    #pragma धकेलो_macro("abort")
    #undef पात
    #define पात "333"
    म_लिखो("abort = %s\n", पात);

    #pragma निकालो_macro("abort")
    म_लिखो("abort = %s\n", पात);

    #pragma निकालो_macro("abort")
    म_लिखो("abort = %s\n", पात);
}
