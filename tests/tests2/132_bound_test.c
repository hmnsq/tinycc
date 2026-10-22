#ಅನ್ತರ್ಭಾವ <stdio.h>
#ಅನ್ತರ್ಭಾವ <float.h>

ಸಙ್ಘ ieee_double_extract
{
    ಸಂರಚನಾ {
        unsigned ಪೂರ್ಣಾಙ್ಕ manl:32;
        unsigned ಪೂರ್ಣಾಙ್ಕ manh:20;
        unsigned ಪೂರ್ಣಾಙ್ಕ exp:11;
        unsigned ಪೂರ್ಣಾಙ್ಕ sig:1;
    } s;
    ದ್ವಿಗುಣ d;
};

ದ್ವಿಗುಣ scale(ದ್ವಿಗುಣ d)
{
    ಸಙ್ಘ ieee_double_extract x;

    x.d = d;
    x.d *= 1000;
    ಪ್ರತ್ಯಾಗಮ x.d;
}

ಶೂನ್ಯ mul(ದ್ವಿಗುಣ *p)
{
    *p *= 2.0;
}

ಪೂರ್ಣಾಙ್ಕ
main(ಶೂನ್ಯ)
{
    ದ್ವಿಗುಣ d = 4.0;
    printf("%g\n", scale(42));
    mul(&d);
    printf("%g\n", d);
    ಪ್ರತ್ಯಾಗಮ 0;
}
