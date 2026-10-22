#شامل <stdio.h>

اجتماع u {
    unsigned long ul;
    long دوگانه ld;
};

تهی
conv (اجتماع u *p)
{
    p->ul = (unsigned صحیح) p->ld;
}

صحیح اصلی (تهی)
{
    اجتماع u v;
    دوگانه d = 1234567890.0;

    v.ld = 42;
    conv (&v);
    printf ("%lu\n", v.ul);
    printf ("%llu\n", (unsigned long long)d);
    بازگشت 0;
}
