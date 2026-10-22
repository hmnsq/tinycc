#অন্তর্ভাৱ <stdio.h>

সঙ্ঘ u {
    unsigned long ul;
    long দ্ৱিগুণ ld;
};

শূন্য
conv (সঙ্ঘ u *p)
{
    p->ul = (unsigned পূর্ণাঙ্ক) p->ld;
}

পূর্ণাঙ্ক main (শূন্য)
{
    সঙ্ঘ u v;
    দ্ৱিগুণ d = 1234567890.0;

    v.ld = 42;
    conv (&v);
    printf ("%lu\n", v.ul);
    printf ("%llu\n", (unsigned long long)d);
    ঘূৰাই 0;
}
