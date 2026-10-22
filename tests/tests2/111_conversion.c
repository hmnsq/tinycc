#ଅନ୍ତର୍ଭାଵ <stdio.h>

ସଂଘ u {
    unsigned long ul;
    long ଦ୍ୱିଗୁଣ ld;
};

ଶୂନ୍ୟ
conv (ସଂଘ u *p)
{
    p->ul = (unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା) p->ld;
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ (ଶୂନ୍ୟ)
{
    ସଂଘ u v;
    ଦ୍ୱିଗୁଣ d = 1234567890.0;

    v.ld = 42;
    conv (&v);
    printf ("%lu\n", v.ul);
    printf ("%llu\n", (unsigned long long)d);
    ଫେରନ୍ତୁ 0;
}
