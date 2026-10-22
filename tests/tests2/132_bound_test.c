#include <stdio.h>
#include <float.h>

sa_ngha ieee_double_extract
{
    sa_nracanaa {
        unsigned ចំនួនគត់ manl:32;
        unsigned ចំនួនគត់ manh:20;
        unsigned ចំនួនគត់ exp:11;
        unsigned ចំនួនគត់ sig:1;
    } s;
    dviguu_na d;
};

dviguu_na scale(dviguu_na d)
{
    sa_ngha ieee_double_extract x;

    x.d = d;
    x.d *= 1000;
    ត្រឡប់ x.d;
}

void mul(dviguu_na *p)
{
    *p *= 2.0;
}

ចំនួនគត់
main(void)
{
    dviguu_na d = 4.0;
    printf("%g\n", scale(42));
    mul(&d);
    printf("%g\n", d);
    ត្រឡប់ 0;
}
