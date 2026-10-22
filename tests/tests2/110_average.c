#ಅನ್ತರ್ಭಾವ <stdio.h>

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ
{
    ದ್ವಿಗುಣ average;
    ಪೂರ್ಣಾಙ್ಕ ಎಣಿಕೆ_2;
}
stats_type;

ಸ್ಥಿರ ಶೂನ್ಯ
testc (stats_type *s, long long data)
{
    s->average = (s->average * s->ಎಣಿಕೆ_2 + data) / (s->ಎಣಿಕೆ_2 + 1);
    s->ಎಣಿಕೆ_2++;
}

ಪೂರ್ಣಾಙ್ಕ main (ಶೂನ್ಯ)
{
    stats_type s;

    s.average = 0;
    s.ಎಣಿಕೆ_2 = 0;
    testc (&s, 10);
    testc (&s, 20);
    printf ("%g %d\n", s.average, s.ಎಣಿಕೆ_2);
    ಪ್ರತ್ಯಾಗಮ 0;
}
