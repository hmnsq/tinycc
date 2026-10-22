#अन्तर्भाव <stdio.h>

प्रकारनिर्देश संरचना
{
    द्विगुण average;
    पूर्णाङ्क मोजणी_2;
}
stats_type;

स्थिर शून्य
testc (stats_type *s, long long data)
{
    s->average = (s->average * s->मोजणी_2 + data) / (s->मोजणी_2 + 1);
    s->मोजणी_2++;
}

पूर्णाङ्क main (शून्य)
{
    stats_type s;

    s.average = 0;
    s.मोजणी_2 = 0;
    testc (&s, 10);
    testc (&s, 20);
    printf ("%g %d\n", s.average, s.मोजणी_2);
    प्रत्यागम 0;
}
