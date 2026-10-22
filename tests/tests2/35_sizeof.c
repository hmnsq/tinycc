पूर्णाङ्क printf(ध्रुव वर्ण*, ...);

पूर्णाङ्क main()
{
    वर्ण a;
    short b;

    printf("sizeof a : %d %d\n", परिमाण(वर्ण), परिमाण(a));
    printf("sizeof b : %d %d\n", परिमाण(short), परिमाण(b));

    पूर्णाङ्क ii[] = {}; /* gnu extension, size = 0 */
    printf("sizeof ii : %d\n", परिमाण ii);

    पूर्णाङ्क kk[] = { 1 };
    printf("sizeof kk : %d\n", परिमाण kk);

    वर्ण cc[] = "12";
    printf("sizeof cc : %d\n", परिमाण cc);

    __WCHAR_TYPE__ ll[] = L"12345";
    printf("len-of ll : %d\n", परिमाण ll / परिमाण ll[0]);

    स्थिर संरचना {
        पूर्णाङ्क a,b,c;
        पूर्णाङ्क d[];
    } ss[] = {{ 1, 2, 3, {} }};
    printf("sizeof ss : %d\n", परिमाण ss);

    पटिनिवत्त 0;
}
