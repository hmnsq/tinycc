#include <stdio.h>

extern 整数 Array3[10];
整数 Array3[] = { 12, 34, };
整数 主要()
{
   整数 Count;

   整数 Array[10] = { 12, 34, 56, 78, 90, 123, 456, 789, 8642, 9753 };

   为 (Count = 0; Count < 10; Count++)
      printf("%d: %d\n", Count, Array[Count]);

   整数 Array2[10] = { 12, 34, 56, 78, 90, 123, 456, 789, 8642, 9753, };

   为 (Count = 0; Count < 10; Count++)
      printf("%d: %d\n", Count, Array2[Count]);

   为 (Count = 0; Count < 10; Count++)
      printf("%d: %d\n", Count, Array3[Count]);

   返回 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
