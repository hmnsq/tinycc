صحيح printf(ثابت حرف*, ...);

صحيح main()
{
    حرف a;
    short b;

    printf("sizeof a : %d %d\n", حجم(حرف), حجم(a));
    printf("sizeof b : %d %d\n", حجم(short), حجم(b));

    صحيح ii[] = {}; /* gnu extension, size = 0 */
    printf("sizeof ii : %d\n", حجم ii);

    صحيح kk[] = { 1 };
    printf("sizeof kk : %d\n", حجم kk);

    حرف cc[] = "12";
    printf("sizeof cc : %d\n", حجم cc);

    __WCHAR_TYPE__ ll[] = L"12345";
    printf("len-of ll : %d\n", حجم ll / حجم ll[0]);

    ساكن بنية {
        صحيح a,b,c;
        صحيح d[];
    } ss[] = {{ 1, 2, 3, {} }};
    printf("sizeof ss : %d\n", حجم ss);

    החזר 0;
}
