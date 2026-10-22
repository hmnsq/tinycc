#അന്തര്ഭാവ <stdio.h>

സംഘം u {
    unsigned long ul;
    long ഇരട്ട ld;
};

ശൂന്യം
conv (സംഘം u *p)
{
    p->ul = (unsigned പൂർണ്ണസംഖ്യ) p->ld;
}

പൂർണ്ണസംഖ്യ പ്രധാന (ശൂന്യം)
{
    സംഘം u v;
    ഇരട്ട d = 1234567890.0;

    v.ld = 42;
    conv (&v);
    printf ("%lu\n", v.ul);
    printf ("%llu\n", (unsigned long long)d);
    തിരികെ 0;
}
