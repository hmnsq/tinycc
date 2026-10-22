#अन्तर्भाव <stdio.h>
#अन्तर्भाव <float.h>

सङ्घ ieee_double_extract
{
    संरचना {
        unsigned पूर्णाङ्क manl:32;
        unsigned पूर्णाङ्क manh:20;
        unsigned पूर्णाङ्क exp:11;
        unsigned पूर्णाङ्क sig:1;
    } s;
    द्विगुण d;
};

द्विगुण scale(द्विगुण d)
{
    सङ्घ ieee_double_extract x;

    x.d = d;
    x.d *= 1000;
    प्रत्यागम x.d;
}

शून्य mul(द्विगुण *p)
{
    *p *= 2.0;
}

पूर्णाङ्क
main(शून्य)
{
    द्विगुण d = 4.0;
    printf("%g\n", scale(42));
    mul(&d);
    printf("%g\n", d);
    प्रत्यागम 0;
}
