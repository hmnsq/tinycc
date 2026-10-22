#include <stdio.h>

typedef struct
{
    double average;
    int बिलांग_2;
}
stats_type;

static void
testc (stats_type *s, long long data)
{
    s->average = (s->average * s->बिलांग_2 + data) / (s->बिलांग_2 + 1);
    s->बिलांग_2++;
}

int main (void)
{
    stats_type s;

    s.average = 0;
    s.बिलांग_2 = 0;
    testc (&s, 10);
    testc (&s, 20);
    printf ("%g %d\n", s.average, s.बिलांग_2);
    return 0;
}
