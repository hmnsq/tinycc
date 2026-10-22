#include<stdio.h>

struct large1 {
    整数 a[768];
};

struct large2 {
    整数 a[1920];
};

void pass_large_struct1(struct large1 in)
{
    printf("%d %d\n", in.a[200], in.a[767]);
    戻る;
}

void pass_large_struct2(struct large2 in)
{
    printf("%d %d %d\n", in.a[200], in.a[1023], in.a[1919]);
    戻る;
}

void pass_many_args(整数 a, 整数 b, 整数 c, 整数 d, 整数 e, 整数 f, 整数 g, 整数 h, 整数 i,
                    整数 j, 整数 k, 整数 l, 整数 m)
{
    printf("%d %d %d %d %d %d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h, i,
           j, k, l, m);
    戻る;
}

struct large1 l1 = { .a = { [200] = 1, [767] = 2 } };
struct large2 l2 = { .a = { [200] = 3, [1023] = 4, [1919] = 5} };

整数 メインページ(void)
{
    pass_large_struct1(l1);
    pass_large_struct2(l2);
    pass_many_args(13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1);

    戻る 0;
}
