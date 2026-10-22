#અન્તર્ભાવ <stdio.h>

સંઘ u {
    unsigned long ul;
    long દ્વિગુણ ld;
};

શૂન્ય
conv (સંઘ u *p)
{
    p->ul = (unsigned પૂર્ણાંક) p->ld;
}

પૂર્ણાંક મુખ્ય (શૂન્ય)
{
    સંઘ u v;
    દ્વિગુણ d = 1234567890.0;

    v.ld = 42;
    conv (&v);
    printf ("%lu\n", v.ul);
    printf ("%llu\n", (unsigned long long)d);
    પાછા 0;
}
