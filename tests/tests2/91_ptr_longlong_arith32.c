പൂർണ്ണസംഖ്യ printf(സ്ഥിരം അക്ഷരം *, ...);
അക്ഷരം t[] = "012345678";

പൂർണ്ണസംഖ്യ പ്രധാന(ശൂന്യം)
{
    അക്ഷരം *data = t;
    unsigned long long r = 4;
    unsigned a = 5;
    unsigned long long b = 12;

    *(unsigned*)(data + r) += a - b;

    printf("data = \"%s\"\n", data);
    തിരികെ 0;
}
