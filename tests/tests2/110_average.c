#ଅନ୍ତର୍ଭାଵ <stdio.h>

ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା
{
    ଦ୍ୱିଗୁଣ average;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ଗଣନା_3;
}
stats_type;

ସ୍ଥିର ଶୂନ୍ୟ
testc (stats_type *s, long long data)
{
    s->average = (s->average * s->ଗଣନା_3 + data) / (s->ଗଣନା_3 + 1);
    s->ଗଣନା_3++;
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ (ଶୂନ୍ୟ)
{
    stats_type s;

    s.average = 0;
    s.ଗଣନା_3 = 0;
    testc (&s, 10);
    testc (&s, 20);
    printf ("%g %d\n", s.average, s.ଗଣନା_3);
    ଫେରନ୍ତୁ 0;
}
