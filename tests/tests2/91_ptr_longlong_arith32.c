จำนวนเต็ม printf(const var_na *, ...);
var_na t[] = "012345678";

จำนวนเต็ม หลัก(void)
{
    var_na *data = t;
    unsigned long long r = 4;
    unsigned a = 5;
    unsigned long long b = 12;

    *(unsigned*)(data + r) += a - b;

    printf("data = \"%s\"\n", data);
    คืน 0;
}
