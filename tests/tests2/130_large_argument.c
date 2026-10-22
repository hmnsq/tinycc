#அந்தர்பாவ<stdio.h>

கட்டமைப்பு large1 {
    முழு a[768];
};

கட்டமைப்பு large2 {
    முழு a[1920];
};

வெறுமை pass_large_struct1(கட்டமைப்பு large1 in)
{
    printf("%d %d\n", in.a[200], in.a[767]);
    திரும்பு;
}

வெறுமை pass_large_struct2(கட்டமைப்பு large2 in)
{
    printf("%d %d %d\n", in.a[200], in.a[1023], in.a[1919]);
    திரும்பு;
}

வெறுமை pass_many_args(முழு a, முழு b, முழு c, முழு d, முழு e, முழு f, முழு g, முழு h, முழு i,
                    முழு j, முழு k, முழு l, முழு m)
{
    printf("%d %d %d %d %d %d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h, i,
           j, k, l, m);
    திரும்பு;
}

கட்டமைப்பு large1 l1 = { .a = { [200] = 1, [767] = 2 } };
கட்டமைப்பு large2 l2 = { .a = { [200] = 3, [1023] = 4, [1919] = 5} };

முழு முதன்மை(வெறுமை)
{
    pass_large_struct1(l1);
    pass_large_struct2(l2);
    pass_many_args(13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1);

    திரும்பு 0;
}
