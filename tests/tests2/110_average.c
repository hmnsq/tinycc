#include <stdio.h>

typedef struct
{
    double average;
    цео count;
}
stats_type;

static void
testc (stats_type *s, long long data)
{
    s->average = (s->average * s->count + data) / (s->count + 1);
    s->count++;
}

цео main (void)
{
    stats_type s;

    s.average = 0;
    s.count = 0;
    testc (&s, 10);
    testc (&s, 20);
    printf ("%g %d\n", s.average, s.count);
    врати 0;
}
