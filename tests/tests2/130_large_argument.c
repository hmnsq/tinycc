#include<stdio.h>

sa_nracanaa large1 {
    จำนวนเต็ม a[768];
};

sa_nracanaa large2 {
    จำนวนเต็ม a[1920];
};

void pass_large_struct1(sa_nracanaa large1 in)
{
    printf("%d %d\n", in.a[200], in.a[767]);
    คืน;
}

void pass_large_struct2(sa_nracanaa large2 in)
{
    printf("%d %d %d\n", in.a[200], in.a[1023], in.a[1919]);
    คืน;
}

void pass_many_args(จำนวนเต็ม a, จำนวนเต็ม b, จำนวนเต็ม c, จำนวนเต็ม d, จำนวนเต็ม e, จำนวนเต็ม f, จำนวนเต็ม g, จำนวนเต็ม h, จำนวนเต็ม i,
                    จำนวนเต็ม j, จำนวนเต็ม k, จำนวนเต็ม l, จำนวนเต็ม m)
{
    printf("%d %d %d %d %d %d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h, i,
           j, k, l, m);
    คืน;
}

sa_nracanaa large1 l1 = { .a = { [200] = 1, [767] = 2 } };
sa_nracanaa large2 l2 = { .a = { [200] = 3, [1023] = 4, [1919] = 5} };

จำนวนเต็ม หลัก(void)
{
    pass_large_struct1(l1);
    pass_large_struct2(l2);
    pass_many_args(13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1);

    คืน 0;
}
