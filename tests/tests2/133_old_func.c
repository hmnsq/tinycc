ціле printf(const char *s, ...);

float fx(x)
float x;
{
    повернути 2.0 * x;
}

void func(float a);

void func3(struct p { ціле a; ціле b; } *q) {
}

void func4(q)
 struct p { ціле a; ціле b; ціле c; } *q;
{
}

struct p { ціле a; ціле b; ціле c; ціле d; };

ціле
main(void)
{
    float fy();

    printf("%g %g\n", fx(2.0), fy(10.0));
    printf("%g %g\n", fx(2.0f), fy(10.0f));
    func(1);
}

float fy(x)
float x;
{
    повернути 3.0 * x;
}

void func(a)
float a;
{
    printf("%g\n", a);
}
