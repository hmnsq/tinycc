#অন্তর্ভাব <stdio.h>
#অন্তর্ভাব <float.h>

সঙ্ঘ ieee_double_extract
{
    সংরচনা {
        unsigned পূর্ণাঙ্ক manl:32;
        unsigned পূর্ণাঙ্ক manh:20;
        unsigned পূর্ণাঙ্ক exp:11;
        unsigned পূর্ণাঙ্ক sig:1;
    } s;
    দ্বিগুণ d;
};

দ্বিগুণ scale(দ্বিগুণ d)
{
    সঙ্ঘ ieee_double_extract x;

    x.d = d;
    x.d *= 1000;
    প্রত্যাগম x.d;
}

শূন্য mul(দ্বিগুণ *p)
{
    *p *= 2.0;
}

পূর্ণাঙ্ক
main(শূন্য)
{
    দ্বিগুণ d = 4.0;
    printf("%g\n", scale(42));
    mul(&d);
    printf("%g\n", d);
    প্রত্যাগম 0;
}
