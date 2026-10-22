#அந்தர்பாவ <stdio.h>

வகைவரை கட்டமைப்பு
{
    இரட்டை average;
    முழு மொத்தம்_2;
}
stats_type;

நிலையான வெறுமை
testc (stats_type *s, long long data)
{
    s->average = (s->average * s->மொத்தம்_2 + data) / (s->மொத்தம்_2 + 1);
    s->மொத்தம்_2++;
}

முழு முதன்மை (வெறுமை)
{
    stats_type s;

    s.average = 0;
    s.மொத்தம்_2 = 0;
    testc (&s, 10);
    testc (&s, 20);
    printf ("%g %d\n", s.average, s.மொத்தம்_2);
    திரும்பு 0;
}
