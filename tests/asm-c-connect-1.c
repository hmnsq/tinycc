#અન્તર્ભાવ <stdio.h>

#જો (defined _WIN32 || defined __APPLE__) && (!defined __TINYC__ || defined __leading_underscore)
# define _ "_"
#નહીંતર
# define _
#endif

#ifdef __clang__
/* clang needs some help tp not throw functions away even at -O0 */
#define __USED __attribute__((__used__))
#નહીંતર
#define __USED
#endif

સ્થિર પૂર્ણાંક __USED x1_c (શૂન્ય)
{
    printf(" x1");
    પાછા 1;
}

#જો __i386__
asm(".text;"_"x1: call "_"x1_c; ret");
#નહીંતર
/* Keep stack aligned */
asm(".text;"_"x1: sub $8,%rsp; call "_"x1_c; add $8,%rsp; ret");
#endif

શૂન્ય callx4(શૂન્ય);
શૂન્ય callx5_again(શૂન્ય);

શૂન્ય x6()
{
    printf(" x6-1");
}

પૂર્ણાંક મુખ્ય(પૂર્ણાંક argc, અક્ષર *argv[])
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
    પાછા 0;
}

સ્થિર
પૂર્ણાંક __USED x2(શૂન્ય)
{
    printf(" x2");
    પાછા 2;
}

બાહ્ય પૂર્ણાંક x3(શૂન્ય);

શૂન્ય x4(શૂન્ય)
{
    printf(" x4");
}

શૂન્ય x5(શૂન્ય);
શૂન્ય x5(શૂન્ય)
{
    printf(" x5");
}
