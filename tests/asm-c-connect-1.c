#अन्तर्भाव <stdio.h>

#सचे (defined _WIN32 || defined __APPLE__) && (!defined __TINYC__ || defined __leading_underscore)
# define _ "_"
#अञ्ञथा
# define _
#endif

#ifdef __clang__
/* clang needs some help tp not throw functions away even at -O0 */
#define __USED __attribute__((__used__))
#अञ्ञथा
#define __USED
#endif

स्थिर पूर्णाङ्क __USED x1_c (शून्य)
{
    printf(" x1");
    पटिनिवत्त 1;
}

#सचे __i386__
asm(".text;"_"x1: call "_"x1_c; ret");
#अञ्ञथा
/* Keep stack aligned */
asm(".text;"_"x1: sub $8,%rsp; call "_"x1_c; add $8,%rsp; ret");
#endif

शून्य callx4(शून्य);
शून्य callx5_again(शून्य);

शून्य x6()
{
    printf(" x6-1");
}

पूर्णाङ्क main(पूर्णाङ्क argc, वर्ण *argv[])
{
    printf("*");
    asm("call "_"x1");
    asm("call "_"x2");
    asm("call "_"x3");
    callx4();
    asm("call "_"x5");
    callx5_again();
    x6();
    printf(" *\n");
    पटिनिवत्त 0;
}

स्थिर
पूर्णाङ्क __USED x2(शून्य)
{
    printf(" x2");
    पटिनिवत्त 2;
}

बाह्य पूर्णाङ्क x3(शून्य);

शून्य x4(शून्य)
{
    printf(" x4");
}

शून्य x5(शून्य);
शून्य x5(शून्य)
{
    printf(" x5");
}
