#അന്തര്ഭാവ <stdio.h>
#അന്തര്ഭാവ <float.h>

സംഘം ieee_double_extract
{
    ഘടന {
        unsigned പൂർണ്ണസംഖ്യ manl:32;
        unsigned പൂർണ്ണസംഖ്യ manh:20;
        unsigned പൂർണ്ണസംഖ്യ exp:11;
        unsigned പൂർണ്ണസംഖ്യ sig:1;
    } s;
    ഇരട്ട d;
};

ഇരട്ട scale(ഇരട്ട d)
{
    സംഘം ieee_double_extract x;

    x.d = d;
    x.d *= 1000;
    തിരികെ x.d;
}

ശൂന്യം mul(ഇരട്ട *p)
{
    *p *= 2.0;
}

പൂർണ്ണസംഖ്യ
പ്രധാന(ശൂന്യം)
{
    ഇരട്ട d = 4.0;
    printf("%g\n", scale(42));
    mul(&d);
    printf("%g\n", d);
    തിരികെ 0;
}
