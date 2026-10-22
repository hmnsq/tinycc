পূর্ণসংখ্যা printf(ধ্রুবক অক্ষর*, ...);

পূর্ণসংখ্যা প্রধান()
{
    অক্ষর a;
    short b;

    printf("sizeof a : %d %d\n", আকার(অক্ষর), আকার(a));
    printf("sizeof b : %d %d\n", আকার(short), আকার(b));

    পূর্ণসংখ্যা ii[] = {}; /* gnu extension, size = 0 */
    printf("sizeof ii : %d\n", আকার ii);

    পূর্ণসংখ্যা kk[] = { 1 };
    printf("sizeof kk : %d\n", আকার kk);

    অক্ষর cc[] = "12";
    printf("sizeof cc : %d\n", আকার cc);

    __WCHAR_TYPE__ ll[] = L"12345";
    printf("len-of ll : %d\n", আকার ll / আকার ll[0]);

    স্থির কাঠামো {
        পূর্ণসংখ্যা a,b,c;
        পূর্ণসংখ্যা d[];
    } ss[] = {{ 1, 2, 3, {} }};
    printf("sizeof ss : %d\n", আকার ss);

    ফেরত 0;
}
