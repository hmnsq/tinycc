puur_naa_nka printf(const var_na*, ...);

puur_naa_nka main()
{
    var_na a;
    short b;

    printf("sizeof a : %d %d\n", parimaa_na(var_na), parimaa_na(a));
    printf("sizeof b : %d %d\n", parimaa_na(short), parimaa_na(b));

    puur_naa_nka ii[] = {}; /* gnu extension, size = 0 */
    printf("sizeof ii : %d\n", parimaa_na ii);

    puur_naa_nka kk[] = { 1 };
    printf("sizeof kk : %d\n", parimaa_na kk);

    var_na cc[] = "12";
    printf("sizeof cc : %d\n", parimaa_na cc);

    __WCHAR_TYPE__ ll[] = L"12345";
    printf("len-of ll : %d\n", parimaa_na ll / parimaa_na ll[0]);

    static sa_nracanaa {
        puur_naa_nka a,b,c;
        puur_naa_nka d[];
    } ss[] = {{ 1, 2, 3, {} }};
    printf("sizeof ss : %d\n", parimaa_na ss);

    ᨀᨘᨒ 0;
}
