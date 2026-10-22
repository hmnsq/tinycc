#समावेश <stdio.h>

पूर्णांक मुख्य()
{
    /* must not affect how #pragma ppop_macro works */
    #घोषणा निकालो_macro foobar1

    /* must not affect how #pragma push_macro works */
    #घोषणा धकेलो_macro foobar2

    #अघोषित पात
    #घोषणा पात "111"
    म_लिखो("abort = %s\n", पात);

    #आशय धकेलो_macro("abort")
    #अघोषित पात
    #घोषणा पात "222"
    म_लिखो("abort = %s\n", पात);

    #आशय धकेलो_macro("abort")
    #अघोषित पात
    #घोषणा पात "333"
    म_लिखो("abort = %s\n", पात);

    #आशय निकालो_macro("abort")
    म_लिखो("abort = %s\n", पात);

    #आशय निकालो_macro("abort")
    म_लिखो("abort = %s\n", पात);
}
