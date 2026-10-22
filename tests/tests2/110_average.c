#অন্তর্ভাৱ <stdio.h>

প্রকারনির্দেশ সংরচনা
{
    দ্ৱিগুণ average;
    পূর্ণাঙ্ক গুনতি_2;
}
stats_type;

স্থির শূন্য
testc (stats_type *s, long long data)
{
    s->average = (s->average * s->গুনতি_2 + data) / (s->গুনতি_2 + 1);
    s->গুনতি_2++;
}

পূর্ণাঙ্ক main (শূন্য)
{
    stats_type s;

    s.average = 0;
    s.গুনতি_2 = 0;
    testc (&s, 10);
    testc (&s, 20);
    printf ("%g %d\n", s.average, s.গুনতি_2);
    ঘূৰাই 0;
}
