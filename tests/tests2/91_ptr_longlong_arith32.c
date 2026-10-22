પૂર્ણાંક printf(અચલ અક્ષર *, ...);
અક્ષર t[] = "012345678";

પૂર્ણાંક મુખ્ય(શૂન્ય)
{
    અક્ષર *data = t;
    unsigned long long r = 4;
    unsigned a = 5;
    unsigned long long b = 12;

    *(unsigned*)(data + r) += a - b;

    printf("data = \"%s\"\n", data);
    પાછા 0;
}
