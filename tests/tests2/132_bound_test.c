#অন্তর্ভাব <stdio.h>
#অন্তর্ভাব <float.h>

সংঘ ieee_double_extract
{
    কাঠামো {
        unsigned পূর্ণসংখ্যা manl:32;
        unsigned পূর্ণসংখ্যা manh:20;
        unsigned পূর্ণসংখ্যা exp:11;
        unsigned পূর্ণসংখ্যা sig:1;
    } s;
    দ্বিগুণ d;
};

দ্বিগুণ scale(দ্বিগুণ d)
{
    সংঘ ieee_double_extract x;

    x.d = d;
    x.d *= 1000;
    ফেরত x.d;
}

শূন্য mul(দ্বিগুণ *p)
{
    *p *= 2.0;
}

পূর্ণসংখ্যা
প্রধান(শূন্য)
{
    দ্বিগুণ d = 4.0;
    printf("%g\n", scale(42));
    mul(&d);
    printf("%g\n", d);
    ফেরত 0;
}
