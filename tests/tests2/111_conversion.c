#অন্তর্ভাব <stdio.h>

সংঘ u {
    unsigned long ul;
    long দ্বিগুণ ld;
};

শূন্য
conv (সংঘ u *p)
{
    p->ul = (unsigned পূর্ণসংখ্যা) p->ld;
}

পূর্ণসংখ্যা প্রধান (শূন্য)
{
    সংঘ u v;
    দ্বিগুণ d = 1234567890.0;

    v.ld = 42;
    conv (&v);
    printf ("%lu\n", v.ul);
    printf ("%llu\n", (unsigned long long)d);
    ফেরত 0;
}
