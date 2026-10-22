#include <stdio.h>
#include <float.h>

sa_ngha ieee_double_extract
{
    sa_nracanaa {
        unsigned puur_naa_nka manl:32;
        unsigned puur_naa_nka manh:20;
        unsigned puur_naa_nka exp:11;
        unsigned puur_naa_nka sig:1;
    } s;
    dviguu_na d;
};

dviguu_na scale(dviguu_na d)
{
    sa_ngha ieee_double_extract x;

    x.d = d;
    x.d *= 1000;
    ꦮꦭꦶ x.d;
}

void mul(dviguu_na *p)
{
    *p *= 2.0;
}

puur_naa_nka
main(void)
{
    dviguu_na d = 4.0;
    printf("%g\n", scale(42));
    mul(&d);
    printf("%g\n", d);
    ꦮꦭꦶ 0;
}
