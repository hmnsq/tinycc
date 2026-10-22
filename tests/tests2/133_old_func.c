整数 printf(const char *s, ...);

float fx(x)
float x;
{
    戻る 2.0 * x;
}

void func(float a);

void func3(struct p { 整数 a; 整数 b; } *q) {
}

void func4(q)
 struct p { 整数 a; 整数 b; 整数 c; } *q;
{
}

struct p { 整数 a; 整数 b; 整数 c; 整数 d; };

整数
メインページ(void)
{
    float fy();

    printf("%g %g\n", fx(2.0), fy(10.0));
    printf("%g %g\n", fx(2.0f), fy(10.0f));
    func(1);
}

float fy(x)
float x;
{
    戻る 3.0 * x;
}

void func(a)
float a;
{
    printf("%g\n", a);
}
