#include <stdio.h>

extern ціле Array3[10];
ціле Array3[] = { 12, 34, };
ціле main()
{
   ціле Count;

   ціле Array[10] = { 12, 34, 56, 78, 90, 123, 456, 789, 8642, 9753 };

   для (Count = 0; Count < 10; Count++)
      printf("%d: %d\n", Count, Array[Count]);

   ціле Array2[10] = { 12, 34, 56, 78, 90, 123, 456, 789, 8642, 9753, };

   для (Count = 0; Count < 10; Count++)
      printf("%d: %d\n", Count, Array2[Count]);

   для (Count = 0; Count < 10; Count++)
      printf("%d: %d\n", Count, Array3[Count]);

   повернути 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
