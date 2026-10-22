#அந்தர்பாவ <stdio.h>

ஒன்றிப்பு u {
    unsigned long ul;
    long இரட்டை ld;
};

வெறுமை
conv (ஒன்றிப்பு u *p)
{
    p->ul = (unsigned முழு) p->ld;
}

முழு முதன்மை (வெறுமை)
{
    ஒன்றிப்பு u v;
    இரட்டை d = 1234567890.0;

    v.ld = 42;
    conv (&v);
    printf ("%lu\n", v.ul);
    printf ("%llu\n", (unsigned long long)d);
    திரும்பு 0;
}
