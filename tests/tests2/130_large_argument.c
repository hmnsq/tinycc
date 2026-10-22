#include<stdio.h>

sa_nracanaa large1 {
    ຈຳນວນເຕັມ a[768];
};

sa_nracanaa large2 {
    ຈຳນວນເຕັມ a[1920];
};

void pass_large_struct1(sa_nracanaa large1 in)
{
    printf("%d %d\n", in.a[200], in.a[767]);
    ສົ່ງຄືນ;
}

void pass_large_struct2(sa_nracanaa large2 in)
{
    printf("%d %d %d\n", in.a[200], in.a[1023], in.a[1919]);
    ສົ່ງຄືນ;
}

void pass_many_args(ຈຳນວນເຕັມ a, ຈຳນວນເຕັມ b, ຈຳນວນເຕັມ c, ຈຳນວນເຕັມ d, ຈຳນວນເຕັມ e, ຈຳນວນເຕັມ f, ຈຳນວນເຕັມ g, ຈຳນວນເຕັມ h, ຈຳນວນເຕັມ i,
                    ຈຳນວນເຕັມ j, ຈຳນວນເຕັມ k, ຈຳນວນເຕັມ l, ຈຳນວນເຕັມ m)
{
    printf("%d %d %d %d %d %d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h, i,
           j, k, l, m);
    ສົ່ງຄືນ;
}

sa_nracanaa large1 l1 = { .a = { [200] = 1, [767] = 2 } };
sa_nracanaa large2 l2 = { .a = { [200] = 3, [1023] = 4, [1919] = 5} };

ຈຳນວນເຕັມ main(void)
{
    pass_large_struct1(l1);
    pass_large_struct2(l2);
    pass_many_args(13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1);

    ສົ່ງຄືນ 0;
}
