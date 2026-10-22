#include <stdio.h>
#include <float.h>

union ieee_double_extract
{
    struct {
        unsigned số_nguyên manl:32;
        unsigned số_nguyên manh:20;
        unsigned số_nguyên exp:11;
        unsigned số_nguyên sig:1;
    } s;
    double d;
};

double scale(double d)
{
    union ieee_double_extract x;

    x.d = d;
    x.d *= 1000;
    trả_về x.d;
}

void mul(double *p)
{
    *p *= 2.0;
}

số_nguyên
main(void)
{
    double d = 4.0;
    printf("%g\n", scale(42));
    mul(&d);
    printf("%g\n", d);
    trả_về 0;
}
