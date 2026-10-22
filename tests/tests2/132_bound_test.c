#include <stdio.h>
#include <float.h>

union ieee_double_extract
{
    struct {
        unsigned цяло manl:32;
        unsigned цяло manh:20;
        unsigned цяло exp:11;
        unsigned цяло sig:1;
    } s;
    double d;
};

double scale(double d)
{
    union ieee_double_extract x;

    x.d = d;
    x.d *= 1000;
    върни x.d;
}

void mul(double *p)
{
    *p *= 2.0;
}

цяло
main(void)
{
    double d = 4.0;
    printf("%g\n", scale(42));
    mul(&d);
    printf("%g\n", d);
    върни 0;
}
