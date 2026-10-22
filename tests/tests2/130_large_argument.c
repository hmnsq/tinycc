#include<stdio.h>

sa_nracanaa large1 {
    පූර්ණ_සංඛ්‍යා a[768];
};

sa_nracanaa large2 {
    පූර්ණ_සංඛ්‍යා a[1920];
};

void pass_large_struct1(sa_nracanaa large1 in)
{
    printf("%d %d\n", in.a[200], in.a[767]);
    ආපසු;
}

void pass_large_struct2(sa_nracanaa large2 in)
{
    printf("%d %d %d\n", in.a[200], in.a[1023], in.a[1919]);
    ආපසු;
}

void pass_many_args(පූර්ණ_සංඛ්‍යා a, පූර්ණ_සංඛ්‍යා b, පූර්ණ_සංඛ්‍යා c, පූර්ණ_සංඛ්‍යා d, පූර්ණ_සංඛ්‍යා e, පූර්ණ_සංඛ්‍යා f, පූර්ණ_සංඛ්‍යා g, පූර්ණ_සංඛ්‍යා h, පූර්ණ_සංඛ්‍යා i,
                    පූර්ණ_සංඛ්‍යා j, පූර්ණ_සංඛ්‍යා k, පූර්ණ_සංඛ්‍යා l, පූර්ණ_සංඛ්‍යා m)
{
    printf("%d %d %d %d %d %d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h, i,
           j, k, l, m);
    ආපසු;
}

sa_nracanaa large1 l1 = { .a = { [200] = 1, [767] = 2 } };
sa_nracanaa large2 l2 = { .a = { [200] = 3, [1023] = 4, [1919] = 5} };

පූර්ණ_සංඛ්‍යා main(void)
{
    pass_large_struct1(l1);
    pass_large_struct2(l2);
    pass_many_args(13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1);

    ආපසු 0;
}
