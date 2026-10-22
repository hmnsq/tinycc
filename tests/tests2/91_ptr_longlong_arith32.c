ཧྲིལ printf(const var_na *, ...);
var_na t[] = "012345678";

ཧྲིལ གཙོ(void)
{
    var_na *data = t;
    unsigned long long r = 4;
    unsigned a = 5;
    unsigned long long b = 12;

    *(unsigned*)(data + r) += a - b;

    printf("data = \"%s\"\n", data);
    ཕྱིར 0;
}
