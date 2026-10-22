#include <stdio.h>

පූර්ණ_සංඛ්‍යා main() 
{
   පූර්ණ_සංඛ්‍යා Count;
   පූර්ණ_සංඛ්‍යා Array[10];

   සඳහා (Count = 1; Count <= 10; Count++)
   {
      Array[Count-1] = Count * Count;
   }

   සඳහා (Count = 0; Count < 10; Count++)
   {
      printf("%d\n", Array[Count]);
   }

   ආපසු 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
