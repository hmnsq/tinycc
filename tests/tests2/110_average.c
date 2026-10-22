#ضمن <stdio.h>

تعريفنوع بنية
{
    مزدوج average;
    صحيح count;
}
stats_type;

ساكن فراغ
testc (stats_type *s, long long data)
{
    s->average = (s->average * s->count + data) / (s->count + 1);
    s->count++;
}

صحيح main (فراغ)
{
    stats_type s;

    s.average = 0;
    s.count = 0;
    testc (&s, 10);
    testc (&s, 20);
    printf ("%g %d\n", s.average, s.count);
    ܦܢܐ 0;
}
