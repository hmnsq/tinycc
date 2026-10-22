ପୂର୍ଣ୍ଣସଂଖ୍ୟା printf(ଅଚଳ ଅକ୍ଷର*, ...);

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ()
{
    ଅକ୍ଷର a;
    short b;

    printf("sizeof a : %d %d\n", ଆକାର(ଅକ୍ଷର), ଆକାର(a));
    printf("sizeof b : %d %d\n", ଆକାର(short), ଆକାର(b));

    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ii[] = {}; /* gnu extension, size = 0 */
    printf("sizeof ii : %d\n", ଆକାର ii);

    ପୂର୍ଣ୍ଣସଂଖ୍ୟା kk[] = { 1 };
    printf("sizeof kk : %d\n", ଆକାର kk);

    ଅକ୍ଷର cc[] = "12";
    printf("sizeof cc : %d\n", ଆକାର cc);

    __WCHAR_TYPE__ ll[] = L"12345";
    printf("len-of ll : %d\n", ଆକାର ll / ଆକାର ll[0]);

    ସ୍ଥିର ସଂରଚନା {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା a,b,c;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା d[];
    } ss[] = {{ 1, 2, 3, {} }};
    printf("sizeof ss : %d\n", ଆକାର ss);

    ଫେରନ୍ତୁ 0;
}
