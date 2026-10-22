#include <stdio.h>
#include <float.h>

union ieee_double_extract
{
    struct {
        unsigned 整数 manl:32;
        unsigned 整数 manh:20;
        unsigned 整数 exp:11;
        unsigned 整数 sig:1;
    } s;
    double d;
};

double scale(double d)
{
    union ieee_double_extract x;

    x.d = d;
    x.d *= 1000;
    返回 x.d;
}

void mul(double *p)
{
    *p *= 2.0;
}

整数
主要(void)
{
    double d = 4.0;
    printf("%g\n", scale(42));
    mul(&d);
    printf("%g\n", d);
    返回 0;
}
