#अन्तर्भाव <stdio.h>

प्रकारव्याख्या संरचना
{
    द्विगुण average;
    पूर्णांक मोजणी_2;
}
stats_type;

स्थिर शून्य
testc (stats_type *s, दीर्घ दीर्घ data)
{
    s->average = (s->average * s->मोजणी_2 + data) / (s->मोजणी_2 + 1);
    s->मोजणी_2++;
}

पूर्णांक main (शून्य)
{
    stats_type s;

    s.average = 0;
    s.मोजणी_2 = 0;
    testc (&s, 10);
    testc (&s, 20);
    म_लिखो ("%g %d\n", s.average, s.मोजणी_2);
    परत 0;
}
