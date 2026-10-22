முழு printf(மாறிலி எழுத்து*, ...);

முழு முதன்மை()
{
    எழுத்து a;
    short b;

    printf("sizeof a : %d %d\n", அளவு(எழுத்து), அளவு(a));
    printf("sizeof b : %d %d\n", அளவு(short), அளவு(b));

    முழு ii[] = {}; /* gnu extension, size = 0 */
    printf("sizeof ii : %d\n", அளவு ii);

    முழு kk[] = { 1 };
    printf("sizeof kk : %d\n", அளவு kk);

    எழுத்து cc[] = "12";
    printf("sizeof cc : %d\n", அளவு cc);

    __WCHAR_TYPE__ ll[] = L"12345";
    printf("len-of ll : %d\n", அளவு ll / அளவு ll[0]);

    நிலையான கட்டமைப்பு {
        முழு a,b,c;
        முழு d[];
    } ss[] = {{ 1, 2, 3, {} }};
    printf("sizeof ss : %d\n", அளவு ss);

    திரும்பு 0;
}
