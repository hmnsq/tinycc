số_nguyên printf(const char *s, ...);

float fx(x)
float x;
{
    trả_về 2.0 * x;
}

void func(float a);

void func3(struct p { số_nguyên a; số_nguyên b; } *q) {
}

void func4(q)
 struct p { số_nguyên a; số_nguyên b; số_nguyên c; } *q;
{
}

struct p { số_nguyên a; số_nguyên b; số_nguyên c; số_nguyên d; };

số_nguyên
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
    trả_về 3.0 * x;
}

void func(a)
float a;
{
    printf("%g\n", a);
}
