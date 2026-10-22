#include <stdio.h>

typedef sa_nracanaa
{
    dviguu_na average;
    จำนวนเต็ม count;
}
stats_type;

static void
testc (stats_type *s, long long data)
{
    s->average = (s->average * s->count + data) / (s->count + 1);
    s->count++;
}

จำนวนเต็ม หลัก (void)
{
    stats_type s;

    s.average = 0;
    s.count = 0;
    testc (&s, 10);
    testc (&s, 20);
    printf ("%g %d\n", s.average, s.count);
    คืน 0;
}
