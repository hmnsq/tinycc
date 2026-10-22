정수 printf(const char *, ...);
char t[] = "012345678";

정수 main(void)
{
    char *data = t;
    unsigned long long r = 4;
    unsigned a = 5;
    unsigned long long b = 12;

    *(unsigned*)(data + r) += a - b;

    printf("data = \"%s\"\n", data);
    반환 0;
}
