#include <stdio.h>
#include <float.h>

union ieee_double_extract
{
    struct {
        unsigned ціле manl:32;
        unsigned ціле manh:20;
        unsigned ціле exp:11;
        unsigned ціле sig:1;
    } s;
    double d;
};

double scale(double d)
{
    union ieee_double_extract x;

    x.d = d;
    x.d *= 1000;
    повернути x.d;
}

void mul(double *p)
{
    *p *= 2.0;
}

ціле
main(void)
{
    double d = 4.0;
    printf("%g\n", scale(42));
    mul(&d);
    printf("%g\n", d);
    повернути 0;
}
