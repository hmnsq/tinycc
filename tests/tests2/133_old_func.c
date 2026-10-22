정수 printf(const char *s, ...);

float fx(x)
float x;
{
    반환 2.0 * x;
}

void func(float a);

void func3(struct p { 정수 a; 정수 b; } *q) {
}

void func4(q)
 struct p { 정수 a; 정수 b; 정수 c; } *q;
{
}

struct p { 정수 a; 정수 b; 정수 c; 정수 d; };

정수
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
    반환 3.0 * x;
}

void func(a)
float a;
{
    printf("%g\n", a);
}
