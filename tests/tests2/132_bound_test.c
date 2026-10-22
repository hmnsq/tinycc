#include <stdio.h>
#include <float.h>

union ieee_double_extract
{
    struct {
        unsigned цео manl:32;
        unsigned цео manh:20;
        unsigned цео exp:11;
        unsigned цео sig:1;
    } s;
    double d;
};

double scale(double d)
{
    union ieee_double_extract x;

    x.d = d;
    x.d *= 1000;
    врати x.d;
}

void mul(double *p)
{
    *p *= 2.0;
}

цео
main(void)
{
    double d = 4.0;
    printf("%g\n", scale(42));
    mul(&d);
    printf("%g\n", d);
    врати 0;
}
