#include <stdio.h>
#include <float.h>

union ieee_double_extract
{
    struct {
        unsigned целое manl:32;
        unsigned целое manh:20;
        unsigned целое exp:11;
        unsigned целое sig:1;
    } s;
    double d;
};

double scale(double d)
{
    union ieee_double_extract x;

    x.d = d;
    x.d *= 1000;
    вернуть x.d;
}

void mul(double *p)
{
    *p *= 2.0;
}

целое
основной(void)
{
    double d = 4.0;
    printf("%g\n", scale(42));
    mul(&d);
    printf("%g\n", d);
    вернуть 0;
}
