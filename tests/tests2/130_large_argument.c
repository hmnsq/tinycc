#include<stdio.h>

struct large1 {
    정수 a[768];
};

struct large2 {
    정수 a[1920];
};

void pass_large_struct1(struct large1 in)
{
    printf("%d %d\n", in.a[200], in.a[767]);
    반환;
}

void pass_large_struct2(struct large2 in)
{
    printf("%d %d %d\n", in.a[200], in.a[1023], in.a[1919]);
    반환;
}

void pass_many_args(정수 a, 정수 b, 정수 c, 정수 d, 정수 e, 정수 f, 정수 g, 정수 h, 정수 i,
                    정수 j, 정수 k, 정수 l, 정수 m)
{
    printf("%d %d %d %d %d %d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h, i,
           j, k, l, m);
    반환;
}

struct large1 l1 = { .a = { [200] = 1, [767] = 2 } };
struct large2 l2 = { .a = { [200] = 3, [1023] = 4, [1919] = 5} };

정수 main(void)
{
    pass_large_struct1(l1);
    pass_large_struct2(l2);
    pass_many_args(13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1);

    반환 0;
}
