പൂർണ്ണസംഖ്യ printf(സ്ഥിരം അക്ഷരം*, ...);

പൂർണ്ണസംഖ്യ പ്രധാന()
{
    അക്ഷരം a;
    short b;

    printf("sizeof a : %d %d\n", വലുപ്പം(അക്ഷരം), വലുപ്പം(a));
    printf("sizeof b : %d %d\n", വലുപ്പം(short), വലുപ്പം(b));

    പൂർണ്ണസംഖ്യ ii[] = {}; /* gnu extension, size = 0 */
    printf("sizeof ii : %d\n", വലുപ്പം ii);

    പൂർണ്ണസംഖ്യ kk[] = { 1 };
    printf("sizeof kk : %d\n", വലുപ്പം kk);

    അക്ഷരം cc[] = "12";
    printf("sizeof cc : %d\n", വലുപ്പം cc);

    __WCHAR_TYPE__ ll[] = L"12345";
    printf("len-of ll : %d\n", വലുപ്പം ll / വലുപ്പം ll[0]);

    സ്ഥിതം ഘടന {
        പൂർണ്ണസംഖ്യ a,b,c;
        പൂർണ്ണസംഖ്യ d[];
    } ss[] = {{ 1, 2, 3, {} }};
    printf("sizeof ss : %d\n", വലുപ്പം ss);

    തിരികെ 0;
}
