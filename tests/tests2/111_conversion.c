#अन्तर्भाव <stdio.h>

सङ्घ u {
    unsigned long ul;
    long द्विगुण ld;
};

शून्य
conv (सङ्घ u *p)
{
    p->ul = (unsigned पूर्णाङ्क) p->ld;
}

पूर्णाङ्क main (शून्य)
{
    सङ्घ u v;
    द्विगुण d = 1234567890.0;

    v.ld = 42;
    conv (&v);
    printf ("%lu\n", v.ul);
    printf ("%llu\n", (unsigned long long)d);
    पटिनिवत्त 0;
}
