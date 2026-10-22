#ضمن<stdio.h>

بنية large1 {
    صحيح a[768];
};

بنية large2 {
    صحيح a[1920];
};

فراغ pass_large_struct1(بنية large1 in)
{
    printf("%d %d\n", in.a[200], in.a[767]);
    ܦܢܐ;
}

فراغ pass_large_struct2(بنية large2 in)
{
    printf("%d %d %d\n", in.a[200], in.a[1023], in.a[1919]);
    ܦܢܐ;
}

فراغ pass_many_args(صحيح a, صحيح b, صحيح c, صحيح d, صحيح e, صحيح f, صحيح g, صحيح h, صحيح i,
                    صحيح j, صحيح k, صحيح l, صحيح m)
{
    printf("%d %d %d %d %d %d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h, i,
           j, k, l, m);
    ܦܢܐ;
}

بنية large1 l1 = { .a = { [200] = 1, [767] = 2 } };
بنية large2 l2 = { .a = { [200] = 3, [1023] = 4, [1919] = 5} };

صحيح main(فراغ)
{
    pass_large_struct1(l1);
    pass_large_struct2(l2);
    pass_many_args(13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1);

    ܦܢܐ 0;
}
