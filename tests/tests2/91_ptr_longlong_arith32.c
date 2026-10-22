முழு printf(மாறிலி எழுத்து *, ...);
எழுத்து t[] = "012345678";

முழு முதன்மை(வெறுமை)
{
    எழுத்து *data = t;
    unsigned long long r = 4;
    unsigned a = 5;
    unsigned long long b = 12;

    *(unsigned*)(data + r) += a - b;

    printf("data = \"%s\"\n", data);
    திரும்பு 0;
}
