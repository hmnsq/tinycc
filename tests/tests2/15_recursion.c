#include <stdio.h>

පූර්ණ_සංඛ්‍යා factorial(පූර්ණ_සංඛ්‍යා i) 
{
   නම් (i < 2)
      ආපසු i;
   නැතහොත්
      ආපසු i * factorial(i - 1);
}

පූර්ණ_සංඛ්‍යා main()
{
   පූර්ණ_සංඛ්‍යා Count;

   සඳහා (Count = 1; Count <= 10; Count++)
      printf("%d\n", factorial(Count));

   ආපසු 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
