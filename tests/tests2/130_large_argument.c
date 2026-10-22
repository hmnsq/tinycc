#include<stdio.h>

struct large1 {
    số_nguyên a[768];
};

struct large2 {
    số_nguyên a[1920];
};

void pass_large_struct1(struct large1 in)
{
    printf("%d %d\n", in.a[200], in.a[767]);
    trả_về;
}

void pass_large_struct2(struct large2 in)
{
    printf("%d %d %d\n", in.a[200], in.a[1023], in.a[1919]);
    trả_về;
}

void pass_many_args(số_nguyên a, số_nguyên b, số_nguyên c, số_nguyên d, số_nguyên e, số_nguyên f, số_nguyên g, số_nguyên h, số_nguyên i,
                    số_nguyên j, số_nguyên k, số_nguyên l, số_nguyên m)
{
    printf("%d %d %d %d %d %d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h, i,
           j, k, l, m);
    trả_về;
}

struct large1 l1 = { .a = { [200] = 1, [767] = 2 } };
struct large2 l2 = { .a = { [200] = 3, [1023] = 4, [1919] = 5} };

số_nguyên main(void)
{
    pass_large_struct1(l1);
    pass_large_struct2(l2);
    pass_many_args(13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1);

    trả_về 0;
}
