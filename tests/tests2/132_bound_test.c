#ଅନ୍ତର୍ଭାଵ <stdio.h>
#ଅନ୍ତର୍ଭାଵ <float.h>

ସଂଘ ieee_double_extract
{
    ସଂରଚନା {
        unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା manl:32;
        unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା manh:20;
        unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା exp:11;
        unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା sig:1;
    } s;
    ଦ୍ୱିଗୁଣ d;
};

ଦ୍ୱିଗୁଣ scale(ଦ୍ୱିଗୁଣ d)
{
    ସଂଘ ieee_double_extract x;

    x.d = d;
    x.d *= 1000;
    ଫେରନ୍ତୁ x.d;
}

ଶୂନ୍ୟ mul(ଦ୍ୱିଗୁଣ *p)
{
    *p *= 2.0;
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା
ମୁଖ୍ୟ(ଶୂନ୍ୟ)
{
    ଦ୍ୱିଗୁଣ d = 4.0;
    printf("%g\n", scale(42));
    mul(&d);
    printf("%g\n", d);
    ଫେରନ୍ତୁ 0;
}
