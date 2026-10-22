целое printf(const char *s, ...);

float fx(x)
float x;
{
    вернуть 2.0 * x;
}

void func(float a);

void func3(struct p { целое a; целое b; } *q) {
}

void func4(q)
 struct p { целое a; целое b; целое c; } *q;
{
}

struct p { целое a; целое b; целое c; целое d; };

целое
основной(void)
{
    float fy();

    printf("%g %g\n", fx(2.0), fy(10.0));
    printf("%g %g\n", fx(2.0f), fy(10.0f));
    func(1);
}

float fy(x)
float x;
{
    вернуть 3.0 * x;
}

void func(a)
float a;
{
    printf("%g\n", a);
}
