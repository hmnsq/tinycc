#شامل <stdio.h>
#شامل <float.h>

اجتماع ieee_double_extract
{
    ساختار {
        unsigned صحیح manl:32;
        unsigned صحیح manh:20;
        unsigned صحیح exp:11;
        unsigned صحیح sig:1;
    } s;
    دوگانه d;
};

دوگانه scale(دوگانه d)
{
    اجتماع ieee_double_extract x;

    x.d = d;
    x.d *= 1000;
    بازگشت x.d;
}

تهی mul(دوگانه *p)
{
    *p *= 2.0;
}

صحیح
اصلی(تهی)
{
    دوگانه d = 4.0;
    printf("%g\n", scale(42));
    mul(&d);
    printf("%g\n", d);
    بازگشت 0;
}
