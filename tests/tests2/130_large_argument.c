#অন্তর্ভাৱ<stdio.h>

সংরচনা large1 {
    পূর্ণাঙ্ক a[768];
};

সংরচনা large2 {
    পূর্ণাঙ্ক a[1920];
};

শূন্য pass_large_struct1(সংরচনা large1 in)
{
    printf("%d %d\n", in.a[200], in.a[767]);
    ঘূৰাই;
}

শূন্য pass_large_struct2(সংরচনা large2 in)
{
    printf("%d %d %d\n", in.a[200], in.a[1023], in.a[1919]);
    ঘূৰাই;
}

শূন্য pass_many_args(পূর্ণাঙ্ক a, পূর্ণাঙ্ক b, পূর্ণাঙ্ক c, পূর্ণাঙ্ক d, পূর্ণাঙ্ক e, পূর্ণাঙ্ক f, পূর্ণাঙ্ক g, পূর্ণাঙ্ক h, পূর্ণাঙ্ক i,
                    পূর্ণাঙ্ক j, পূর্ণাঙ্ক k, পূর্ণাঙ্ক l, পূর্ণাঙ্ক m)
{
    printf("%d %d %d %d %d %d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h, i,
           j, k, l, m);
    ঘূৰাই;
}

সংরচনা large1 l1 = { .a = { [200] = 1, [767] = 2 } };
সংরচনা large2 l2 = { .a = { [200] = 3, [1023] = 4, [1919] = 5} };

পূর্ণাঙ্ক main(শূন্য)
{
    pass_large_struct1(l1);
    pass_large_struct2(l2);
    pass_many_args(13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1);

    ঘূৰাই 0;
}
