#अन्तर्भाव <stdio.h>

पूर्णाङ्क मुख्यम्()
{
    /* must not affect how #pragma ppop_macro works */
    #परिभाषय निष्कासय_macro foobar1

    /* must not affect how #pragma push_macro works */
    #परिभाषय प्रक्षिप_macro foobar2

    #अपरिभाषय abort
    #परिभाषय abort "111"
    प्रारूप_लिख("abort = %s\n", abort);

    #निर्देशः प्रक्षिप_macro("abort")
    #अपरिभाषय abort
    #परिभाषय abort "222"
    प्रारूप_लिख("abort = %s\n", abort);

    #निर्देशः प्रक्षिप_macro("abort")
    #अपरिभाषय abort
    #परिभाषय abort "333"
    प्रारूप_लिख("abort = %s\n", abort);

    #निर्देशः निष्कासय_macro("abort")
    प्रारूप_लिख("abort = %s\n", abort);

    #निर्देशः निष्कासय_macro("abort")
    प्रारूप_लिख("abort = %s\n", abort);
}
