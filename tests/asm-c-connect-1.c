#ಅನ್ತರ್ಭಾವ <stdio.h>

#ಆದರೆ (defined _WIN32 || defined __APPLE__) && (!defined __TINYC__ || defined __leading_underscore)
# define _ "_"
#ಇಲ್ಲದಿದ್ದರೆ
# define _
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __clang__
/* clang needs some help tp not throw functions away even at -O0 */
#ವ್ಯಾಖ್ಯಾನಿಸು __USED __attribute__((__used__))
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು __USED
#ಆದರೆ_ಅಂತ್ಯ

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ __USED x1_c (ಶೂನ್ಯ)
{
    ಬರೆ(" x1");
    ಹಿಂತಿರುಗಿ 1;
}

#ಆದರೆ __i386__
asm(".text;"_"x1: call "_"x1_c; ret");
#ಇಲ್ಲದಿದ್ದರೆ
/* Keep stack aligned */
asm(".text;"_"x1: sub $8,%rsp; call "_"x1_c; add $8,%rsp; ret");
#ಆದರೆ_ಅಂತ್ಯ

ಶೂನ್ಯ callx4(ಶೂನ್ಯ);
ಶೂನ್ಯ callx5_again(ಶೂನ್ಯ);

ಶೂನ್ಯ x6()
{
    ಬರೆ(" x6-1");
}

ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ(ಪೂರ್ಣಾಂಕ argc, ಅಕ್ಷರ *argv[])
{
    ಬರೆ("*");
    asm("call "_"x1");
    asm("call "_"x2");
    asm("call "_"x3");
    callx4();
    asm("call "_"x5");
    callx5_again();
    x6();
    ಬರೆ(" *\n");
    ಹಿಂತಿರುಗಿ 0;
}

ಸ್ಥಿರ
ಪೂರ್ಣಾಂಕ __USED x2(ಶೂನ್ಯ)
{
    ಬರೆ(" x2");
    ಹಿಂತಿರುಗಿ 2;
}

ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ x3(ಶೂನ್ಯ);

ಶೂನ್ಯ x4(ಶೂನ್ಯ)
{
    ಬರೆ(" x4");
}

ಶೂನ್ಯ x5(ಶೂನ್ಯ);
ಶೂನ್ಯ x5(ಶೂನ್ಯ)
{
    ಬರೆ(" x5");
}
