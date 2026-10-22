#समावेश <stdio.h>

#अगर (defined _WIN32 || defined __APPLE__) && (!defined __TINYC__ || defined __leading_underscore)
# define _ "_"
#अन्यथा
# define _
#पूर्ण_अगर

#अगर_घोषित __clang__
/* clang needs some help tp not throw functions away even at -O0 */
#घोषणा __USED __attribute__((__used__))
#अन्यथा
#घोषणा __USED
#पूर्ण_अगर

अटल पूर्णांक __USED x1_c (व्योम)
{
    म_लिखो(" x1");
    वापस 1;
}

#अगर __i386__
यंत्र(".text;"_"x1: call "_"x1_c; ret");
#अन्यथा
/* Keep stack aligned */
यंत्र(".text;"_"x1: sub $8,%rsp; call "_"x1_c; add $8,%rsp; ret");
#पूर्ण_अगर

व्योम callx4(व्योम);
व्योम callx5_again(व्योम);

व्योम x6()
{
    म_लिखो(" x6-1");
}

पूर्णांक मुख्य(पूर्णांक argc, अक्षर *argv[])
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
    वापस 0;
}

अटल
पूर्णांक __USED x2(व्योम)
{
    म_लिखो(" x2");
    वापस 2;
}

बाह्य पूर्णांक x3(व्योम);

व्योम x4(व्योम)
{
    म_लिखो(" x4");
}

व्योम x5(व्योम);
व्योम x5(व्योम)
{
    म_लिखो(" x5");
}
