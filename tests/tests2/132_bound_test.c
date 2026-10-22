#include <stdio.h>
#include <float.h>

union ieee_double_extract
{
    struct {
        unsigned 정수 manl:32;
        unsigned 정수 manh:20;
        unsigned 정수 exp:11;
        unsigned 정수 sig:1;
    } s;
    double d;
};

double scale(double d)
{
    union ieee_double_extract x;

    x.d = d;
    x.d *= 1000;
    반환 x.d;
}

void mul(double *p)
{
    *p *= 2.0;
}

정수
main(void)
{
    double d = 4.0;
    printf("%g\n", scale(42));
    mul(&d);
    printf("%g\n", d);
    반환 0;
}
