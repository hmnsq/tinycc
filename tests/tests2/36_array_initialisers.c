#include <stdio.h>

extern số_nguyên Array3[10];
số_nguyên Array3[] = { 12, 34, };
số_nguyên main()
{
   số_nguyên Count;

   số_nguyên Array[10] = { 12, 34, 56, 78, 90, 123, 456, 789, 8642, 9753 };

   cho (Count = 0; Count < 10; Count++)
      printf("%d: %d\n", Count, Array[Count]);

   số_nguyên Array2[10] = { 12, 34, 56, 78, 90, 123, 456, 789, 8642, 9753, };

   cho (Count = 0; Count < 10; Count++)
      printf("%d: %d\n", Count, Array2[Count]);

   cho (Count = 0; Count < 10; Count++)
      printf("%d: %d\n", Count, Array3[Count]);

   trả_về 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
