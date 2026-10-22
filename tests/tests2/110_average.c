#अन्तर्भाव <stdio.h>

प्रकारनिर्देश संरचना
{
    द्विगुण average;
    पूर्णाङ्क गन्ती_2;
}
stats_type;

स्थिर शून्य
testc (stats_type *s, दीर्घ दीर्घ data)
{
    s->average = (s->average * s->गन्ती_2 + data) / (s->गन्ती_2 + 1);
    s->गन्ती_2++;
}

पूर्णाङ्क main (शून्य)
{
    stats_type s;

    s.average = 0;
    s.गन्ती_2 = 0;
    testc (&s, 10);
    testc (&s, 20);
    म_लिखो ("%g %d\n", s.average, s.गन्ती_2);
    फर्काऊ 0;
}
