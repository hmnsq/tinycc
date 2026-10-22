#અન્તર્ભાવ <stdio.h>
#અન્તર્ભાવ <float.h>

સંઘ ieee_double_extract
{
    સંરચના {
        unsigned પૂર્ણાંક manl:32;
        unsigned પૂર્ણાંક manh:20;
        unsigned પૂર્ણાંક exp:11;
        unsigned પૂર્ણાંક sig:1;
    } s;
    દ્વિગુણ d;
};

દ્વિગુણ scale(દ્વિગુણ d)
{
    સંઘ ieee_double_extract x;

    x.d = d;
    x.d *= 1000;
    પાછા x.d;
}

શૂન્ય mul(દ્વિગુણ *p)
{
    *p *= 2.0;
}

પૂર્ણાંક
મુખ્ય(શૂન્ય)
{
    દ્વિગુણ d = 4.0;
    printf("%g\n", scale(42));
    mul(&d);
    printf("%g\n", d);
    પાછા 0;
}
