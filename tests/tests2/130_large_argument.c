#include<stdio.h>

struct large1 {
    целое a[768];
};

struct large2 {
    целое a[1920];
};

void pass_large_struct1(struct large1 in)
{
    printf("%d %d\n", in.a[200], in.a[767]);
    вернуть;
}

void pass_large_struct2(struct large2 in)
{
    printf("%d %d %d\n", in.a[200], in.a[1023], in.a[1919]);
    вернуть;
}

void pass_many_args(целое a, целое b, целое c, целое d, целое e, целое f, целое g, целое h, целое i,
                    целое j, целое k, целое l, целое m)
{
    printf("%d %d %d %d %d %d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h, i,
           j, k, l, m);
    вернуть;
}

struct large1 l1 = { .a = { [200] = 1, [767] = 2 } };
struct large2 l2 = { .a = { [200] = 3, [1023] = 4, [1919] = 5} };

целое основной(void)
{
    pass_large_struct1(l1);
    pass_large_struct2(l2);
    pass_many_args(13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1);

    вернуть 0;
}
