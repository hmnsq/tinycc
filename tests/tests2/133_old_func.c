цяло printf(const char *s, ...);

float fx(x)
float x;
{
    върни 2.0 * x;
}

void func(float a);

void func3(struct p { цяло a; цяло b; } *q) {
}

void func4(q)
 struct p { цяло a; цяло b; цяло c; } *q;
{
}

struct p { цяло a; цяло b; цяло c; цяло d; };

цяло
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
    върни 3.0 * x;
}

void func(a)
float a;
{
    printf("%g\n", a);
}
