#include<stdio.h>

sa_nracanaa large1 {
    puur_naa_nka a[768];
};

sa_nracanaa large2 {
    puur_naa_nka a[1920];
};

void pass_large_struct1(sa_nracanaa large1 in)
{
    printf("%d %d\n", in.a[200], in.a[767]);
    ᬯᬮᬶ;
}

void pass_large_struct2(sa_nracanaa large2 in)
{
    printf("%d %d %d\n", in.a[200], in.a[1023], in.a[1919]);
    ᬯᬮᬶ;
}

void pass_many_args(puur_naa_nka a, puur_naa_nka b, puur_naa_nka c, puur_naa_nka d, puur_naa_nka e, puur_naa_nka f, puur_naa_nka g, puur_naa_nka h, puur_naa_nka i,
                    puur_naa_nka j, puur_naa_nka k, puur_naa_nka l, puur_naa_nka m)
{
    printf("%d %d %d %d %d %d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h, i,
           j, k, l, m);
    ᬯᬮᬶ;
}

sa_nracanaa large1 l1 = { .a = { [200] = 1, [767] = 2 } };
sa_nracanaa large2 l2 = { .a = { [200] = 3, [1023] = 4, [1919] = 5} };

puur_naa_nka main(void)
{
    pass_large_struct1(l1);
    pass_large_struct2(l2);
    pass_many_args(13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1);

    ᬯᬮᬶ 0;
}
