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

पूर्णाङ्क x3(शून्य)
{
    प्रारूप_लिख(" x3");
    प्रत्यागम 3;
}

/* That callx4 is defined globally (as if ".globl callx4")
   is a TCC extension.  GCC doesn't behave like this.  */
शून्य callx4(शून्य);
#यदि __i386__
__asm__(_"callx4: call "_"x4; ret;"
#अन्यथा
/* Keep stack aligned */
__asm__(_"callx4: sub $8,%rsp; call "_"x4; add $8,%rsp; ret;"
#यदि_अन्तः
#यदि_अपरिभाषितम् __TINYC__
    " .global "_"callx4"
#यदि_अन्तः
);

बाह्य शून्य x5(शून्य);

शून्य callx5_again(शून्य);
शून्य callx5_again(शून्य)
{
    x5();
    asm("call "_"x6");
}

स्थिर शून्य __USED x6()
{
    प्रारूप_लिख(" x6-2");
}
