ಪೂರ್ಣಾಙ್ಕ printf(ಧ್ರುವ ವರ್ಣ*, ...);

ಪೂರ್ಣಾಙ್ಕ main()
{
    ವರ್ಣ a;
    short b;

    printf("sizeof a : %d %d\n", ಪರಿಮಾಣ(ವರ್ಣ), ಪರಿಮಾಣ(a));
    printf("sizeof b : %d %d\n", ಪರಿಮಾಣ(short), ಪರಿಮಾಣ(b));

    ಪೂರ್ಣಾಙ್ಕ ii[] = {}; /* gnu extension, size = 0 */
    printf("sizeof ii : %d\n", ಪರಿಮಾಣ ii);

    ಪೂರ್ಣಾಙ್ಕ kk[] = { 1 };
    printf("sizeof kk : %d\n", ಪರಿಮಾಣ kk);

    ವರ್ಣ cc[] = "12";
    printf("sizeof cc : %d\n", ಪರಿಮಾಣ cc);

    __WCHAR_TYPE__ ll[] = L"12345";
    printf("len-of ll : %d\n", ಪರಿಮಾಣ ll / ಪರಿಮಾಣ ll[0]);

    ಸ್ಥಿರ ಸಂರಚನಾ {
        ಪೂರ್ಣಾಙ್ಕ a,b,c;
        ಪೂರ್ಣಾಙ್ಕ d[];
    } ss[] = {{ 1, 2, 3, {} }};
    printf("sizeof ss : %d\n", ಪರಿಮಾಣ ss);

    ಪ್ರತ್ಯಾಗಮ 0;
}
