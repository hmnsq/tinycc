#include <stdio.h>

පූර්ණ_සංඛ්‍යා main()
{
   පූර්ණ_සංඛ්‍යා a;
   පූර්ණ_සංඛ්‍යා p;
   පූර්ණ_සංඛ්‍යා t;

   a = 1;
   p = 0;
   t = 0;

   do
   {
      printf("%d\n", a);
      t = a;
      a = t + p;
      p = t;
   } අතරතුර (a < 100);

   ආපසු 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
