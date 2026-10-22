صحيح لکو(ثابت حرف*, ...);

صحيح مکيه()
{
    حرف a;
    ننڍو b;

    لکو("sizeof a : %d %d\n", حجم(حرف), حجم(a));
    لکو("sizeof b : %d %d\n", حجم(ننڍو), حجم(b));

    صحيح ii[] = {}; /* gnu extension, size = 0 */
    لکو("sizeof ii : %d\n", حجم ii);

    صحيح kk[] = { 1 };
    لکو("sizeof kk : %d\n", حجم kk);

    حرف cc[] = "12";
    لکو("sizeof cc : %d\n", حجم cc);

    __WCHAR_TYPE__ ll[] = L"12345";
    لکو("len-of ll : %d\n", حجم ll / حجم ll[0]);

    ساكن بنية {
        صحيح a,b,c;
        صحيح d[];
    } ss[] = {{ 1, 2, 3, {} }};
    لکو("sizeof ss : %d\n", حجم ss);

    أرجع 0;
}
