#ضمن <stdio.h>

تعريفنوع بنية
{
    مزدوج average;
    صحيح تعداد_3;
}
stats_type;

ساكن فراغ
testc (stats_type *s, long long data)
{
    s->average = (s->average * s->تعداد_3 + data) / (s->تعداد_3 + 1);
    s->تعداد_3++;
}

صحيح الرئيسية (فراغ)
{
    stats_type s;

    s.average = 0;
    s.تعداد_3 = 0;
    testc (&s, 10);
    testc (&s, 20);
    printf ("%g %d\n", s.average, s.تعداد_3);
    إرجاع 0;
}
