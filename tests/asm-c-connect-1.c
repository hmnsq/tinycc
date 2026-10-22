#अन्तर्भाव <stdio.h>

#जर (defined _WIN32 || defined __APPLE__) && (!defined __TINYC__ || defined __leading_underscore)
# define _ "_"
#अन्यथा
# define _
#endif

#ifdef __clang__
/* clang needs some help tp not throw functions away even at -O0 */
#define __USED __attribute__((__used__))
#अन्यथा
#define __USED
#endif

स्थिर पूर्णांक __USED x1_c (शून्य)
{
    म_लिखो(" x1");
    परत 1;
}

#जर __i386__
यंत्र(".text;"_"x1: call "_"x1_c; ret");
#अन्यथा
/* Keep stack aligned */
यंत्र(".text;"_"x1: sub $8,%rsp; call "_"x1_c; add $8,%rsp; ret");
#endif

शून्य callx4(शून्य);
शून्य callx5_again(शून्य);

शून्य x6()
{
    म_लिखो(" x6-1");
}

पूर्णांक main(पूर्णांक argc, अक्षर *argv[])
{
    म_लिखो("*");
    यंत्र("call "_"x1");
    यंत्र("call "_"x2");
    यंत्र("call "_"x3");
    callx4();
    यंत्र("call "_"x5");
    callx5_again();
    x6();
    म_लिखो(" *\n");
    परत 0;
}

स्थिर
पूर्णांक __USED x2(शून्य)
{
    म_लिखो(" x2");
    परत 2;
}

बाह्य पूर्णांक x3(शून्य);

शून्य x4(शून्य)
{
    म_लिखो(" x4");
}

शून्य x5(शून्य);
शून्य x5(शून्य)
{
    म_लिखो(" x5");
}
