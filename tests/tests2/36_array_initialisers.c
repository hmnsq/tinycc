#include <stdio.h>

extern ကိန်းပြည့် Array3[10];
ကိန်းပြည့် Array3[] = { 12, 34, };
ကိန်းပြည့် main()
{
   ကိန်းပြည့် Count;

   ကိန်းပြည့် Array[10] = { 12, 34, 56, 78, 90, 123, 456, 789, 8642, 9753 };

   အတွက် (Count = 0; Count < 10; Count++)
      printf("%d: %d\n", Count, Array[Count]);

   ကိန်းပြည့် Array2[10] = { 12, 34, 56, 78, 90, 123, 456, 789, 8642, 9753, };

   အတွက် (Count = 0; Count < 10; Count++)
      printf("%d: %d\n", Count, Array2[Count]);

   အတွက် (Count = 0; Count < 10; Count++)
      printf("%d: %d\n", Count, Array3[Count]);

   ပြန်ပေး 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
