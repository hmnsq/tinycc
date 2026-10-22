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

पूर्णांक x3(व्योम)
{
    म_लिखो(" x3");
    वापस 3;
}

/* That callx4 is defined globally (as if ".globl callx4")
   is a TCC extension.  GCC doesn't behave like this.  */
व्योम callx4(व्योम);
#अगर __i386__
__asm__(_"callx4: call "_"x4; ret;"
#अन्यथा
/* Keep stack aligned */
__asm__(_"callx4: sub $8,%rsp; call "_"x4; add $8,%rsp; ret;"
#पूर्ण_अगर
#अगर_अघोषित __TINYC__
    " .global "_"callx4"
#पूर्ण_अगर
);

बाह्य व्योम x5(व्योम);

व्योम callx5_again(व्योम);
व्योम callx5_again(व्योम)
{
    x5();
    यंत्र("call "_"x6");
}

अटल व्योम __USED x6()
{
    म_लिखो(" x6-2");
}
