#ضمن <stdio.h>

اتحاد u {
    unsigned long ul;
    long مزدوج ld;
};

فراغ
conv (اتحاد u *p)
{
    p->ul = (unsigned صحيح) p->ld;
}

صحيح main (فراغ)
{
    اتحاد u v;
    مزدوج d = 1234567890.0;

    v.ld = 42;
    conv (&v);
    printf ("%lu\n", v.ul);
    printf ("%llu\n", (unsigned long long)d);
    החזר 0;
}
