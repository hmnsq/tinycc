#अन्तर्भाव <stdio.h>

#यदि (defined _WIN32 || defined __APPLE__) && (!defined __TINYC__ || defined __leading_underscore)
# define _ "_"
#अन्यथा
# define _
#यदि_अन्तः

#यदि_परिभाषितम् __clang__
/* clang needs some help tp not throw functions away even at -O0 */
#परिभाषय __USED __attribute__((__used__))
#अन्यथा
#परिभाषय __USED
#यदि_अन्तः

स्थिर पूर्णाङ्क __USED x1_c (शून्य)
{
    प्रारूप_लिख(" x1");
    प्रत्यागम 1;
}

#यदि __i386__
asm(".text;"_"x1: call "_"x1_c; ret");
#अन्यथा
/* Keep stack aligned */
asm(".text;"_"x1: sub $8,%rsp; call "_"x1_c; add $8,%rsp; ret");
#यदि_अन्तः

शून्य callx4(शून्य);
शून्य callx5_again(शून्य);

शून्य x6()
{
    प्रारूप_लिख(" x6-1");
}

पूर्णाङ्क मुख्यम्(पूर्णाङ्क argc, वर्ण *argv[])
{
    प्रारूप_लिख("*");
    asm("call "_"x1");
    asm("call "_"x2");
    asm("call "_"x3");
    callx4();
    asm("call "_"x5");
    callx5_again();
    x6();
    प्रारूप_लिख(" *\n");
    प्रत्यागम 0;
}

स्थिर
पूर्णाङ्क __USED x2(शून्य)
{
    प्रारूप_लिख(" x2");
    प्रत्यागम 2;
}

बाह्य पूर्णाङ्क x3(शून्य);

शून्य x4(शून्य)
{
    प्रारूप_लिख(" x4");
}

शून्य x5(शून्य);
शून्य x5(शून्य)
{
    प्रारूप_लिख(" x5");
}
