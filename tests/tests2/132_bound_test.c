#include <stdio.h>
#include <float.h>

sa_ngha ieee_double_extract
{
    sa_nracanaa {
        unsigned ຈຳນວນເຕັມ manl:32;
        unsigned ຈຳນວນເຕັມ manh:20;
        unsigned ຈຳນວນເຕັມ exp:11;
        unsigned ຈຳນວນເຕັມ sig:1;
    } s;
    dviguu_na d;
};

dviguu_na scale(dviguu_na d)
{
    sa_ngha ieee_double_extract x;

    x.d = d;
    x.d *= 1000;
    ສົ່ງຄືນ x.d;
}

void mul(dviguu_na *p)
{
    *p *= 2.0;
}

ຈຳນວນເຕັມ
main(void)
{
    dviguu_na d = 4.0;
    printf("%g\n", scale(42));
    mul(&d);
    printf("%g\n", d);
    ສົ່ງຄືນ 0;
}
