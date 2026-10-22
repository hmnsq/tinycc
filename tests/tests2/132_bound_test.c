#include <stdio.h>
#include <float.h>

sa_ngha ieee_double_extract
{
    sa_nracanaa {
        unsigned จำนวนเต็ม manl:32;
        unsigned จำนวนเต็ม manh:20;
        unsigned จำนวนเต็ม exp:11;
        unsigned จำนวนเต็ม sig:1;
    } s;
    dviguu_na d;
};

dviguu_na scale(dviguu_na d)
{
    sa_ngha ieee_double_extract x;

    x.d = d;
    x.d *= 1000;
    คืน x.d;
}

void mul(dviguu_na *p)
{
    *p *= 2.0;
}

จำนวนเต็ม
หลัก(void)
{
    dviguu_na d = 4.0;
    printf("%g\n", scale(42));
    mul(&d);
    printf("%g\n", d);
    คืน 0;
}
