#include <stdio.h>
#include <float.h>

sa_ngha ieee_double_extract
{
    sa_nracanaa {
        unsigned පූර්ණ_සංඛ්‍යා manl:32;
        unsigned පූර්ණ_සංඛ්‍යා manh:20;
        unsigned පූර්ණ_සංඛ්‍යා exp:11;
        unsigned පූර්ණ_සංඛ්‍යා sig:1;
    } s;
    dviguu_na d;
};

dviguu_na scale(dviguu_na d)
{
    sa_ngha ieee_double_extract x;

    x.d = d;
    x.d *= 1000;
    ආපසු x.d;
}

void mul(dviguu_na *p)
{
    *p *= 2.0;
}

පූර්ණ_සංඛ්‍යා
main(void)
{
    dviguu_na d = 4.0;
    printf("%g\n", scale(42));
    mul(&d);
    printf("%g\n", d);
    ආපසු 0;
}
