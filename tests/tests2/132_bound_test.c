#அந்தர்பாவ <stdio.h>
#அந்தர்பாவ <float.h>

ஒன்றிப்பு ieee_double_extract
{
    கட்டமைப்பு {
        unsigned முழு manl:32;
        unsigned முழு manh:20;
        unsigned முழு exp:11;
        unsigned முழு sig:1;
    } s;
    இரட்டை d;
};

இரட்டை scale(இரட்டை d)
{
    ஒன்றிப்பு ieee_double_extract x;

    x.d = d;
    x.d *= 1000;
    திரும்பு x.d;
}

வெறுமை mul(இரட்டை *p)
{
    *p *= 2.0;
}

முழு
முதன்மை(வெறுமை)
{
    இரட்டை d = 4.0;
    printf("%g\n", scale(42));
    mul(&d);
    printf("%g\n", d);
    திரும்பு 0;
}
