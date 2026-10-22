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

ಪೂರ್ಣಾಂಕ x3(ಶೂನ್ಯ)
{
    ಬರೆ(" x3");
    ಹಿಂತಿರುಗಿ 3;
}

/* That callx4 is defined globally (as if ".globl callx4")
   is a TCC extension.  GCC doesn't behave like this.  */
ಶೂನ್ಯ callx4(ಶೂನ್ಯ);
#ಆದರೆ __i386__
__asm__(_"callx4: call "_"x4; ret;"
#ಇಲ್ಲದಿದ್ದರೆ
/* Keep stack aligned */
__asm__(_"callx4: sub $8,%rsp; call "_"x4; add $8,%rsp; ret;"
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __TINYC__
    " .global "_"callx4"
#ಆದರೆ_ಅಂತ್ಯ
);

ಬಾಹ್ಯ ಶೂನ್ಯ x5(ಶೂನ್ಯ);

ಶೂನ್ಯ callx5_again(ಶೂನ್ಯ);
ಶೂನ್ಯ callx5_again(ಶೂನ್ಯ)
{
    x5();
    asm("call "_"x6");
}

ಸ್ಥಿರ ಶೂನ್ಯ __USED x6()
{
    ಬರೆ(" x6-2");
}
