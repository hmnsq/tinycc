#অন্তর্ভাৱ <stdio.h>
#অন্তর্ভাৱ <float.h>

সঙ্ঘ ieee_double_extract
{
    সংরচনা {
        unsigned পূর্ণাঙ্ক manl:32;
        unsigned পূর্ণাঙ্ক manh:20;
        unsigned পূর্ণাঙ্ক exp:11;
        unsigned পূর্ণাঙ্ক sig:1;
    } s;
    দ্ৱিগুণ d;
};

দ্ৱিগুণ scale(দ্ৱিগুণ d)
{
    সঙ্ঘ ieee_double_extract x;

    x.d = d;
    x.d *= 1000;
    ঘূৰাই x.d;
}

শূন্য mul(দ্ৱিগুণ *p)
{
    *p *= 2.0;
}

পূর্ণাঙ্ক
main(শূন্য)
{
    দ্ৱিগুণ d = 4.0;
    printf("%g\n", scale(42));
    mul(&d);
    printf("%g\n", d);
    ঘূৰাই 0;
}
