পূর্ণাঙ্ক printf(ধ্রুব বর্ণ*, ...);

পূর্ণাঙ্ক main()
{
    বর্ণ a;
    short b;

    printf("sizeof a : %d %d\n", পরিমাণ(বর্ণ), পরিমাণ(a));
    printf("sizeof b : %d %d\n", পরিমাণ(short), পরিমাণ(b));

    পূর্ণাঙ্ক ii[] = {}; /* gnu extension, size = 0 */
    printf("sizeof ii : %d\n", পরিমাণ ii);

    পূর্ণাঙ্ক kk[] = { 1 };
    printf("sizeof kk : %d\n", পরিমাণ kk);

    বর্ণ cc[] = "12";
    printf("sizeof cc : %d\n", পরিমাণ cc);

    __WCHAR_TYPE__ ll[] = L"12345";
    printf("len-of ll : %d\n", পরিমাণ ll / পরিমাণ ll[0]);

    স্থির সংরচনা {
        পূর্ণাঙ্ক a,b,c;
        পূর্ণাঙ্ক d[];
    } ss[] = {{ 1, 2, 3, {} }};
    printf("sizeof ss : %d\n", পরিমাণ ss);

    প্রত্যাগম 0;
}
