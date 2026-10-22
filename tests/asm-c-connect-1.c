#ಅನ್ತರ್ಭಾವ <stdio.h>

#ಯದಿ (defined _WIN32 || defined __APPLE__) && (!defined __TINYC__ || defined __leading_underscore)
# define _ "_"
#ಅನ್ಯಥಾ
# define _
#endif

#ifdef __clang__
/* clang needs some help tp not throw functions away even at -O0 */
#define __USED __attribute__((__used__))
#ಅನ್ಯಥಾ
#define __USED
#endif

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ __USED x1_c (ಶೂನ್ಯ)
{
    printf(" x1");
    ಪ್ರತ್ಯಾಗಮ 1;
}

#ಯದಿ __i386__
asm(".text;"_"x1: call "_"x1_c; ret");
#ಅನ್ಯಥಾ
/* Keep stack aligned */
asm(".text;"_"x1: sub $8,%rsp; call "_"x1_c; add $8,%rsp; ret");
#endif

ಶೂನ್ಯ callx4(ಶೂನ್ಯ);
ಶೂನ್ಯ callx5_again(ಶೂನ್ಯ);

ಶೂನ್ಯ x6()
{
    printf(" x6-1");
}

ಪೂರ್ಣಾಙ್ಕ main(ಪೂರ್ಣಾಙ್ಕ argc, ವರ್ಣ *argv[])
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
    ಪ್ರತ್ಯಾಗಮ 0;
}

ಸ್ಥಿರ
ಪೂರ್ಣಾಙ್ಕ __USED x2(ಶೂನ್ಯ)
{
    printf(" x2");
    ಪ್ರತ್ಯಾಗಮ 2;
}

ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ x3(ಶೂನ್ಯ);

ಶೂನ್ಯ x4(ಶೂನ್ಯ)
{
    printf(" x4");
}

ಶೂನ್ಯ x5(ಶೂನ್ಯ);
ಶೂನ್ಯ x5(ಶೂನ್ಯ)
{
    printf(" x5");
}
