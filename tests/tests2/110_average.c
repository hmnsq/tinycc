#അന്തര്ഭാവ <stdio.h>

തരനിർവചനം ഘടന
{
    ഇരട്ട average;
    പൂർണ്ണസംഖ്യ എണ്ണം_2;
}
stats_type;

സ്ഥിതം ശൂന്യം
testc (stats_type *s, long long data)
{
    s->average = (s->average * s->എണ്ണം_2 + data) / (s->എണ്ണം_2 + 1);
    s->എണ്ണം_2++;
}

പൂർണ്ണസംഖ്യ പ്രധാന (ശൂന്യം)
{
    stats_type s;

    s.average = 0;
    s.എണ്ണം_2 = 0;
    testc (&s, 10);
    testc (&s, 20);
    printf ("%g %d\n", s.average, s.എണ്ണം_2);
    തിരികെ 0;
}
