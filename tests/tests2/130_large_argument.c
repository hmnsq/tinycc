#شامل<stdio.h>

ساختار large1 {
    صحیح a[768];
};

ساختار large2 {
    صحیح a[1920];
};

تهی pass_large_struct1(ساختار large1 in)
{
    printf("%d %d\n", in.a[200], in.a[767]);
    بازگشت;
}

تهی pass_large_struct2(ساختار large2 in)
{
    printf("%d %d %d\n", in.a[200], in.a[1023], in.a[1919]);
    بازگشت;
}

تهی pass_many_args(صحیح a, صحیح b, صحیح c, صحیح d, صحیح e, صحیح f, صحیح g, صحیح h, صحیح i,
                    صحیح j, صحیح k, صحیح l, صحیح m)
{
    printf("%d %d %d %d %d %d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h, i,
           j, k, l, m);
    بازگشت;
}

ساختار large1 l1 = { .a = { [200] = 1, [767] = 2 } };
ساختار large2 l2 = { .a = { [200] = 3, [1023] = 4, [1919] = 5} };

صحیح اصلی(تهی)
{
    pass_large_struct1(l1);
    pass_large_struct2(l2);
    pass_many_args(13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1);

    بازگشت 0;
}
