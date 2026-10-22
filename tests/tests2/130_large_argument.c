#include<stdio.h>

sa_nracanaa large1 {
    ကိန်းပြည့် a[768];
};

sa_nracanaa large2 {
    ကိန်းပြည့် a[1920];
};

void pass_large_struct1(sa_nracanaa large1 in)
{
    printf("%d %d\n", in.a[200], in.a[767]);
    ပြန်ပေး;
}

void pass_large_struct2(sa_nracanaa large2 in)
{
    printf("%d %d %d\n", in.a[200], in.a[1023], in.a[1919]);
    ပြန်ပေး;
}

void pass_many_args(ကိန်းပြည့် a, ကိန်းပြည့် b, ကိန်းပြည့် c, ကိန်းပြည့် d, ကိန်းပြည့် e, ကိန်းပြည့် f, ကိန်းပြည့် g, ကိန်းပြည့် h, ကိန်းပြည့် i,
                    ကိန်းပြည့် j, ကိန်းပြည့် k, ကိန်းပြည့် l, ကိန်းပြည့် m)
{
    printf("%d %d %d %d %d %d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h, i,
           j, k, l, m);
    ပြန်ပေး;
}

sa_nracanaa large1 l1 = { .a = { [200] = 1, [767] = 2 } };
sa_nracanaa large2 l2 = { .a = { [200] = 3, [1023] = 4, [1919] = 5} };

ကိန်းပြည့် main(void)
{
    pass_large_struct1(l1);
    pass_large_struct2(l2);
    pass_many_args(13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1);

    ပြန်ပေး 0;
}
