#include <stdio.h>
#include <float.h>

sa_ngha ieee_double_extract
{
    sa_nracanaa {
        unsigned ကိန်းပြည့် manl:32;
        unsigned ကိန်းပြည့် manh:20;
        unsigned ကိန်းပြည့် exp:11;
        unsigned ကိန်းပြည့် sig:1;
    } s;
    dviguu_na d;
};

dviguu_na scale(dviguu_na d)
{
    sa_ngha ieee_double_extract x;

    x.d = d;
    x.d *= 1000;
    ပြန်ပေး x.d;
}

void mul(dviguu_na *p)
{
    *p *= 2.0;
}

ကိန်းပြည့်
main(void)
{
    dviguu_na d = 4.0;
    printf("%g\n", scale(42));
    mul(&d);
    printf("%g\n", d);
    ပြန်ပေး 0;
}
