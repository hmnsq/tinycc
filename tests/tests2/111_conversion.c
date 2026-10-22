#include <stdio.h>

sa_ngha u {
    unsigned long ul;
    long dviguu_na ld;
};

void
conv (sa_ngha u *p)
{
    p->ul = (unsigned ចំនួនគត់) p->ld;
}

ចំនួនគត់ main (void)
{
    sa_ngha u v;
    dviguu_na d = 1234567890.0;

    v.ld = 42;
    conv (&v);
    printf ("%lu\n", v.ul);
    printf ("%llu\n", (unsigned long long)d);
    ត្រឡប់ 0;
}
