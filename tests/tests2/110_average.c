#समावेश <stdio.h>

प्रकार काष्ठा
{
    द्विगुन average;
    पूर्णांक गिनती_2;
}
stats_type;

अटल व्योम
testc (stats_type *s, दीर्घ दीर्घ तथ्य)
{
    s->average = (s->average * s->गिनती_2 + तथ्य) / (s->गिनती_2 + 1);
    s->गिनती_2++;
}

पूर्णांक मुख्य (व्योम)
{
    stats_type s;

    s.average = 0;
    s.गिनती_2 = 0;
    testc (&s, 10);
    testc (&s, 20);
    म_लिखो ("%g %d\n", s.average, s.गिनती_2);
    वापस 0;
}
