#include <stdio.h>
#include <float.h>

sa_ngha ieee_double_extract
{
    sa_nracanaa {
        unsigned ཧྲིལ manl:32;
        unsigned ཧྲིལ manh:20;
        unsigned ཧྲིལ exp:11;
        unsigned ཧྲིལ sig:1;
    } s;
    dviguu_na d;
};

dviguu_na scale(dviguu_na d)
{
    sa_ngha ieee_double_extract x;

    x.d = d;
    x.d *= 1000;
    ཕྱིར x.d;
}

void mul(dviguu_na *p)
{
    *p *= 2.0;
}

ཧྲིལ
གཙོ(void)
{
    dviguu_na d = 4.0;
    printf("%g\n", scale(42));
    mul(&d);
    printf("%g\n", d);
    ཕྱིར 0;
}
