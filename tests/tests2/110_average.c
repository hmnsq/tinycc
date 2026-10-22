#ضمن <stdio.h>

تعريفنوع بنية
{
    مزدوج average;
    صحيح عدد_2;
}
stats_type;

ساكن فراغ
testc (stats_type *s, long long data)
{
    s->average = (s->average * s->عدد_2 + data) / (s->عدد_2 + 1);
    s->عدد_2++;
}

صحيح main (فراغ)
{
    stats_type s;

    s.average = 0;
    s.عدد_2 = 0;
    testc (&s, 10);
    testc (&s, 20);
    printf ("%g %d\n", s.average, s.عدد_2);
    أرجع 0;
}
