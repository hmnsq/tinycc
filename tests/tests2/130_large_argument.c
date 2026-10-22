#અન્તર્ભાવ<stdio.h>

સંરચના large1 {
    પૂર્ણાંક a[768];
};

સંરચના large2 {
    પૂર્ણાંક a[1920];
};

શૂન્ય pass_large_struct1(સંરચના large1 in)
{
    printf("%d %d\n", in.a[200], in.a[767]);
    પાછા;
}

શૂન્ય pass_large_struct2(સંરચના large2 in)
{
    printf("%d %d %d\n", in.a[200], in.a[1023], in.a[1919]);
    પાછા;
}

શૂન્ય pass_many_args(પૂર્ણાંક a, પૂર્ણાંક b, પૂર્ણાંક c, પૂર્ણાંક d, પૂર્ણાંક e, પૂર્ણાંક f, પૂર્ણાંક g, પૂર્ણાંક h, પૂર્ણાંક i,
                    પૂર્ણાંક j, પૂર્ણાંક k, પૂર્ણાંક l, પૂર્ણાંક m)
{
    printf("%d %d %d %d %d %d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h, i,
           j, k, l, m);
    પાછા;
}

સંરચના large1 l1 = { .a = { [200] = 1, [767] = 2 } };
સંરચના large2 l2 = { .a = { [200] = 3, [1023] = 4, [1919] = 5} };

પૂર્ણાંક મુખ્ય(શૂન્ય)
{
    pass_large_struct1(l1);
    pass_large_struct2(l2);
    pass_many_args(13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1);

    પાછા 0;
}
