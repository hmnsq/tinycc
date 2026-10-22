صحیح printf(ثابت نویسه*, ...);

صحیح اصلی()
{
    نویسه a;
    short b;

    printf("sizeof a : %d %d\n", اندازه(نویسه), اندازه(a));
    printf("sizeof b : %d %d\n", اندازه(short), اندازه(b));

    صحیح ii[] = {}; /* gnu extension, size = 0 */
    printf("sizeof ii : %d\n", اندازه ii);

    صحیح kk[] = { 1 };
    printf("sizeof kk : %d\n", اندازه kk);

    نویسه cc[] = "12";
    printf("sizeof cc : %d\n", اندازه cc);

    __WCHAR_TYPE__ ll[] = L"12345";
    printf("len-of ll : %d\n", اندازه ll / اندازه ll[0]);

    ایستا ساختار {
        صحیح a,b,c;
        صحیح d[];
    } ss[] = {{ 1, 2, 3, {} }};
    printf("sizeof ss : %d\n", اندازه ss);

    بازگشت 0;
}
