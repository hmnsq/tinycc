પૂર્ણાંક printf(અચલ અક્ષર*, ...);

પૂર્ણાંક મુખ્ય()
{
    અક્ષર a;
    short b;

    printf("sizeof a : %d %d\n", કદ(અક્ષર), કદ(a));
    printf("sizeof b : %d %d\n", કદ(short), કદ(b));

    પૂર્ણાંક ii[] = {}; /* gnu extension, size = 0 */
    printf("sizeof ii : %d\n", કદ ii);

    પૂર્ણાંક kk[] = { 1 };
    printf("sizeof kk : %d\n", કદ kk);

    અક્ષર cc[] = "12";
    printf("sizeof cc : %d\n", કદ cc);

    __WCHAR_TYPE__ ll[] = L"12345";
    printf("len-of ll : %d\n", કદ ll / કદ ll[0]);

    સ્થિર સંરચના {
        પૂર્ણાંક a,b,c;
        પૂર્ણાંક d[];
    } ss[] = {{ 1, 2, 3, {} }};
    printf("sizeof ss : %d\n", કદ ss);

    પાછા 0;
}
