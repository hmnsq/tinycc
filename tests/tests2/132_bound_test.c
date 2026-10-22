#ضمن <stdio.h>
#ضمن <float.h>

اتحاد ieee_double_extract
{
    بنية {
        unsigned صحيح manl:32;
        unsigned صحيح manh:20;
        unsigned صحيح exp:11;
        unsigned صحيح sig:1;
    } s;
    مزدوج d;
};

مزدوج scale(مزدوج d)
{
    اتحاد ieee_double_extract x;

    x.d = d;
    x.d *= 1000;
    החזר x.d;
}

فراغ mul(مزدوج *p)
{
    *p *= 2.0;
}

صحيح
main(فراغ)
{
    مزدوج d = 4.0;
    printf("%g\n", scale(42));
    mul(&d);
    printf("%g\n", d);
    החזר 0;
}
