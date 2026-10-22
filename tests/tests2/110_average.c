#અન્તર્ભાવ <stdio.h>

પ્રકારવ્યાખ્યા સંરચના
{
    દ્વિગુણ average;
    પૂર્ણાંક ગણતરી_2;
}
stats_type;

સ્થિર શૂન્ય
testc (stats_type *s, long long data)
{
    s->average = (s->average * s->ગણતરી_2 + data) / (s->ગણતરી_2 + 1);
    s->ગણતરી_2++;
}

પૂર્ણાંક મુખ્ય (શૂન્ય)
{
    stats_type s;

    s.average = 0;
    s.ગણતરી_2 = 0;
    testc (&s, 10);
    testc (&s, 20);
    printf ("%g %d\n", s.average, s.ગણતરી_2);
    પાછા 0;
}
