#ଅନ୍ତର୍ଭାଵ <stdio.h>

#ଯଦି (defined _WIN32 || defined __APPLE__) && (!defined __TINYC__ || defined __leading_underscore)
# define _ "_"
#ଅନ୍ୟଥା
# define _
#endif

#ifdef __clang__
/* clang needs some help tp not throw functions away even at -O0 */
#define __USED __attribute__((__used__))
#ଅନ୍ୟଥା
#define __USED
#endif

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା __USED x1_c (ଶୂନ୍ୟ)
{
    printf(" x1");
    ଫେରନ୍ତୁ 1;
}

#ଯଦି __i386__
asm(".text;"_"x1: call "_"x1_c; ret");
#ଅନ୍ୟଥା
/* Keep stack aligned */
asm(".text;"_"x1: sub $8,%rsp; call "_"x1_c; add $8,%rsp; ret");
#endif

ଶୂନ୍ୟ callx4(ଶୂନ୍ୟ);
ଶୂନ୍ୟ callx5_again(ଶୂନ୍ୟ);

ଶୂନ୍ୟ x6()
{
    printf(" x6-1");
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ(ପୂର୍ଣ୍ଣସଂଖ୍ୟା argc, ଅକ୍ଷର *argv[])
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
    ଫେରନ୍ତୁ 0;
}

ସ୍ଥିର
ପୂର୍ଣ୍ଣସଂଖ୍ୟା __USED x2(ଶୂନ୍ୟ)
{
    printf(" x2");
    ଫେରନ୍ତୁ 2;
}

ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା x3(ଶୂନ୍ୟ);

ଶୂନ୍ୟ x4(ଶୂନ୍ୟ)
{
    printf(" x4");
}

ଶୂନ୍ୟ x5(ଶୂନ୍ୟ);
ଶୂନ୍ୟ x5(ଶୂନ୍ୟ)
{
    printf(" x5");
}
