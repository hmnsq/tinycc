#include<stdio.h>

struct large1 {
    цео a[768];
};

struct large2 {
    цео a[1920];
};

void pass_large_struct1(struct large1 in)
{
    printf("%d %d\n", in.a[200], in.a[767]);
    врати;
}

void pass_large_struct2(struct large2 in)
{
    printf("%d %d %d\n", in.a[200], in.a[1023], in.a[1919]);
    врати;
}

void pass_many_args(цео a, цео b, цео c, цео d, цео e, цео f, цео g, цео h, цео i,
                    цео j, цео k, цео l, цео m)
{
    printf("%d %d %d %d %d %d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h, i,
           j, k, l, m);
    врати;
}

struct large1 l1 = { .a = { [200] = 1, [767] = 2 } };
struct large2 l2 = { .a = { [200] = 3, [1023] = 4, [1919] = 5} };

цео main(void)
{
    pass_large_struct1(l1);
    pass_large_struct2(l2);
    pass_many_args(13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1);

    врати 0;
}
