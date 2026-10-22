#ಅನ್ತರ್ಭಾವ <stdio.h>

ಸಙ್ಘ u {
    unsigned long ul;
    long ದ್ವಿಗುಣ ld;
};

ಶೂನ್ಯ
conv (ಸಙ್ಘ u *p)
{
    p->ul = (unsigned ಪೂರ್ಣಾಙ್ಕ) p->ld;
}

ಪೂರ್ಣಾಙ್ಕ main (ಶೂನ್ಯ)
{
    ಸಙ್ಘ u v;
    ದ್ವಿಗುಣ d = 1234567890.0;

    v.ld = 42;
    conv (&v);
    printf ("%lu\n", v.ul);
    printf ("%llu\n", (unsigned long long)d);
    ಪ್ರತ್ಯಾಗಮ 0;
}
