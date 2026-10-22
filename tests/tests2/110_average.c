#شامل <stdio.h>

تعریفنوع ساختار
{
    دوگانه average;
    صحیح شمار_2;
}
stats_type;

ایستا تهی
testc (stats_type *s, long long data)
{
    s->average = (s->average * s->شمار_2 + data) / (s->شمار_2 + 1);
    s->شمار_2++;
}

صحیح اصلی (تهی)
{
    stats_type s;

    s.average = 0;
    s.شمار_2 = 0;
    testc (&s, 10);
    testc (&s, 20);
    printf ("%g %d\n", s.average, s.شمار_2);
    بازگشت 0;
}
