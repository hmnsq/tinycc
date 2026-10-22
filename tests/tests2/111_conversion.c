#include <stdio.h>

union u {
    unsigned long ul;
    long double ld;
};

void
conv (union u *p)
{
    p->ul = (unsigned 整数) p->ld;
}

整数 メインページ (void)
{
    union u v;
    double d = 1234567890.0;

    v.ld = 42;
    conv (&v);
    printf ("%lu\n", v.ul);
    printf ("%llu\n", (unsigned long long)d);
    戻る 0;
}
