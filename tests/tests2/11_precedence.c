//#include <stdio.h>
extern පූර්ණ_සංඛ්‍යා printf(const var_na *, ...);

පූර්ණ_සංඛ්‍යා main()
{
   පූර්ණ_සංඛ්‍යා a;
   පූර්ණ_සංඛ්‍යා b;
   පූර්ණ_සංඛ්‍යා c;
   පූර්ණ_සංඛ්‍යා d;
   පූර්ණ_සංඛ්‍යා e;
   පූර්ණ_සංඛ්‍යා f;
   පූර්ණ_සංඛ්‍යා x;
   පූර්ණ_සංඛ්‍යා y;

   a = 12;
   b = 34;
   c = 56;
   d = 78;
   e = 0;
   f = 1;

   printf("%d\n", c + d);
   printf("%d\n", (y = c + d));
   printf("%d\n", e || e && f);
   printf("%d\n", e || f && f);
   printf("%d\n", e && e || f);
   printf("%d\n", e && f || f);
   printf("%d\n", a && f | f);
   printf("%d\n", a | b ^ c & d);
   printf("%d, %d\n", a == a, a == b);
   printf("%d, %d\n", a != a, a != b);
   printf("%d\n", a != b && c != d);
   printf("%d\n", a + b * c / f);
   printf("%d\n", a + b * c / f);
   printf("%d\n", (4 << 4));
   printf("%d\n", (64 >> 4));

   ආපසු 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
