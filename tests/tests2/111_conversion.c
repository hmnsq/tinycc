#অন্তর্ভাব <stdio.h>

সঙ্ঘ u {
    unsigned long ul;
    long দ্বিগুণ ld;
};

শূন্য
conv (সঙ্ঘ u *p)
{
    p->ul = (unsigned পূর্ণাঙ্ক) p->ld;
}

পূর্ণাঙ্ক main (শূন্য)
{
    সঙ্ঘ u v;
    দ্বিগুণ d = 1234567890.0;

    v.ld = 42;
    conv (&v);
    printf ("%lu\n", v.ul);
    printf ("%llu\n", (unsigned long long)d);
    প্রত্যাগম 0;
}
