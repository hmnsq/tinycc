#अन्तर्भाव <stdio.h>

प्रकारनिर्देश संरचना
{
    द्विगुण average;
    पूर्णाङ्क गणनम्_2;
}
stats_type;

स्थिर शून्य
testc (stats_type *s, long long data)
{
    s->average = (s->average * s->गणनम्_2 + data) / (s->गणनम्_2 + 1);
    s->गणनम्_2++;
}

पूर्णाङ्क main (शून्य)
{
    stats_type s;

    s.average = 0;
    s.गणनम्_2 = 0;
    testc (&s, 10);
    testc (&s, 20);
    printf ("%g %d\n", s.average, s.गणनम्_2);
    पटिनिवत्त 0;
}
