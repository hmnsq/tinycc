#অন্তর্ভাব <stdio.h>

প্রকারলেখ কাঠামো
{
    দ্বিগুণ average;
    পূর্ণসংখ্যা গুনতি_2;
}
stats_type;

স্থির শূন্য
testc (stats_type *s, long long তথ্য)
{
    s->average = (s->average * s->গুনতি_2 + তথ্য) / (s->গুনতি_2 + 1);
    s->গুনতি_2++;
}

পূর্ণসংখ্যা প্রধান (শূন্য)
{
    stats_type s;

    s.average = 0;
    s.গুনতি_2 = 0;
    testc (&s, 10);
    testc (&s, 20);
    printf ("%g %d\n", s.average, s.গুনতি_2);
    ফেরত 0;
}
