#include <stdio.h>

පූර්ණ_සංඛ්‍යා main()
{
   පූර්ණ_සංඛ්‍යා a;
   පූර්ණ_සංඛ්‍යා b;
   පූර්ණ_සංඛ්‍යා *d;
   පූර්ණ_සංඛ්‍යා *e;
   d = &a;
   e = &b;
   a = 12;
   b = 34;
   printf("%d\n", *d);
   printf("%d\n", *e);
   printf("%d\n", d == e);
   printf("%d\n", d != e);
   d = e;
   printf("%d\n", d == e);
   printf("%d\n", d != e);

   ආපසු 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
