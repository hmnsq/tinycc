#include <stdio.h>

extern පූර්ණ_සංඛ්‍යා Array3[10];
පූර්ණ_සංඛ්‍යා Array3[] = { 12, 34, };
පූර්ණ_සංඛ්‍යා main()
{
   පූර්ණ_සංඛ්‍යා Count;

   පූර්ණ_සංඛ්‍යා Array[10] = { 12, 34, 56, 78, 90, 123, 456, 789, 8642, 9753 };

   සඳහා (Count = 0; Count < 10; Count++)
      printf("%d: %d\n", Count, Array[Count]);

   පූර්ණ_සංඛ්‍යා Array2[10] = { 12, 34, 56, 78, 90, 123, 456, 789, 8642, 9753, };

   සඳහා (Count = 0; Count < 10; Count++)
      printf("%d: %d\n", Count, Array2[Count]);

   සඳහා (Count = 0; Count < 10; Count++)
      printf("%d: %d\n", Count, Array3[Count]);

   ආපසු 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
